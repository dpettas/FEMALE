
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


    Array  res; 
    Array  sol; 
    Matrix jac;

  public: 

    Fem_1d( Mesh1D& mesh);

    int& get_NumberOfElements() { return nxel  ;}
    int& get_NumberOfBasis   () { return nbf_1d;}
    int& get_NumberOfNodes   () { return nodtol;}



  protected:
    void set_DiscretizationData(); 
    void set_global_arrays();
  
    void clear_global_arrays(); 

};




#endif










