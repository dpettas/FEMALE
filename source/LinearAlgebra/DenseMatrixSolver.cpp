#include<vector>
#include"LinearAlgebra/DenseMatrixSolver.hpp"
#include"LinearAlgebra/Solver/Lapack.h"

#define _SQUARE_ 100 
#define _ROWS_   200

int DenseMatrixSolver::factorization (DenseMatrix& A) {

	if ( !A.isSquare() )  return _SQUARE_;

	int m = A.get_nrows();
	int n = A.get_ncols();
	// Reserve the ipiv memory
	ipiv.reserve( n);

	dgetrf_( &m,
				   &n,
					 &*A.begin()   ,
					 &m            ,
					 &*ipiv.begin(),
					 &info);

	return info;

}


int DenseMatrixSolver::solve( DenseMatrix& A,
							               	DenseMatrix& B,
															DenseMatrix& X)
{

	if ( !A.isSquare()         ) return _SQUARE_; 
	if ( !A.haveTheSameRows(B) ) return _ROWS_  ;
	if ( !A.haveTheSameRows(X) ) return _ROWS_  ; 


 
	int m    = A.get_nrows(); 
	int n    = A.get_ncols();
	int nrhs = B.get_ncols();
	// Assign the values of B in X
  X = B; 

	dgetrs_( "N"           , 
					 &m            ,
					 &nrhs         ,
					 &*A.begin()   ,
					 &m            ,
					 &*ipiv.begin(),
					 &*X.begin()   ,
					 &m            ,
					 &info);

	return info;
}


int DenseMatrixSolver::solve( DenseMatrix&         A,
							              	std::vector<double>& B,
															std::vector<double>& X){

	if ( !A.isSquare()         ) return 100; 
	if ( !A.haveTheSameRows(B) ) return 200;

	int m    = A.get_nrows(); 
	int n    = A.get_ncols();
	int nrhs = 1;

	dgetrs_( "N"           , 
					 &m            ,
					 &nrhs         ,
					 &*A.begin()   ,
					 &m            ,
					 &*ipiv.begin(),
					 &*B.begin()   ,
					 &m            ,
					 &info);

	return info;
}


