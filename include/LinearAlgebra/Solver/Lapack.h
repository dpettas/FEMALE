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

 
extern "C"  int dgetf2_(int *m, int *n, double *a, int *lda, int *ipiv, int *info);


// Lapack factorization routine

extern "C"  int dgetrf_(int    *m, 
								        int    *n,
											 	double *a,
											 	int    *lda,
											 	int    *ipiv,
											 	int    *info);
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


#endif
