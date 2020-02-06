
#ifndef ARRAY_H
#define ARRAY_H 

#include <vector>

class Array: public std::vector<double>
{
  private: 

  public: 

  Array( size_t n ) { std::vector<double>::resize(n); }


  double& operator() (size_t i) { return operator[](i);}


};




#endif 


