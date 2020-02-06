#include "Matrix.h"
#include "Array.h"
#include "LinearSolve.h"

#include <lapacke.h>
#include <iostream>
#include <vector>


const int neq    = 1;
const int nbf_1d = 3;  
const int nrhs   = 1;

int nxel; 
int nnx ;
int nodtol; 
int nunknowns;



// 	    MODULE ELEMENTS_MODULE
//
//         INTEGER, PARAMETER:: NEQ    = 1   ! NUMBER OF EQUATIONS
//	     INTEGER, PARAMETER:: NBF_1d = 3   ! NUMBER OF BASIS FUNCTIONS PER ELEMENT
//     	 INTEGER, PARAMETER:: NRHS = 1                    
//		
//      
//         INTEGER :: NXEL                   ! TOTAL NUMBER OF ELEMENTS
//	     INTEGER :: NNX                    ! TOTAL NUMBER OF NODES IN THE X-DIRECTION
//    	 INTEGER :: NODTOL                 ! TOTAL NUMBER OF NODES
//	     INTEGER :: NUNKNOWNS              ! TOTAL NUMBER OF UNKNOWNS
//
//		 contains
//		 
//		 SUBROUTINE DISCRETIZATION_DATA
//		  IMPLICIT NONE
//          NXEL    = 10
//	      NNX     = (NBF_1d-1)*NXEL + 1
//    	  NODTOL  = NNX
//	      NUNKNOWNS = NEQ*NODTOL
//         END SUBROUTINE DISCRETIZATION_DATA
//		 
//     	END MODULE ELEMENTS_MODULE




int main()
{
    Lapack LinearSolver; 
    Matrix A(3,3); 
    Array  B(3); 

    A(0,0) = 1;
    A(0,1) = 2;
    A(0,2) =-1;

    A(1,0) = 2;
    A(1,1) = 2;
    A(1,2) = 2;

    A(2,0) = 1;
    A(2,1) =-1;
    A(2,2) = 2;


    B(0) = 2.0;
    B(1) =12.0;
    B(2) = 5.0;


    LinearSolver.factorize(A);
    LinearSolver.solve(A,B);      


    std::cout << "solution is:";    
    std::cout << "[" << B[0] << ", " << B[1] << ", " << B[2] << "," << "]" << std::endl;


    return(0);
}



