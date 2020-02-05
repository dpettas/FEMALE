#include <iostream>

#include "./Matrix.h"

#include <vector>
#include <iterator>

//<><><><><><><><><><><><><><><><><><><>
// MODULE DISCRETIZATION_DATA 
//<><><><><><><><><><><><><><><><><><><>

int const nbf_1d    = 2;
int const nbf_2d    = nbf_1d * nbf_1d;
int const nbf_tr_2s = 3;

int nxel; 
int nyel; 
int nntol; 
int nntol_tr;

int nnx; 
int nny; 

int nodtol; 
int nunknowns;

void discretization_data(); 

	
//<><><><><><><><><><><><><><><><><><><>
// MODULE GLOBAL_ARRAY 
//<><><><><><><><><><><><><><><><><><><>

std::vector<double> residual;
std::vector<double> solution;
std::vector<double> jacobian;


void allocate_global_arrays(bool allocate, int n );

	
//<><><><><><><><><><><><><><><><><><><>
// MODULE NEWTON_RAPSHON 
//<><><><><><><><><><><><><><><><><><><>
int    const max_num_iter = 1000; 
double const max_error    = 1.e-6;

int          iteration;
double       res_norm;

	
//<><><><><><><><><><><><><><><><><><><>
// MODULE ENUMERATION_MODULE
//<><><><><><><><><><><><><><><><><><><>

class Boundary{
  private:
  public:
    int nntol; 
    int nnod;
    std::vector<std::vector<int>> nm_elem;
};


int  const nbnds = 4;
char const direction = 'x';

std::vector<Boundary> bnd(nbnds);

std::vector<std::vector<int>>  nm_elem;
std::vector<std::vector<int>>  nm_tr_elem;

std::vector<std::vector<int>>  bnd1;
std::vector<std::vector<int>>  bnd2;
std::vector<std::vector<int>>  bnd3;
std::vector<std::vector<int>>  bnd4;


void allocate_boundary_type(bool allocate, Boundary _bnd, int _nnxy = 0);


int main()
{
  discretization_data();
  allocate_global_arrays(true, nunknowns);

  Matrix<double> A(3,3, 5.0);

  A(0,0) = 0.0;
  A(0,1) = 1.0;
  A(1,1) = 2.0;


  std::cout << A(2,2) << std::endl;
  return 0;
}












void discretization_data()
{
  nxel = 10;
  nyel = 10;

  nntol = nxel * nyel; 
  nntol_tr = 2.0 * nntol;

  nnx = (nbf_1d - 1) * nxel + 1;
  nny = (nbf_1d - 1) * nyel + 1;

  nodtol = nnx * nny; 
  nunknowns = nodtol;

}


void allocate_global_arrays(bool allocate, int n)
{
 if (allocate){    
    residual.reserve(n);
    solution.reserve(n);
    jacobian.reserve(n*n);
  } 
  else 
  {
    residual.clear();
    solution.clear();
    jacobian.clear();
  }

}

void allocate_boundary_type(bool allocate, Boundary _bnd, int _nnxy)
{
  _bnd.nnod = _nnxy;
  _bnd.nntol= (_bnd.nnod -1)/(nbf_1d-1);

  if (allocate) { 
    _bnd.nm_elem.reserve(_bnd.nntol);
    
    for (std::vector<std::vector<int>>::iterator it = _bnd.nm_elem.begin();
                                                 it < _bnd.nm_elem.end()  ;++it)
    {
     it->reserve(nbf_1d);
    }
 
  }
  else{
    _bnd.nm_elem.clear();
  }


}




