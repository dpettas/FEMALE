
#include "Matrix.h"
#include "Array.h"
#include "Lapack.h"
#include "Fem_1D.h"

#include "Mesh_1D.h"
#include "Element_1D.h"

//#include "GaussPoints1D.h"

#include <iostream>
#include <utility>
#include <vector> 
#include <math.h>
#include <string>

#include "debugging.h"

#define __NXEL__         10 
#define __NBF_1D__        3
#define __LOW_BOUND__   0.0 
#define __UPPER_BOUND__ 1.0





int main()
{

  Mesh1D MainMesh (__NXEL__      , 
                   __NBF_1D__    ,
                   __LOW_BOUND__ ,
                   __UPPER_BOUND__);

//
  Fem_1d Base ( MainMesh );
//
//  debug_print( Base.get_NumberOfBasis()     );
//  debug_print( Base.get_NumberOfElements()  ); 
//  debug_print( Base.get_NumberOfNodes()     ); 
//  debug_print( Base.get_NumberOfEquations() );


 

  return 0;
}




