#ifndef VECTOR_MTX_H //make sure header is included only once
#define VECTOR_MTX_H 
//calls vector_malloc, mtx_malloc, mtx_free, CopyVector, int_vector_malloc, Vector_APlusScaledBtoA,Vector_Clear


double *vector_malloc(int nmax);//vector allocation

double **mtx_malloc(int mmax, int nmax);//matrix allocation

void mtx_free(double **mtx, int mmax); //matrix memory de-allocation

void Vector_Copy(double *a, double *b, int nmax); //copy a to b

int *int_vector_malloc(int nmax); //integer vector allocation

void Vector_APlusScaledBtoA(double *a, double *b, double c, int num_eq);//calculates A+c*B 

void Vector_Clear(double *a, int num_eq);//clears 

#endif