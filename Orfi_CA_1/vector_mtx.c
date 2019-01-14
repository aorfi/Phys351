#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "vector_mtx.h"

double *vector_malloc(int nmax){
    double *v;
    v = (double *) malloc(sizeof(double)*nmax);
    return v;
}

double **mtx_malloc(int mmax, int nmax){
    double **mtx;
    int m,n;
    mtx = (double**)malloc(sizeof(double*)*mmax);
    
    for(m=0;m<=mmax;m++){
        mtx[m] = (double *)malloc(sizeof(double)*nmax);
    }

    // for(m=0;m<mmax;m++){
    //     for(n=0;n<nmax;n++){
    //         mtx[m][n] = 0.0;
    //     }
    // }
    return mtx;
}

void mtx_free(double **mtx, int mmax){
    for(int m=0; m<=mmax; m++){
        free(mtx[m]);
    }
    free(mtx);
}

void CopyVector(double *a, double *b, int nmax){
    for(int i=0; i<=nmax; i++){
        a[i]=b[i];
    }
}

int *int_vector_malloc(int nmax){
    int *v = (int *) malloc(sizeof(int)*nmax);
    return v;

}




