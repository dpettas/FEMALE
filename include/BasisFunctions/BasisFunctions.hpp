#ifndef BASIS_FUNCTIONS_H
#define BASIS_FUNCTIONS_H


#include <iostream>
#include <vector>
#include <cmath>

#include "BasisFunctions/Phi.hpp"


/* The class BasisFunctions specifies the default parameters 
 * for the definitions of the basis function. 
 * This value will be inherited in other functions such as 
 * the Lagrange_1D in which the functions of the basis functions
 * are declared. 
 * */


class BasisFunctions{

	private:

	protected:
		size_t              num   = -1; 
		double              value = std::nan("");

		std::vector<Phi>    phi;
		std::vector<double> eval_phi;
		std::vector<double> eval_der;	
	public:
	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Setters
	//<><><><><><><><><><><><><><><><><><><><><><><><>	
	void set_numOfBasisFunctions( size_t n      ) { num   = n     ;}
	void set_value              ( double value_ ) { value = value_;}

	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Getters
	//<><><><><><><><><><><><><><><><><><><><><><><><>	
	size_t get_number_of_basis() {return num  ;}
	double get_value          () {return value;}


	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Boolean
	//<><><><><><><><><><><><><><><><><><><><><><><><>	
	bool is_number_of_basis_defined() { return num > 0           ;}
	bool is_value_defined          () { return !std::isnan(value);} 
	bool is_basis_empty            () { return  phi.empty()      ;}
	
	bool is_eval_phi_defined       () { return !eval_phi.empty() ;}
	bool is_eval_der_defined       () { return !eval_der.empty() ;}

	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Methods
	//<><><><><><><><><><><><><><><><><><><><><><><><>	

	void evaluate (double val);
	void evaluate ();



};

#endif
