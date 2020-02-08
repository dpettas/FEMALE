#ifndef MESH_1D
#define MESH_1D

#include <vector>
#include "Element_1D.h"


class Mesh1D
{
  private:
    int nxel;
    int nbf_1d; 
    int nnx; 
    int nodtol; 


    double low; 
    double  up; 
    
    std::vector<double>           x; 
    std::vector<Element_1D> element; 

  public:

    Mesh1D(){};
    Mesh1D( Mesh1D& other);
    Mesh1D(int NumberOfElements, int NumberOfBasis, double _lower_limit, double _upper_limit);
 

    int&    get_NumberOfElements() { return nxel  ;}
    int&    get_NumberOfBasis   () { return nbf_1d;}
    int&    get_NumberOfNodes   () { return nodtol;}

    double& get_Low_Mesh_Limit  () { return    low;}
    double& get_Upper_Mesh_Limit() { return     up;}


    std::vector<double>&      get_Nodes()          { return       x;}
    std::vector<Element_1D>&  get_Elements()       { return element;}
    Element_1D&               get_Element (int id) { return element[id];}
  protected: 

    void calculate_nodes  (); 
    void calculate_element(); 
     
};






#endif 
