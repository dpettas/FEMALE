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
		size_t              num    = 0; 
		double              value  = std::nan("");
		double              f_value;
		double             df_value;

		std::vector<Phi>    phi;

	public:
	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Setters
	//<><><><><><><><><><><><><><><><><><><><><><><><>	
	void set_number_of_basis_functions( size_t n      ) { num   = n     ;}
	void set_value                     ( double value_ ) { value = value_;}

	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Getters
	//<><><><><><><><><><><><><><><><><><><><><><><><>	
	size_t get_number_of_basis_functions() {return num  ;}
	double get_value          () {return value;}


	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Boolean
	//<><><><><><><><><><><><><><><><><><><><><><><><>	
	bool is_number_of_basis_defined() { return num > 0           ;}
	bool is_value_defined          () { return !std::isnan(value);} 
	bool is_basis_empty            () { return  phi.empty()      ;}
	
	//<><><><><><><><><><><><><><><><><><><><><><><><>
	// Methods
	//<><><><><><><><><><><><><><><><><><><><><><><><>	

	void calculate();

};

#endif
