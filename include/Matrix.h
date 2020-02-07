#ifndef MATRIX_H
#define MATRIX_H 

#include<vector>

class Matrix: public std::vector<double>
{
  private: 
    size_t n; 
    size_t m;

  public:
    Matrix();                             
    Matrix(const size_t  _n, const size_t  _m);
    Matrix(const size_t  _n, const size_t  _m, const double& val);
    Matrix(const Matrix& other);
   
    
    size_t         get_num_rows()       { return n; }
    size_t         get_num_rows() const { return n; }

    size_t         get_num_cols()       { return m; }
    size_t         get_num_cols() const { return m; }


    void           reserve( size_t _n, size_t _m);
    void           resize ( size_t _n, size_t _m); 
    void           resize ( size_t _n, size_t _m, double& val); 
    void           clear  ();

          double& operator()(size_t i, size_t j)       { return operator[](i + j * n); }
    const double& operator()(size_t i, size_t j) const { return operator[](i + j * n); }

    Matrix& operator = ( const double& val);


};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// METHODS
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

Matrix& Matrix::operator = (const double& val)
{

  for ( std::vector<double>::iterator it = this->begin(); 
        it != this->end(); 
        ++ it)
  { *it = val; }

  return *this;
}



#endif


