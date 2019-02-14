#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "vector_mtx.h"

double *vector_malloc(int nmax){ //memory allocation for a vector 
    double *v;
    v = (double *) malloc(sizeof(double)*nmax);
    return v;
}

double **mtx_malloc(int mmax, int nmax){ //memory allocation for a matrix
    double **mtx;
    mtx = (double**)malloc(sizeof(double*)*mmax);
    
    for(int m=0;m<mmax;m++){
        mtx[m] = (double *)malloc(sizeof(double)*nmax);
    }

    return mtx;
}

void mtx_free(double **mtx, int mmax){ //memory de-allocation for a matrix
    for(int m=0; m<mmax; m++){
        free(mtx[m]);
    }
    free(mtx);
}

void Vector_Copy(double *a, double *b, int nmax){ //Copy one vector to another
    for(int i=0; i< nmax; i++){
        b[i]=a[i];
    }
}

int *int_vector_malloc(int nmax){ //memory allocation for a vector with integer data 
    int *v = (int *) malloc(sizeof(int)*nmax);
    return v;

}

void Vector_APlusScaleBtoA(double *a, double *b, double c, int num_eq){//calculates A+c*B 
    for(int i = 0; i < num_eq; i++){
        a[i] =a[i] + c*b[i];
    }
    return;
}


void Vector_Clear(double *a, int num_eq){
    for (int i = 0 ; i< num_eq; i++){
        a[i] = 0; 
    }
    
    return; 
}


// #include "vector_mtx.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// //TAKEN FROM ASSIGNMENT 1

// // Here is where I define the functions declared in the Header
// // No main method in this file.


// double *vector_malloc(int nmax){
//     // grabs a memory space that can fit an array of doubles of size nmax
//     // returns a pointer to the first element of this array
//     double *pointer1; //declaring the pointer
    
//     pointer1 = (double *) malloc(sizeof(double)*nmax);
//     //pointer1 now points to the location of the first "space" in memory allocated to the vector
//     return pointer1;
    
// }

// double **mtx_malloc(int mmax, int nmax){
//     //grabs memory space that can fit the matrix (2d array).
//     // returns **pointer
//     // matrix has mmax rows and nmax columns
    
//     double **pointer;
//     //pointer is a 2d array pointing first to the first address of the row element of the matrix
//     //and secondly to the first address of the column elements of the matrix
    
//     pointer = (double **) malloc(sizeof(double*)*mmax);
//     // pointer_row1 is a pointer that is pointing to the first row vector in the matrix
//     // generate for each row a (column) array.
//     //That way, pointer_row is itself an array pointing to the first position of each column
    
//     for( int m = 0; m < mmax; m++){
//         //assign to each m value of pointer_row the location of the sub-array's first position.
//         pointer[m]=(double *) malloc(sizeof(double)*nmax);
//     }
    
//     return pointer;
// }


// void mtx_free(double **mtx, int mmax){
//     //two steps to freeing matrix:
//     //1. free up the pointers in the sub-arrays (the first "layer" of pointers):
//     for( int m = 0; m < mmax; m++){
//         free(mtx[m]);
//     }
//     //2. free the "second" layer of pointers: the pointer pointing to the rows
//     free(mtx);
    
//     // void method so no return statement
// }

// void Vector_Copy(double *a, double *b, int nmax){
//     // copy the values of array a to array b
    
//     for(int m = 0 ; m < nmax ; m++){
//         //sets b[m] to pointer that points to a[m]
//         b[m] = a[m];
//     }
//     //no return
// }

// int *int_vector_malloc(int nmax){
//     int *pointer1; //declaring the pointer as integer
    
//     pointer1 = (int *) malloc(sizeof(int)*nmax);
//     //pointer1 now points to the location of the first "space" in memory allocated to the vector
//     return pointer1;
// }

// //Two more functions needed for evolve.c: 







