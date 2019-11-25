#ifndef PHI_H
#define PHI_H

#include <cmath>




class Phi{

	private:
		double  (*f )(double) = NULL  ;
		double  (*df)(double) = NULL  ;
		double  eps           = 1.e-8 ;
		double  val           = std::nan("");
		double dval           = std::nan("");
	public:
		Phi(){};
		Phi( double (*f_) (double)                         );
		Phi( double (*f_) (double), double value           );
		Phi( double (*f_) (double), double (*df_) (double) );

		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Setters 
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		void   set_epsilon ( double eps_ ); 
		void   set_value   ( double val_ ) {val = val_; }

		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Getters
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>

		double get_value  ();
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Getters
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>

		bool is_value_defined()     { return !std::isnan(val);}
		bool is_not_value_defined()	{ return  std::isnan(val);}
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		// Methods
		//<><><><><><><><><><><><><><><><><><><><><><><><><><>
		void calculate(); 
		
		double evaluate             (double val_);
		double evaluate             () {return f(val);}
		double derivative           (double val_);
	
		double derivative ()
			{ if (df!=NULL) { return df(val);}
				else          { return this->numerical_derivative(val);} 
			}

		double numerical_derivative (double val_);

		double numerical_derivative()
		{ return (f(val+eps) - f(val) )/eps;}
};



#endif



