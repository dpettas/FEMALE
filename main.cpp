#include <iostream>

#include <vector>
#include "LinearAlgebra/DenseMatrix.hpp"
#include "LinearAlgebra/Solver/Lapack.h"
#include "LinearAlgebra/DenseMatrixSolver.hpp"
#include "BasisFunctions/BasisLagrange.hpp"
#include "BasisFunctions/Phi.hpp"


class Test{

	private:
	double (*func)(double) = NULL;


	public:
		Test(){};
		Test( double (*bf_) (double) ) { func = bf_;   }

		double set_value  ( double val); // calculate the function and derivative
		double evaluate   ( double val);
		double derivative ( double val);

};


double Test::derivative( double val){
	return (func(val+1.e-12) - func(val))/1.e-12;
}

double Test::evaluate( double val) {return func(val);}



double function_0( double x);




int main()
{

	Test phi  ( function_0 ) ; 
	Test phi_ ([](double x ) { return x;} );

	std::cout << phi.evaluate  (5.0) << std::endl;	
	std::cout << phi.derivative(5.0) << std::endl;	


	std::cout << phi_.evaluate  (5.0) << std::endl;	
	std::cout << phi_.derivative(5.0) << std::endl;	



	return 0;
}


double function_0( double x)  { return x*x*x;}



