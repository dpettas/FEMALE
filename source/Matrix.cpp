#include "Matrix.h"


Matrix::Matrix()
  { n = 0; m = 0; std::vector<double>::resize( n * m); }


Matrix::Matrix(const size_t _n, const size_t _m)
  { n = _n; m = _m; std::vector<double>::resize(n*m     );}

Matrix::Matrix(const size_t _n, const size_t _m, const double& val)
  { n = _n; m = _m; std::vector<double>::resize(n*m, val);}


Matrix::Matrix(const Matrix& other)
  { 
    n       = other.get_num_rows(); 
    m       = other.get_num_cols();
    std::vector<double>::resize( n*m);}


void Matrix::reserve(size_t _n, size_t _m )
  { std::vector<double>::reserve(_n*_m     ); }

void Matrix::resize (size_t _n, size_t _m )
  { std::vector<double>::resize (_n*_m     ); n = _n; m = _m; }

void Matrix::resize (size_t _n, size_t _m, double& val)
  { std::vector<double>::resize (_n*_m, val); n = _n; m = _m; }


void Matrix::clear()
  { n = m = 0 ; std::vector<double>::clear(); } 



