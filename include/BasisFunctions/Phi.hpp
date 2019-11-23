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



Phi::Phi( double (*f_)  (double) ) { f = f_; df = NULL;}

Phi::Phi( double (*f_)  (double) ,
				  double value ) { f = f_; val = value; }

Phi::Phi( double (*f_)  (double),
					double (*df_) (double) ) { f = f_; df = df_ ;}






double Phi::get_value () {return val;}


double Phi::evaluate (double val_){return  f(val_);}
//double Phi::evaluate ()           {return  f(val );}


double Phi::derivative(double val_)
{
	if   (df != NULL) { return df(val_)    ;}
	else              { return std::nan("");}
}

double Phi::numerical_derivative(double val_)
{
	return (f(val_ + eps)- f(val_))/eps;
}



#endif



