
#ifndef DENSE_MATRIX_SOLVER_H
#define DENSE_MATRIX_SOLVER_H

#include <vector>
#include <algorithm>
#include "LinearAlgebra/DenseMatrix.hpp"
#include "LinearAlgebra/Solver/Lapack.h"


class DenseMatrixSolver
{
	private:
		int info;
		std::vector<int> ipiv; 

	public:

		DenseMatrixSolver() {info = 0; std::fill(ipiv.begin(),ipiv.end(), 0.0); }	

		int factorization ( DenseMatrix& A                        );
		int solve         ( DenseMatrix& A, DenseMatrix&         B);  
		int solve         ( DenseMatrix& A, std::vector<double>& B); 

};

int DenseMatrixSolver::factorization (DenseMatrix& A) {

	/*
	 * Notice that the method returns an integer in case 
	 * where we want to do error handling. 
	 * List of errors:
	 * 		~ 100: The matrix is not a square matrix.
	 *
	 */

	if ( !A.isSquare() )  return 100;


	int m = A.get_nrows();
	int n = A.get_ncols();

	for (size_t i; i < A.size(); ++i )
	{
		std::cout << A[i] << std::endl;

	}
	dgetrf_( &m,
				   &n,
					 &*A.begin()   ,
					 &m            ,
					 &*ipiv.begin(),
					 &info);

	return info;

}


int DenseMatrixSolver::solve( DenseMatrix& A, DenseMatrix& B  ){

	if ( !A.isSquare()         ) return 100; 
	if ( !A.haveTheSameRows(B) ) return 200;


 
	int m    = A.get_nrows(); 
	int n    = A.get_ncols();
	int nrhs = B.get_ncols();

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


int DenseMatrixSolver::solve( DenseMatrix& A, std::vector<double>& B  ){

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


#endif
