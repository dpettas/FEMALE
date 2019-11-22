#include <iostream>

#include "LinearAlgebra/DenseMatrix.hpp"
#include "LinearAlgebra/Solver/Lapack.h"
#include "LinearAlgebra/DenseMatrixSolver.hpp"


int main()
{

	// Dense Matrix empty
	{
		DenseMatrix A;
	}


	// Dense Matrix declaration
	{
		DenseMatrix A(3,3);
	}


	// Dense Matrix declaration with initialization
	{
		DenseMatrixSolver Solver;
		DenseMatrix       A(3,3, 1.0);
		DenseMatrix       B(3,1, 0.0);


		A(0,0) = 1.0; 
		A(1,1) = 2.0;
		A(2,2) = 3.0;

		Solver.factorization( A );


	}


	return 0;
}
