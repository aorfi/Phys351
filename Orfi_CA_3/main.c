#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "vector_mtx.h"
#include "init.h"
#include "forces.h"
#include "evolve.h"
#include "analysis.h"

int main(int argc, char **argv){
    char *input_file;
    double *q;
    double t_i, t_f;
    input_file = argv[1]; //gets input file from terminal


    ReadInParams(input_file); //gets parameters from input file
    PrintParams();//prints parameters

    q = vector_malloc(PARAM_DATA.num_eq);//allocated memory for q

    InitializeNeq(q);

    EvolveNeq(q);

    return 0;
}
