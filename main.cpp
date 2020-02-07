#include "Matrix.h"
#include "Array.h"
#include "LinearSolve.h"


#include <ios>
#include <lapacke.h>
#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <math.h>   
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//  ELEMENTS MODULE
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//  the module was checked. [Correct]
const int neq    = 1;
const int nbf_1d = 3;  
const int nrhs   = 1;

size_t nxel; 
size_t nnx ;
size_t nodtol; 
size_t nunknowns;

void DISCRETIZATION_DATA()
{
  nxel      = 100; 
  nnx       = (nbf_1d - 1) * nxel + 1;
  nodtol    = nnx;
  nunknowns = neq * nodtol;
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// GLOBAL ARRAYS MODULE 
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

Array  residual; 
Array  solution; 
Matrix jacobian; 

std::vector<bool> bcondition;


void ALLOCATE_GLOBAL_ARRAYS(bool allocate, int _size = 0)
{
  if (allocate){
    residual.resize(_size); 
    solution.resize(_size);
  
    jacobian.resize(_size, _size);

    bcondition.resize(_size);}
  else
  {
    residual.clear();
    solution.clear(); 
    jacobian.clear();
    bcondition.clear();   
  }

}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NEWTON RAPSHON 
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
const int    max_num_iter =  1000;
const double max_error    = 1.e-6;
double iteration;
double res_norm;

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ENUMERATION MODULE 
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
std::vector< std::vector<int> > nm_elem;

void ALLOCATE_ENUMERATION_INDICES(bool allocate, int nxel_, int nbf_1d_)
{

  if (allocate){

    nm_elem.resize(nxel_); 

    for ( std::vector<std::vector<int>>::iterator it = nm_elem.begin(); 
          it != nm_elem.end(); 
          ++it )
    {
      it->resize(nbf_1d_, 0); 
    }
  }
  else {
  
    nm_elem.clear();
  }

  }

int   NNUM_NODES  ( int i) { return i;}		 
void  NNUM_ELEMENT()
{
  for (size_t nelem = 0; nelem < nxel; ++nelem)
  {
    nm_elem[nelem][0] = 2* nelem; 
    nm_elem[nelem][1] = nm_elem[nelem][0] + 1; 
    nm_elem[nelem][2] = nm_elem[nelem][1] + 1;
  } 
 
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// MESH MODULE 
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// This module was checked. [Correct]
double xaxis; 
double xfact;
Array x; 

void ALLOCATE_MESH_ARRAYS(bool allocate, int nodtol_)
{
  if   (allocate) { x.resize(nodtol_); }
  else            { x.clear();         }
}



void INITIALIZE_MESH() { xaxis = 1.0; xfact = 1.0;}

void MESH()
{
  int    node; 
  double fi;
  double fx; 
  for( size_t i = 0; i < nnx; ++i)
  {
    node = NNUM_NODES(i);
    fi   = i; 
    fx   = nxel; 

    x[node] = 0.0; 

    if ( i != 0) {x[node] = xaxis *  (fi)/(2.0 * fx) ; }
  }

}
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//  GAUSS MODULE
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//
// Checked everything is correct
//
const int NGAUSS_1d = 3; 

std::vector<double> GAPT_1d(NGAUSS_1d); 
std::vector<double> WO_1d  (NGAUSS_1d);

std::vector< std::vector<double> > BFN_1d (nbf_1d);
std::vector< std::vector<double> > DFDC_1d(nbf_1d);
std::vector<double>                DFDX_1d(nbf_1d);

void GAUSS_EVALUATION_1d()
{
  GAPT_1d[0] = - sqrt(3.0/5.0);
  GAPT_1d[1] =   0.0;
  GAPT_1d[2] = + sqrt(3.0/5.0);

  WO_1d  [0] = 5.0/9.0;
  WO_1d  [1] = 8.0/9.0;
  WO_1d  [2] = 5.0/9.0;

  for (size_t i = 0; i < NGAUSS_1d; ++i)
  {
    double x = GAPT_1d[i]; 

    BFN_1d[0].push_back( -0.5 * x * (1.0 - x) );
    BFN_1d[1].push_back(  1.0 - x * x         );
    BFN_1d[2].push_back( +0.5 * x * (1.0 + x) );

    DFDC_1d[0].push_back( (2.0*x - 1.0)/2.0 ); 
    DFDC_1d[1].push_back( -2.0*x            );
    DFDC_1d[2].push_back( (2.0*x + 1.0)/2.0 );  

  }


}


void GAUSS_EVALUATION()
{
  GAUSS_EVALUATION_1d();
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// DOMAIN 
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
void domi();

void BASIS( const int&                       _ig, 
            const int&                      _nbf, 
            const std::vector<int>&          _nm, 
                  double&                  _x_gs,
                  double&               _dxdc_gs,
                  double&               _cjac_gs,
                  double&               _ajac_gs,
                  std::vector<double>&  _DFDX_gs )
{
  //     CALCULATE PARTIAL DERIVATIVES OF TRANSFORMATION
  //     AT A POINT C IN NELEM
  _x_gs    = 0.0; 
  _dxdc_gs = 0.0;

  for(int i = 0; i < _nbf; ++i)
  { _x_gs    += BFN_1d [i][_ig] * x(_nm[i] );
    _dxdc_gs += DFDC_1d[i][_ig] * x(_nm[i] ); }
  // CALCULATE JACOBIAN OF THE TRANSFORMATION
  _cjac_gs = _dxdc_gs;
 
  _ajac_gs = abs(_cjac_gs);


  // CALCULATE DERIVATIVES OF BASIS FUNCTIONS WRT X COORDINATES
  for(int i = 0; i < _nbf; ++i)
  { _DFDX_gs[i] = DFDC_1d[i][_ig]/_cjac_gs;}

}

int dotProduct( Array& A , Array& B) 
{ 
  
    int product = 0; 
  
    // Loop for calculate cot product 
    for (int i = 0; i < A.size(); i++) product += A(i) * B(i); 
    return product; 
} 

int main()
{
  // <><><><><><><><><><><><><><><><><><><><>
  // GAUSS EVALUATION FOR 3 GAUSS POINTS
  // <><><><><><><><><><><><><><><><><><><><>
  GAUSS_EVALUATION();

  // <><><><><><><><><><><><><><><><><><><><>
  // SET NUMBER OF ELEMENTS
  // <><><><><><><><><><><><><><><><><><><><>
  DISCRETIZATION_DATA();

  // <><><><><><><><><><><><><><><><><><><><>
  // CALCULATE MESH POINTS
  // <><><><><><><><><><><><><><><><><><><><>

  ALLOCATE_MESH_ARRAYS(true, nodtol);
  INITIALIZE_MESH();
  MESH();

  // <><><><><><><><><><><><><><><><><><><><>
  // ALLOCATE CONNECTIVITY ARRAY
  // <><><><><><><><><><><><><><><><><><><><>

  ALLOCATE_ENUMERATION_INDICES(true, nxel, nbf_1d);
  NNUM_ELEMENT(); 

  // <><><><><><><><><><><><><><><><><><><><>
  // ALLOCATE MEMORY FOR GLOBAL SYSTEM OF EQUATIONS
  // <><><><><><><><><><><><><><><><><><><><>

  ALLOCATE_GLOBAL_ARRAYS(true, nunknowns);

  // <><><><><><><><><><><><><><><><><><><><>
  // <><><><><><><><><><><><><><><><><><><><>

  solution = 1.0;
  iteration=   0;
  res_norm = 1.0;

  Lapack LinearSolve;  
  do {

    iteration += 1; 
    std::cout << "LOOP_NEWTON_RAPSHON: " << iteration << std::endl;


    residual = 0.0; 
    jacobian = 0.0;   

    domi(); 
    residual(0)           = solution(0)           - 1.0; 
    residual(nunknowns-1) = solution(nunknowns-1) - 2.0; 
   
    for(size_t j = 0; j < nunknowns; ++j)
      {
        jacobian(0          ,j) = 0.0;
        jacobian(nunknowns-1,j) = 0.0;  
      }
      jacobian(0,0) = 1.0; 
      jacobian(nunknowns-1  , nunknowns-1) = 1.0;
   
      int nfo = LinearSolve.factorize(jacobian);
      if (nfo==0) LinearSolve.solve(jacobian, residual);

      
      else  { std::cout << "Error: infor is not 0" << std::endl; return 1;}


      for(size_t i = 0; i < nunknowns; ++i) { solution(i) -= residual(i); }

       
      res_norm = sqrt( dotProduct(residual,residual) );

      std::cout.precision(10);
      std::cout << "ITERATION :" << iteration << " " << std::scientific
                << "RESIDUAL  :" << res_norm  << " " << std::defaultfloat    
                << std::endl; 

    if (iteration >= max_num_iter) break; 
  } while (res_norm > max_error); 


for (size_t i = 0; i < solution.size(); ++i)
  {
  
    std::cout << solution(i) << std::endl; 
  }


  std::ofstream myfile; 
  myfile.open( "solution_cpp.dat"); 


for (size_t i = 0; i < solution.size(); ++i)
  {
  
    myfile << std::to_string(x(i)) + "\t" + std::to_string(solution(i)) + "\n";
  }






  return 0;
}


void domi()
{
  double wet = 0.0; 
  double bifn= 0.0;
  double dbix= 0.0; 
  double bjfn= 0.0; 
  double dbjx= 0.0; 
  double T_gs= 0.0; 
  double DTDX_gs = 0.0; 
  double x_gs    = 0.0; 
  double ajac_gs = 0.0; 
  double cjac_gs = 0.0; 
  double dxdc_gs = 0.0;


  std::vector<int>    nm            (nbf_1d);
  std::vector<double> DFDX_gs       (nbf_1d);
  std::vector<double> SOLUTION_elem (nbf_1d); 

  double TERM_RES; 
  double TERM_JAC; 

  Array  TEMP_RES(nbf_1d);
  Matrix TEMP_JAC(nbf_1d,nbf_1d); 


  for (size_t nelem = 0; nelem < nxel; ++nelem)
  {
    //  COPY CONNECTIVITY ARRAY TO A LOCAL ARRAY
    nm[0] = nm_elem[nelem][0];
    nm[1] = nm_elem[nelem][1];
    nm[2] = nm_elem[nelem][2];

    //  COPY SOLUTION VECTOR TO A LOCAL  ARRAY	 

    SOLUTION_elem[0] = solution[ nm[0]  ];
    SOLUTION_elem[1] = solution[ nm[1]  ];
    SOLUTION_elem[2] = solution[ nm[2]  ];

    //  INITIALIZE WORKING (TEMPORARY) AREAS FOR ELEMENT INTEGRATION ***
    //  BEFORE FORMING ELEMENTAL JACOBIAN AND RHS VECTOR
    TEMP_RES = 0.0;
    TEMP_JAC = 0.0;

    //  ITERATE OVER EACH GAUSS POINT IN AN ELEMENT   ***
    for (size_t ig = 0; ig < NGAUSS_1d; ++ig)
    {
      //        _gs  stands for the value of a variable at the gauss point "IG"
      //
      //        ISOPARAMETRIC MAPPING		 
      //        CALCULATE DERIVATIVES OF BASIS FUNCTIONS AND TRANSFORMATION
      //        JACOBIAN AT THE GAUSS POINT "IG" IN X COORDINATE
      //
      //        IT ALSO CALCULATES THE INDEPENDENT VARIABLE X AT THE GAUSS POINT "IG" 
      //
      BASIS( ig, nbf_1d, nm, x_gs , dxdc_gs, cjac_gs, ajac_gs, DFDX_gs ); 

      wet = WO_1d[ig] * abs(cjac_gs); 


      //        CALCULATE DEPENDENT VARIABLE AND PARTIAL DERIVATIVES AT
      //        THE GAUSSIAN INTEGRATION POINTS

      T_gs = 0.0; DTDX_gs = 0.0;
      for ( size_t i = 0; i < nbf_1d ; ++i)
        {
          T_gs    += SOLUTION_elem[i] * BFN_1d[i][ig];
          DTDX_gs += SOLUTION_elem[i] * DFDX_gs[i];
        }

      // ITERATE OVER WEIGHTING FUNCTIONS

      for(int iw = 0; iw < nbf_1d; ++iw)
      {
          bifn = BFN_1d [iw][ig]; 
          dbix = DFDX_gs[iw];

          TERM_RES = - dbix * DTDX_gs - 0.50 * T_gs * bifn; 

          TEMP_RES(iw) += TERM_RES * wet;


        for(int jw = 0; jw < nbf_1d; ++jw)
        {
              bjfn = BFN_1d [jw][ig];
              dbjx = DFDX_gs[jw];
              
              TERM_JAC        = -dbix * dbjx - 0.50 * bjfn * bifn;          
              TEMP_JAC(iw,jw)+= TERM_JAC * wet;

        }
      }
    }


// STORE THE ELEMENT RESIDUAL VECTOR
// IN THE GLOBAL VECTOR B
  for(int i = 0; i < nbf_1d; ++i)
   { int ii = nm[i]; residual(ii) += TEMP_RES[i]; }

  for(int i = 0; i < nbf_1d; ++i)
    { 
      int ii = nm[i];
      for(int j = 0; j < nbf_1d; ++j)
        {
          int jj = nm[j];

          jacobian(ii,jj) += TEMP_JAC(i,j);
        }
    
    }

  }

//    for ( size_t i = 0; i < jacobian.get_num_rows(); ++i)
//    { 
//      for ( size_t j = 0; j < jacobian.get_num_cols(); ++j)
//      {
//        std::cout << jacobian(i,j) << " ";
//      }     
//        std::cout << std::endl; 
//    }
//



}



