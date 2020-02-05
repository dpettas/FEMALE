#include <vector>
#include <iostream>

std::vector<double> linspace(double xmin, double xmax, int n);

class Element
{
  private:
    size_t n;
    std::vector<size_t> index;
  public:

  Element(std::vector<size_t> _index );
};





int main()
{

 std::vector<double> a = linspace(2.0, 3.0, 11);  


 for (std::vector<double>::iterator i = a.begin(); i !=a.end(); ++i)
 {std::cout << *i << '\n';} 



  return 0;
}



std::vector<double> linspace( double xmin, double xmax, int n)
{
  std::vector<double> out( n , 0.0); 
  double              step = (xmax - xmin)/(n-1);

  for(size_t i; i < n; ++i){out[i] = xmin + step * i;}

  return out;
}




