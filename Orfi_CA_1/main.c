#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_mtx.h"
#include "params.h"

int main(int argc, char **argv){ //imputs information from compiler 
    char *input_file;
    input_file = argv[1];  //first file name written 
    ReadInParams(input_file);
    PrintParams();
    return 1;
}