#include "ModelParameter.hpp"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Constructors
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Default Constructor
ModelParameter::ModelParameter()
{cval = 0.0; ival = 0.0; fval = 0.0; step = 0.0; this->check();}


ModelParameter::ModelParameter(double ival_)
{cval = ival = fval = ival_        ; step = 0.0; this->check();}

ModelParameter::ModelParameter
(double ival_, double fval_, double step_)
{cval = ival = ival_; fval = fval_; step = step_; this->check();}

ModelParameter::ModelParameter
(double cval_, double ival_, double fval_, double step_)
{cval = cval_;
 ival = ival_;
 fval = fval_;
 step = step_;
 this->check();}
// Copy Constructor
ModelParameter::ModelParameter
( const ModelParameter& other)
{ cval = other.get_val    ();
  ival = other.get_initial(); 
  fval = other.get_final  ();
  step = other.get_step   ();
  this->check();
}
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Methods
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
void ModelParameter::check() 
{
 if ( this->are_not_the_bounds_correct() ) 
 {std::cout << 
 "The upper bound of the instance is smaller than the lower"
            << std::endl;
  std::cout << " lower value : " << ival <<
               " upper value : " << fval << std::endl;
  }   
}

void ModelParameter::fix_values_between_the_limits()
{ if      ( this->is_larger_than_upper_bound() ) { cval = fval;}
  else if ( this->is_lower_than_lower_bound () ) { cval = ival;}    }


std::ostream& operator << (std::ostream& os, const ModelParameter& mp)
{
  os << mp.get_val();
  return os;
}


