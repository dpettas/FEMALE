#include <iostream>
#include <cmath>
#include <ostream>
#include <vector>
#include "./include/LinearAlgebra.h"

#include "./include/BasisFunctions/Lagrange.hpp"
#include "./include/BasisFunctions/Phi.hpp"
#include "./include/ModelParameter.hpp"


int main()
{
  ModelParameter Re (19.0, 0.0, 20.0, -0.1);

  while (Re.is_in_the_bounds())
  {
    std::cout<< Re << std::endl; 

    Re ++;  
  
  };Re.fix_values_between_the_limits();

  std::cout << Re << std::endl;


}



