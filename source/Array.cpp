
#include "Array.h"

Array& Array::operator = (const double& val){ 
  
  for(std::vector<double>::iterator it = this->begin(); 
      it != this->end(); 
      ++ it) 
  { *it = val; }

  return *this;
}


