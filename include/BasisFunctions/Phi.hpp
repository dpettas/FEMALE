#ifndef PHI_H
#define PHI_H

#include <cmath>




class Phi{

	private:
		double (*f )(double) = NULL  ;
		double (*df)(double) = NULL  ;
		double eps           = 1.e-8 ;
		double val           = std::nan("");

	public:
		Phi(){};
		Phi( double (*f_) (double)                         );
		Phi( double (*f_) (double), double value           );
		Phi( double (*f_) (double), double (*df_) (double) );

		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Setters 
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		void   set_epsilon ( double eps_ ); 
		double set_value   ( double val_ );

		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Getters
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>

		double get_value  ();
		
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Methods
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>

		double evaluate             (double val_);
		double evalueate            ()           ;
		double derivative           (double val_);
		double numerical_derivative (double val_);

};



#endif



