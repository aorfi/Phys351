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
    int m,n;
    mtx = (double**)malloc(sizeof(double*)*mmax);
    
    for(m=0;m<=mmax;m++){
        mtx[m] = (double *)malloc(sizeof(double)*nmax);
    }

    return mtx;
}

void mtx_free(double **mtx, int mmax){ //memory de-allocation for a matrix
    for(int m=0; m<=mmax; m++){
        free(mtx[m]);
    }
    free(mtx);
}

void CopyVector(double *a, double *b, int nmax){ //Copy one vector to another
    for(int i=0; i<=nmax; i++){
        a[i]=b[i];
    }
}

int *int_vector_malloc(int nmax){ //memory allocation for a vector with integer data 
    int *v = (int *) malloc(sizeof(int)*nmax);
    return v;

}




