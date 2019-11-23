#include <iostream>

#include <vector>
#include "LinearAlgebra/DenseMatrix.hpp"
#include "LinearAlgebra/Solver/Lapack.h"
#include "LinearAlgebra/DenseMatrixSolver.hpp"
#include "BasisFunctions/BasisLagrange.hpp"
#include "BasisFunctions/Phi.hpp"




int main()
{
	Phi phi_0 ( [](double x) {return x*x; }, 5.0 );

	std::cout<< phi_0.evaluate(2.0) << std::endl;

	return 0;
}



