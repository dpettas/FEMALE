
#ifndef DEBUGGING_H
#define DEBUGGING_H 

#include <iostream>


#define debug_print(name) print_name_value(#name, (name))

void print_name_value(std::string name, int& value); 




void print_name_value(std::string name, int& value) {
  std::cout << name  << "\t" 
            << value << std::endl;
}

#endif


