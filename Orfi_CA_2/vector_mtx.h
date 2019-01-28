#ifndef VECTOR_MTX_H //make sure header is included only once
#define VECTOR_MTX_H 


double *vector_malloc(int nmax);//vector allocation

double **mtx_malloc(int mmax, int nmax);//matrix allocation

void mtx_free(double **mtx, int mmax); //matrix memory de-allocation

void CopyVector(double *a, double *b, int nmax); //copy a to b

int *int_vector_malloc(int nmax); //integer vector allocation

#endif