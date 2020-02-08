#include "Element_1D.h"

Element_1D::Element_1D( std::vector<int> _conn, std::vector<double>*_x)
{ conn = _conn; 
  x    = _x; 
}

std::vector<double>& Element_1D::get_position()
{
  x_conn.push_back( x->operator[] ( conn[0]) ); 
  x_conn.push_back( x->operator[] ( conn[1]) ); 
  x_conn.push_back( x->operator[] ( conn[2]) ); 
 
  return x_conn;

}


