
#ifndef ELEMENT_1D
#define ELEMENT_1D 

#include <vector>
#include <iostream>

class Element_1D
{
  private: 
    std::vector<double>*   x;
    std::vector<int>    conn;

    std::vector<double> x_conn;  
  public: 

    Element_1D(); 
    Element_1D( std::vector<int> _conn, std::vector<double>* _x); 
    std::vector<int>      get_connectivity() { return conn;}
    std::vector<double>&  get_position    ();
};






#endif
