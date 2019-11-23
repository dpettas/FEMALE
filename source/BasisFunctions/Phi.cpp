#include "BasisFunctions/Phi.hpp"

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


