
#ifndef DENSE_MATRIX_SOLVER_H
#define DENSE_MATRIX_SOLVER_H

#include <vector>
#include <iterator>
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


	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	// getters 
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	
	int get_info() { return info; }

	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	// Boolean methods
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	 
	bool success() { return info == 0; }
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	// Methods
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

		int factorization ( DenseMatrix& A );

		int solve         ( DenseMatrix& A,
									     	DenseMatrix& B,
											 	DenseMatrix& X); 

		int solve         ( DenseMatrix& A,
									      std::vector<double>& B,
												std::vector<double>& X); 

};

#endif
