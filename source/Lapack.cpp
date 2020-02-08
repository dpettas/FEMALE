#include "Lapack.h"

int Lapack::factorize(Matrix& A)
{
  int n = A.get_num_rows();
  int m = A.get_num_cols();

  int info;

  ipiv.resize( std::min(n,m), 0 );


  dgetrf_(&n, &m, & *A.begin(), &n, & *ipiv.begin(), &info);

  return info;
}


int Lapack::solve(Matrix& A, Matrix& B)
{
  int n    = A.get_num_rows();
  int nrhs = B.get_num_cols();
  int info;

  char trans = 'N';  

	dgetrs_(&trans, &n, &nrhs, &*A.begin(), &n, &*ipiv.begin(), &*B.begin(), &n, &info);

  return info;
}

int Lapack::solve(Matrix& A, Array& B)
{
  int n    = A.get_num_rows();
  int nrhs = 1;
  int info;

  char trans = 'N';  

	dgetrs_(&trans, &n, &nrhs, &*A.begin(), &n, &*ipiv.begin(), &*B.begin(), &n, &info);

  return info;
}



