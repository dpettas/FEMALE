
#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H


#include <vector>


//create a template for different values T and not only double

class DenseMatrix: public std::vector<double>
{
	private:
	/* This class was inherit by the std::vector class
	 *
	 * The basic methods are:
	 * 	size_t get_rows() : returns the number of rows
	 * 	size_t get_cols() : returns the number of columns */


		size_t m; 
		size_t n; 

	public:
		// Constructor of the class 
		DenseMatrix()                    : 
			std::vector<double>(0)
			{ m = 0  ; n = 0 ; }

		DenseMatrix(size_t m_, size_t n_):
		 	std::vector<double>(m_*n_)
			{ m = m_ ; n = n_; }

		DenseMatrix(size_t m_, size_t n_, double val): 
			std::vector<double> (m_*n_, val)
			{ m = m_ ; n = n_; }

		//<><><><><><><><><><><><><><><><><><><><><><><><>
		// GETTERS
		//<><><><><><><><><><><><><><><><><><><><><><><><>

		size_t get_nrows() const { return m;}
		size_t get_ncols() const { return n;} 

		//<><><><><><><><><><><><><><><><><><><><><><><><>
		// Booleans Methods
		//<><><><><><><><><><><><><><><><><><><><><><><><>

		bool isSquare()        { return m == n;}
		bool haveTheSameRows( DenseMatrix& B)        { return n == B.get_nrows(); }
		bool haveTheSameRows( std::vector<double> B) { return m == B.size     (); }
		//<><><><><><><><><><><><><><><><><><><><><><><><>
		// METHODS
		//<><><><><><><><><><><><><><><><><><><><><><><><>
		void resize (size_t m_, size_t n_){ m = m_;  n = n_; 	std::vector<double>::resize (m_*n_);}
		void reserve(size_t m_, size_t n_){           				std::vector<double>::reserve(m_*n_);}
		void clear  ()	                  {	m = n = 0      ;	std::vector<double>::clear();       }
		void swap   (DenseMatrix& y){
			std::swap(n,y.n);
		 	std::swap(m,y.m);
			std::vector<double>::swap(y);
		}

		void clearMemory(){
			DenseMatrix empty;
		  swap(empty);
		}
		//<><><><><><><><><><><><><><><><><><><><><><><><>
		// OPERATORS
		//<><><><><><><><><><><><><><><><><><><><><><><><>

		      double& operator()(size_t i, size_t j)       { return operator[](i+j*m); }
		const double& operator()(size_t i, size_t j) const { return operator[](i+j*m); }
};


#endif
