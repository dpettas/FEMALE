#include "Fem_1D.h"


Fem_1d::Fem_1d( Mesh1D& _mesh)
{
  nxel      = _mesh.get_NumberOfElements(); 
  nbf_1d    = _mesh.get_NumberOfBasis();
  nodtol    = _mesh.get_NumberOfNodes();  
  neq       = 1; 
  mesh      = _mesh; 
  nunknowns = nodtol * neq; 

  this->allocate_memory_global_arrays();
}


Fem_1d::Fem_1d( Mesh1D& _mesh, int NumberOfEquations)
{
  nxel      = _mesh.get_NumberOfElements(); 
  nbf_1d    = _mesh.get_NumberOfBasis();
  nodtol    = _mesh.get_NumberOfNodes();  
  neq       = NumberOfEquations; 
  mesh      = _mesh;
  nunknowns = nodtol * neq; 

  this->allocate_memory_global_arrays();
}


void Fem_1d::allocate_memory_global_arrays()
{
  res.resize (nunknowns); 
  sol.resize (nunknowns); 
  jac.reserve(nunknowns, nunknowns); 
}

void Fem_1d::clear_memory_global_arrays()
{
  res.clear(); 
  sol.clear(); 
  jac.clear();
}


