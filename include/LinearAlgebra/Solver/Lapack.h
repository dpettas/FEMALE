#ifndef LAPACK_H
#define LAPACK_H

//<><><><><><><><><><><><><><><><><><><><>
// Include files 
//<><><><><><><><><><><><><><><><><><><><>

#include "LinearAlgebra/DenseMatrix.hpp"


#ifdef MKL
#define dgetf2_ DGETF2
#define dgetfr_ DGETFR
#define dgetrs_ DGETRS
#endif

 
extern "C"  int dgetf2_(int *m, int *n, double *a, int *lda, int *ipiv, int *info);i


// Lapack factorization routine
extern "C"  int dgetrf_(int *m, int *n, double *a, int *lda, int *ipiv, int *info);
// you may need add int at the end to specify the lenght of trans
extern "C"  int dgetrs_(const char    *trans,
							               	 int    *n    ,
															 int    *nrhs ,
															 double *a    ,
															 int    *lda  ,
															 int    *ipiv ,
															 double *b    ,
															 int    *ldb  ,
															 int    *info);



int dgetf2(DenseMatrix& A, std::vector<int> &ipiv)

{
	int m = A.get_nrows();
	int n = A.get_ncols();
	int info;
	dgetf2_(&m, &n, &*A.begin(), &m, &*ipiv.begin(), &info);
	return info;
}

int dgetrf(DenseMatrix& A, std::vector<int> &ipiv)
{
	int m = A.get_nrows();
	int n = A.get_ncols();
	int info;
	dgetrf_(&m, &n, &*A.begin(), &m, &*ipiv.begin(), &info);
	return info;
}

int dgetrs(DenseMatrix& A, DenseMatrix& B, std::vector<int> &ipiv)
{
	int m = A.get_nrows();
	int n = A.get_ncols();
	int nrhs = B.get_ncols();
	int info;
	dgetrs_("N", &m, &nrhs, &*A.begin(), &m, &*ipiv.begin(), &*B.begin(), &m, &info);
	return info;
}

#endif
