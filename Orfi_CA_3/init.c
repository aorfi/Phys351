#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "forces.h"
#include "init.h"
#include "vector_mtx.h"

void ReadInParams(char *input_file){
    FILE *input; // Order of reading-in: mass, x_i, p_i, t_i, t_f, it_max,choice, num_eq, k_spring
    input = fopen(input_file, "r");//open file for reading, read all values
    fscanf(input, "num_eq = %d", &PARAM_DATA.num_eq);//get value for number of equations
    PARAM_DATA.q_i = vector_malloc(PARAM_DATA.num_eq);//assigns memory for the q_i vector
    PARAM_DATA.I_prin = vector_malloc(PARAM_DATA.num_eq);//assigns memory for the I_prin vector

    for(int i = 0; i < PARAM_DATA.num_eq; i++){//assigns each q_i value
        fscanf(input, "\nq_i[%*c] = %lf", &PARAM_DATA.q_i[i]);
      }

    for(int i = 0; i < PARAM_DATA.num_eq; i++){//assigns each I_prin value
        fscanf(input, "\nI_prin[%*c] = %lf", &PARAM_DATA.I_prin[i]);
      }

    fscanf(input, "\nt_i = %lf", &PARAM_DATA.t_i);//assigns the rest of the variables
    fscanf(input, "\nt_f = %lf", &PARAM_DATA.t_f);
    fscanf(input, "\nit_max = %d", &PARAM_DATA.it_max);
    fscanf(input, "\nh = %lf", &PARAM_DATA.h);
    fclose(input);//close files
    return;
}

void PrintParams(void) {
    FILE *output;// Order of reading-out: mass, x_i, p_i, t_i, t_f, it_max, num_eq, k_spring
    output = fopen("InitParams.dat", "w"); //open file for writing, write each value
    fprintf(output, "Number of Diff Equations %d\n", PARAM_DATA.num_eq);
    fprintf(output, "Initial q1 %e\n", (PARAM_DATA.q_i)[0]);
    fprintf(output, "Initial q2 %e\n", (PARAM_DATA.q_i)[1]);
    fprintf(output, "Initial q3 %e\n", (PARAM_DATA.q_i)[2]);
    fprintf(output, "Initial Time %e\n", PARAM_DATA.t_i);
    fprintf(output, "Final Time %e\n", PARAM_DATA.t_f);
    fprintf(output, "Number of Time Intervals %d\n", PARAM_DATA.it_max);
    fprintf(output, "Time Step Size %e\n", PARAM_DATA.h);
    fprintf(output, "Initial I1 %e\n", (PARAM_DATA.I_prin)[0]);
    fprintf(output, "Initial I2 %e\n", (PARAM_DATA.I_prin)[1]);
    fprintf(output, "Initial I3 %e\n", (PARAM_DATA.I_prin)[2]);
    fclose(output);//close files
    return;
}

 void InitializeNeq(double *q){
    for(int i = 0; i < PARAM_DATA.num_eq; i++){//assigns each q_i value
        q[i] = PARAM_DATA.q_i[i];  
      }
    PARAM_DATA.QVelos = (FuncPt *)malloc(sizeof(FuncPt)*PARAM_DATA.num_eq);
    PARAM_DATA.QVelos[0] = QVelo0;
    PARAM_DATA.QVelos[1] = QVelo1;
    PARAM_DATA.QVelos[2] = QVelo2;
     return;
 }
