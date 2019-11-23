#include <iostream>

#include <vector>
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
		DenseMatrix       A(3,3, 0.0);
		DenseMatrix       B(3,1, 1.0);
		DenseMatrix       X(3,1);

		A(0,0) = 1.0; 
		A(1,1) = 2.0;
		A(2,2) = 3.0;

		Solver.factorization( A );
		int info = Solver.solve(A,B);

		std::cout 
			<< B[0] << " " 
			<< B[1] << " "
			<< B[2] << " "
			<< std::endl;

		std::cout << info << std::endl;
		
	}


	return 0;
}
