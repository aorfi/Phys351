#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_mtx.h"

double *vector_malloc(int nmax){
    double *v = (double *) malloc(sizeof(double)*nmax);
    return v; 
}
double **mtx_malloc(int mmax, int nmax){
    double **mtx;
    int m,n;
    mtx = (double **) malloc(sizeof(double) *nmax);
   for(m=0; m<=mmax; m++)
   {
       mtx[m] = (double *)malloc(sizeof(double)*nmax);
   } 
   for(m=0; m<=mmax; m++){
       for(n=0; n<=nmax; n++){
           mtx[m][n]= 0.0;
        }
   }
   return mtx;
}
void mtx_free(double **mtx, int mmax){
    for(int m=0; m<=mmax; m++)
    {
        free(mtx[m]);
    }
    free(mtx); 
}
void Vector_Copy(double *a, double *b, int nmax){ //Copy one vector to another
    for(int i=0; i< nmax; i++){
        b[i]=a[i];
    }
}
 
int *int_vector_malloc(int nmax){
    int *v = (int *) malloc(sizeof(int)*nmax);
    return v;
} 

void Vector_APlusScaledBtoA(double *a, double *b, double c, int num_eq){
    double temp;
    for(int i=0; i< num_eq; i++){
        temp=a[i] + c*b[i]; 
        a[i]=temp;
    }
    return; 
}

void Vector_Clear(double *a, int num_eq){
   for(int i=0; i< num_eq; i++){
        a[i]=0; 
   }
   return;
}

double Vector_Distance(double *a, double *b, int num_elems){//gets distance between vectors
    double temp,d;
    d=0;
    for(int i=0; i< (num_elems); i++){ 
        temp= pow((a[i]-b[i]),2);
        d += temp;
    }
    d=pow(d,0.5); 
    return d; 
}
