
#ifndef ARRAY_H
#define ARRAY_H 

#include <vector>

class Array: public std::vector<double>
{
  private: 

  public: 
  Array()           {};
  Array( size_t n             ) { std::vector<double>::resize(n);    }
  Array( size_t n, double val ) { std::vector<double>::resize(n,val);}

  double& operator() (size_t i) { return operator[](i);}

  Array&  operator = ( const double& val);


};


#endif 


