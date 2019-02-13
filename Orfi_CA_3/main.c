#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_mtx.h"
#include "params.h" // parameter definitions
#include "init.h" // initialization functions
#include "evolve.h" // time evolution

int main(int argc, char **argv){
    char *input_file;
    double *q;
    double t_i, t_f;
    input_file = argv[1]; //gets input file from terminal


    ReadInParams(input_file); //gets parameters from input file
    //printf("hello1\n");
    PrintParams();//prints parameters
    //printf("hello2\n");

   // q = vector_malloc(PARAM_DATA.num_eq);//allocated memory for q

    //InitializeNeq(q);

    //EvolveNew(q);

    return 0;
}
