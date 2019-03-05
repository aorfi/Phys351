#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "vector_mtx.h"
#include "init.h"
#include "evolve.h"
int main(int argc, char **argv){
    char *input; 
    double *q;
    double t_i,t_f; 
    input = argv[1];


    ReadInParams(input); 
    PrintParams();

    q=vector_malloc(PARAM_DATA.num_eq); // alocating space for q

    InitializeNeq(q);
    EvolveNeq(q);
    return 0;}