
#ifndef LAGRANGE_H
#define LAGRANGE_H


#include <iostream>
#include <vector>
#include <cmath>

#include "BasisFunctions/BasisFunctions.hpp"
#include "BasisFunctions/Phi.hpp"



class Lagrange_1D: public BasisFunctions
{

	public:

		Lagrange_1D();
		Lagrange_1D( double  val);


	//<><><><><><><><><><><><><><><><><><><><><><><><><>
	// Operators
	//<><><><><><><><><><><><><><><><><><><><><><><><><>

	Phi operator[](size_t i) {return phi[i];}
};



//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Default Constructor
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

Lagrange_1D::Lagrange_1D(){

this->set_number_of_basis_functions(3);//Define the number of basis functions


// Define the lagrange basis functions defined from 0 to 1
phi.push_back( Phi(  [](double x) { return -0.5*  x *(1.0 - x); }  ));
phi.push_back( Phi(  [](double x) { return +(1.0 -x)*(1.0 + x); }  ));
phi.push_back( Phi(  [](double x) { return +0.5*  x *(1.0 + x); }  ));
}

Lagrange_1D::Lagrange_1D(double val){

this->set_number_of_basis_functions(3);// set the number of basis functions
this->set_value(val)                  ;// set the poisition of the basis functions


phi.push_back( Phi(  [](double x) { return -0.5*  x *(1.0 - x); }, val ));
phi.push_back( Phi(  [](double x) { return +(1.0 -x)*(1.0 + x); }, val ));
phi.push_back( Phi(  [](double x) { return +0.5*  x *(1.0 + x); }, val ));


// this->calculate();  // calculates the value of the function and the corresponding derivative
//

}



#endif
