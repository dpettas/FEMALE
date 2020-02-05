#ifndef MATRIX_H
#define MATRIX_H

#include <iterator>
#include <vector>
#include <iostream>

template <class T>
class Matrix
{
  private:
    std::vector<T> index; 
    size_t n; 
    size_t m;

  public:
    Matrix();
    Matrix(size_t _n, size_t _m);
    Matrix(size_t _n, size_t _m, T val);
    Matrix( Matrix& other); 

    void initialize( T& val);

    void resize (size_t _n, size_t _m);
    void reserve(size_t _n, size_t _m);
    void clear  ();
    size_t& get_num_rows()                   { return n;}
    size_t& get_num_cols()                   { return m;}
    T&      get_index   (size_t i, size_t j) { return index[i + j*m]; }

    T&      operator()  (size_t i, size_t j) { return this->get_index(i,j);}

    const size_t size    () const            { return index.size();}
    const size_t capacity() const            { return index.capacity();}  

};

template<class T> Matrix<T>::Matrix() {n = m = 0; index.reserve(n*m);}
template<class T> Matrix<T>::Matrix(size_t _n, size_t _m)        { n = _n; m = _m; index.reserve(n * m); }
template<class T> Matrix<T>::Matrix(size_t _n, size_t _m, T val)
  { n = _n; m = _m; index.reserve(n * m); this->initialize(val); }
template<class T> Matrix<T>::Matrix(Matrix<T>& other)           
  { n = other.get_num_rows(); m = other.get_num_cols(); index.swap(other);}
//<><><><><><><><><><><><><><><><><><><><><><><><>
// METHODS
//<><><><><><><><><><><><><><><><><><><><><><><><>

template<class T>
void Matrix<T>::initialize(T& val)
{
//  for (std::vector<T>::iterator it = indexr.begin() ; it != index.end(); ++it)
//  {} 
}

template<class T>
void Matrix<T>::resize (size_t _n, size_t _m)        { n = _n; m = _m; index.resize(n*m)   ;}

template<class T>
void Matrix<T>::reserve(size_t _n, size_t _m)        {                 index.reserve(_n*_m);}









#endif
