
#include "LinearSolve.h"



//int Lapack::factorize( Matrix& A)
//{
//  int n = A.get_num_rows();
//  int m = A.get_num_cols(); 
//  int info =-100;
//
//
//  ipiv.resize( std::min(n,m) );
//
//  dgetrf(&n, &m, &*A.begin(), &m, &*ipiv.begin(), &info);
//
//  return info;
//}
//

//
//int Lapack::solve(Matrix<double>& A, Matrix<double>& B)
//{
//  int n    = A.get_num_rows();
//  int m    = A.get_num_cols();
//  int nrhs = B.get_num_cols();
//
//
//
//  int info ;
//
//  dgetrs_("N", &n, &nrhs         , &*A.get_elements().begin(),
//               &n, &*ipiv.begin(), &*B.get_elements().begin(),
//               &m, &info);
//
//  std::cout << B(0,0) << std::endl; 
//  std::cout << B(1,0) << std::endl;
// 
//  return info;
//}












