
#ifndef FEM_1D
#define FEM_1D

#include "Array.h" 
#include "Matrix.h"
#include "Mesh_1D.h"

class Fem_1d
{
  private: 
    int neq;
    int nbf_1d; 
    
    int nxel; 
    int nnx; 
    int nodtol; 
    int nunknowns; 


    Mesh1D mesh; 

    Array  res; 
    Array  sol; 
    Matrix jac;

  public: 

    Fem_1d( Mesh1D& mesh);
    Fem_1d( Mesh1D& mesh, int NumberOfEquations);




    int&    get_NumberOfElements () { return nxel  ;}
    int&    get_NumberOfBasis    () { return nbf_1d;}
    int&    get_NumberOfNodes    () { return nodtol;}
    int&    get_NumberOfEquations() { return    neq;}
    Mesh1D& get_Mesh             () { return   mesh;}

  protected:

    void allocate_memory_global_arrays();
    void clear_memory_global_arrays(); 

};




#endif










