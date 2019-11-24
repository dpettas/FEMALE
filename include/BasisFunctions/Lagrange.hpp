
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




Lagrange_1D::Lagrange_1D(){
// Define the lagrange basis functions defined from 0 to 1
phi.push_back( Phi(  [](double x) { return -0.5*  x *(1.0 - x); }  ));
phi.push_back( Phi(  [](double x) { return +(1.0 -x)*(1.0 + x); }  ));
phi.push_back( Phi(  [](double x) { return +0.5*  x *(1.0 + x); }  ));
}

Lagrange_1D::Lagrange_1D(double val){

	phi.push_back( Phi(  [](double x) { return -0.5*  x *(1.0 - x); }, val ));
	phi.push_back( Phi(  [](double x) { return +(1.0 -x)*(1.0 + x); }, val ));
	phi.push_back( Phi(  [](double x) { return +0.5*  x *(1.0 + x); }, val ));

}



#endif
