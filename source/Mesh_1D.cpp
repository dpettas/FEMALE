#include "Mesh_1D.h"

Mesh1D::Mesh1D(int NumberOfElements, int NumberOfBasis, double _lower_limit, double _upper_limit)
{
  nxel    = NumberOfElements; 
  nbf_1d  = NumberOfBasis; 

  nnx     = (nbf_1d - 1) * nxel + 1; 
  nodtol  = nnx;

  low     = _lower_limit;  
  up      = _upper_limit;

  // <><><><><><><><><><><><>
  x.resize( nodtol );

  // execute the private methods. 
  this->calculate_nodes(); 
  this->calculate_element();
}



Mesh1D::Mesh1D ( Mesh1D& other)
{
  nxel   = other.get_NumberOfElements(); 
  nbf_1d = other.get_NumberOfBasis(); 
  nodtol = other.get_NumberOfNodes(); 
  nnx    = nodtol;

  low    = other.get_Low_Mesh_Limit(); 
  up     = other.get_Upper_Mesh_Limit();  

  x      = other.get_Nodes(); 
  element= other.get_Elements();
}



void Mesh1D::calculate_nodes()
{
  double step = (up - low)/(nodtol-1);  

  x[0] = low; 

  for(int i = 1; i < nodtol; ++i) { x[i] = x[0] + step * i; }

}


void  Mesh1D::calculate_element()
{
  for (int el = 0; el < nxel; ++el)
  {
    int idx = (nbf_1d - 1) * el; 
    
    std::vector<int> tmp_conn = {idx + 0,
                                 idx + 1,
                                 idx + 2};

    element.push_back( Element_1D( tmp_conn, &x) );

  } 

}


