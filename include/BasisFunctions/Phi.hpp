#ifndef PHI_H
#define PHI_H

class Phi
{
	private: 
	double val; 
	double derivative; 

	public:



	double get_val()        const {return val;}
	double get_derivative() const {return derivative;}	
	double ddx()            const {return derivative;}


};
#endif



