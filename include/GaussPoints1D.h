#ifndef GAUSSPOINTS1D_H
#define GAUSSPOINTS1D_H

#include <utility>
#include <vector>

class GaussPoints_1D
{

  private: 
    int num; 
    std::vector< std::pair<double, double> > pt;

  public: 

    GaussPoints_1D( int& numberofGaussPoints ){ num = numberofGaussPoints; };   

    void add_new_point( double& pt, double& weight);

};

void GaussPoints_1D::add_new_point(double& _p, double& _w)
{ 
 pt.push_back( std::pair<double,double> (_p,_w) );
}

//GaussPoints_1D Gs1D_3; 

//Gs1D_3.add_new_point( 0.3330, 5.0/8.0 ); 






#endif
