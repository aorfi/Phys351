#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_mtx.h" // vector and matrix utility functions
#include "params.h" // parameter definitions
#include "init.h" // initialization functions
#include "evolve.h" // time evolution
#include "analysis.h" // analyze the results

int main(int argc, char **argv){
    printf("test0");
    char *input_file; //input file name
    double *x,*p;
    
    input_file = argv[1]; //input from terminal (index 1)
    ReadInParams(input_file); //uses ReadInParams to interpret input data
    //PrintParams();//Prints params
    printf("test1");

    x = vector_malloc(PARAM_DATA.it_max + 1); //allocates for number of time intervals +1
    p = vector_malloc(PARAM_DATA.it_max + 1); 
    printf("test2");

    Initialize(x,p);//initalizes both vecotrs
    printf("test3");

    Evolve(x,p);
    printf("test4");
    WriteResults(x,p);

    return 0;
}