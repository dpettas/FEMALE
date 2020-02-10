#ifndef GAUSSPOINTS1D_H
#define GAUSSPOINTS1D_H

#include <math.h>
#include <utility>
#include <vector>


#define _GSPT_ std::pair<double, double>

class GaussPoints_1D
{
  private: 
    std::vector<_GSPT_> pt;

  public: 

    GaussPoints_1D( ){};   
    int    get_number_of_points() { return    pt.size() ;}

     double get_point ( int id)    { return pt[id].first ;}
     double get_weight( int id)    { return pt[id].second;}
    _GSPT_ get_pair   ( int id)    { return       pt[id] ;} 

    ~GaussPoints_1D(){};
  protected:
    void   add_new_point( const double& _p, const double& _w)
      { pt.push_back(_GSPT_ (_p, _w ) ); } 
};
//<><><><><><><><><><><><><><><><><><><><><><><><>
// 1 GAUSS POINT IN THE INTERVAL OF [-1,1]
//<><><><><><><><><><><><><><><><><><><><><><><><>

class Gauss_1_Points_1D: public GaussPoints_1D
{
  private: 

  public: 

    Gauss_1_Points_1D()
    { 
     this->add_new_point( 0.0, 2.0 );
    } 
}; 


//<><><><><><><><><><><><><><><><><><><><><><><><>
// 2 GAUSS POINTS IN THE INTERVAL OF [-1,1]
//<><><><><><><><><><><><><><><><><><><><><><><><>

class Gauss_2_Points_1D: public GaussPoints_1D
{
  private: 

  public: 

    Gauss_2_Points_1D()
    { 
     this->add_new_point( - sqrt(1.0/3.0), 1.0 );
     this->add_new_point( + sqrt(1.0/3.0), 1.0 );
    } 
}; 


//<><><><><><><><><><><><><><><><><><><><><><><><>
// 3 GAUSS POINTS IN THE INTERVAL OF [-1,1]
//<><><><><><><><><><><><><><><><><><><><><><><><>

class Gauss_3_Points_1D: public GaussPoints_1D
{
  private: 

  public: 

    Gauss_3_Points_1D()
    { 
     this->add_new_point( - sqrt(3.0/5.0), 5.0/9.0 );
     this->add_new_point(            0.0 , 8.0/9.0 ); 
     this->add_new_point( + sqrt(3.0/5.0), 5.0/9.0 );
    } 
}; 


//<><><><><><><><><><><><><><><><><><><><><><><><>
// 4 GAUSS POINTS IN THE INTERVAL OF [-1,1]
//<><><><><><><><><><><><><><><><><><><><><><><><>

class Gauss_4_Points_1D: public GaussPoints_1D
{
  private: 

  public: 

    Gauss_4_Points_1D()
    { 
     this->add_new_point( -0.8611363115940526 , 0.3478548451374538 ); 
     this->add_new_point( -0.3399810435848563 , 0.6521451548625461 );
     this->add_new_point(  0.3399810435848563 , 0.6521451548625461 ); 
     this->add_new_point(  0.8611363115940526 , 0.3478548451374538 );
    }

}; 


#undef GSPT
#endif
