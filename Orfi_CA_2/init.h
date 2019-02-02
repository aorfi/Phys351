#ifndef INIT_H
#define INIT_H
#include "params.h"
//calls ReadInParams, PrintParams and Initialize 

void ReadInParams(char *input_file);//read params from input_file
void PrintParams(void);
void Initialize(double *x, double *p);

#endif