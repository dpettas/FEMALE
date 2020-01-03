#include <iostream>

#include <vector>
#include "./LinearAlgebra/DenseMatrix.hpp"
#include "./LinearAlgebra/Solver/Lapack.h"
#include "./LinearAlgebra/DenseMatrixSolver.hpp"
#include "./BasisFunctions/Lagrange.hpp"
#include "./BasisFunctions/Phi.hpp"



int main()
{

	BasisFunctions bf;

	Lagrange_1D phi(-1.0); 

	std::cout << phi.get_value() << std::endl;

	return 0;
}



