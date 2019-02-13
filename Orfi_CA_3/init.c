#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h" 
#include "init.h"
#include "vector_mtx.h"

void ReadInParams(char *input_file){
    char str[80];
    PARAM_DATA.q_i = vector_malloc(PARAM_DATA.num_eq);
    FILE *input; // Order of reading-in: mass, x_i, p_i, t_i, t_f, it_max,choice, num_eq, k_spring
    input = fopen(input_file, "r");//open file for reading, read all values
    fscanf(input, "num_eq = %d", &PARAM_DATA.num_eq);
    

    for(int i = 0; i <= PARAM_DATA.num_eq; i++){
        fscanf(input, "\nq_i[%*c] = %lf", &PARAM_DATA.q_i[i]);
        printf("q[%d] = %lf\n",i,PARAM_DATA.q_i[i]);
      }
    printf("%d\n", PARAM_DATA.num_eq);
    printf("%lf\n", PARAM_DATA.q_i[0]);
    printf("%lf\n", PARAM_DATA.q_i[1]);
    printf("%lf\n", PARAM_DATA.q_i[2]);

    fscanf(input, "\nt_i = %lf", &PARAM_DATA.t_i);
    fscanf(input, "\nt_f = %lf", &PARAM_DATA.t_f);
    fscanf(input, "\nit_max = %d", &PARAM_DATA.it_max);
    PARAM_DATA.h = (PARAM_DATA.t_f - PARAM_DATA.t_i)/((double) PARAM_DATA.it_max);//calculate h

   
    // fscanf(input, "\nI_prin[0] = %d", (&PARAM_DATA.I_prin)[0]);
    // fscanf(input, "\nI_prin[1] = %d", (&PARAM_DATA.I_prin)[1]);
    // fscanf(input, "\nI_prin[2] = %d", (&PARAM_DATA.I_prin)[2]);
    fclose(input);//close files
    return;
}

void PrintParams(void) {
    FILE *output;// Order of reading-out: mass, x_i, p_i, t_i, t_f, it_max, num_eq, k_spring
    output = fopen("InitParams.dat", "w+"); //open file for writing, write each value
    printf("%lf", PARAM_DATA.t_i);
    //fprintf(output, "Number of Diff Equations %d\n", PARAM_DATA.num_eq);
    
    // fprintf(output, "Initial q1 %e\n", (PARAM_DATA.q_i)[0]);
    // fprintf(output, "Initial q2 %e\n", (PARAM_DATA.q_i)[1]);
    // fprintf(output, "Initial q3 %e\n", (PARAM_DATA.q_i)[2]);
    fprintf(output, "Initial Time \n");
    printf("test");
    // fprintf(output, "Final Time %e\n", PARAM_DATA.t_f);
    // fprintf(output, "Number of Time Intervals %d\n", PARAM_DATA.it_max);
    // fprintf(output, "Time Step Size %e\n", PARAM_DATA.h);
    //fprintf(output, "Initial I1 %e\n", (PARAM_DATA.I_prin)[0]);
    //fprintf(output, "Initial I2 %e\n", (PARAM_DATA.I_prin)[1]);
    //fprintf(output, "Initial I3 %e\n", (PARAM_DATA.I_prin)[2]);
    fclose(output);//close files
    return;
}

// void InitializeNeq(double *x, double *p){
  

   

//     return;
// }

