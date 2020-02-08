#include "Fem_1D.h"

Fem_1d::Fem_1d( Mesh1D& mesh)
{
  nxel      = mesh.get_NumberOfElements(); 
  nbf_1d    = mesh.get_NumberOfBasis();
  nodtol    = mesh.get_NumberOfNodes();  
  neq       = 1; 

  nunknowns = nodtol * neq; 

}


