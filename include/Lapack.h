#ifndef LINEARSOLVE_H
#define LINEARSOLVE_H

#include "Matrix.h"
#include "Array.h"

#include <vector>
#include <algorithm>

#include <lapacke.h>

class Lapack

{
  private: 


    std::vector<int> ipiv;      
  public:
  Lapack() {};

  int factorize( Matrix& A );
  int solve    ( Matrix& A, Matrix& B); 
  int solve    ( Matrix& A, Array&  B);
    
  std::vector<int> get_pivoting ()       { return ipiv;}
  std::vector<int> get_pivoting () const { return ipiv;}

};








#endif 

