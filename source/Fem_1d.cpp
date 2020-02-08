
#include "Fem_1D.h"

Fem_1d::Fem_1d( Mesh1D& mesh)
{
  nxel = mesh.get_NumberOfElements(); 

  neq  = 1;

}


