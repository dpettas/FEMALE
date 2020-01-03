#include <iostream>
#include <cmath>

class ModelParameter
{
  private:
    double ival; 
    double fval;
    double step;
  
    double cval;
    bool   end = false; 
  public:
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    // Constructor
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

    ModelParameter()            {cval = 0.0; ival = 0.0; fval = 0.0; step = 0.0; this->check();}
    ModelParameter(double ival_){cval = ival = fval = ival_        ; step = 0.0; this->check();}

    ModelParameter(double ival_, double fval_, double step_)
    {cval = ival = ival_; fval = fval_; step = step_; this->check();}
 
    ModelParameter(double cval_, double ival_, double fval_, double step_)
    {cval = cval_; ival = ival_; fval = fval_; step = step_; this->check();}

    ModelParameter( const ModelParameter& other)
    {
     ival = other.get_initial(); 
     fval = other.get_final  ();
     step = other.get_step   ();
     this->check();
    }
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    // Methods
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    void check() {
      if ( this->are_not_the_bounds_correct() ) 
     {std::cout << "The upper bound of the instance is smaller than the lower" << std::endl;
      std::cout << " lower value : " << ival <<
                   " upper value : " << fval << std::endl;
     }   
    }

    void fix_values_between_the_limits()
    {  if      ( this->is_larger_than_upper_bound() ) { cval = fval;}
       else if ( this->is_lower_than_lower_bound () ) { cval = ival;}     
    }

    void increment    () { cval += step; }
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    // SETTERS
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    void set_val    (double val) { cval = val; }
    void set_initial(double val) { ival = val; }
    void set_final  (double val) { fval = val; }
    void set_step   (double val) { step = val; }
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    // GETTERS
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    const double& get_initial() const {return this->ival;}
    const double& get_final  () const {return this->fval;}
    const double& get_step   () const {return this->step;}
    const double& get_val    () const {return this->cval;}
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    // BOOLEAN
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    const bool   are_the_bounds_correct    () const {return fval >  ival                   ;}
    const bool   are_not_the_bounds_correct() const {return !this->are_the_bounds_correct();}
    const bool   is_static                 () const {return ival == fval || step == 0.0    ;}
    const bool   is_in_the_bounds          () const {return cval >= ival-std::abs(step)  && 
                                                            cval <= fval+std::abs(step)    ;}
    const bool   in_not_in_the_bounds      () const {return !this->is_in_the_bounds()      ;}
    const bool   is_larger_than_upper_bound() const {return cval > fval                    ;}
    const bool   is_lower_than_lower_bound () const {return cval < ival                    ;}
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    // OPERATORS
    // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    ModelParameter  operator + (double val) { return  ModelParameter(cval+val,ival,fval,step); }
    ModelParameter& operator +=(double val) { 
      cval += val;
      if      ( this->is_larger_than_upper_bound() ) { cval = fval;}
      else if ( this->is_lower_than_lower_bound () ) { cval = ival;}
      return *this;
    }      
    void operator ++()          { this->increment()  ;}
    void operator ++(int)       { this->increment()  ;}
    bool operator <=(double val){ return cval <= val ;}
    bool operator >=(double val){ return cval >= val ;}
    bool operator > (double val){ return cval >  val ;}
    bool operator < (double val){ return cval <  val ;}


    friend std::ostream& operator<<(std::ostream& os, const ModelParameter& mp);

};

std::ostream& operator << (std::ostream& os, const ModelParameter& mp)
{
  os << mp.get_val();
  return os;
}

