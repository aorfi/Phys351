#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "forces.h" 
#include "params.h" 
#include "init.h"

void ReadInParams(char *input_file){
    FILE *input; // Order of reading-in: mass, x_i, p_i, t_i, t_f, it_max,choice, num_eq, k_spring
    input = fopen(input_file, "r");//open file for reading, read all values
    fscanf(input, "mass = %lf", &PARAM_DATA.mass);
    fscanf(input, "\nx_i = %lf", &PARAM_DATA.x_i);
    fscanf(input, "\np_i = %lf", &PARAM_DATA.p_i);
    fscanf(input, "\nt_i = %lf", &PARAM_DATA.t_i);
    fscanf(input, "\nt_f = %lf", &PARAM_DATA.t_f);
    fscanf(input, "\nit_max = %d", &PARAM_DATA.it_max);
    fscanf(input, "\nchoice = %d", &PARAM_DATA.choice);
    fscanf(input, "\nnum_eq = %d", &PARAM_DATA.num_eq);
    fscanf(input, "\nspring const k = %lf", &PARAM_DATA.k_spring);
    PARAM_DATA.h = (PARAM_DATA.t_f - PARAM_DATA.t_i)/((double) PARAM_DATA.it_max);//calculate h
    fclose(input);//close files
    return;
}

void PrintParams(void) {
    FILE *output;// Order of reading-out: mass, x_i, p_i, t_i, t_f, it_max, num_eq, k_spring
    output = fopen("InitParams.dat", "w"); //open file for writing, write each value
    fprintf(output, "Mass %e\n" , PARAM_DATA.mass);
    fprintf(output, "Initial Position %e\n", PARAM_DATA.x_i);
    fprintf(output, "Initial Momentum %e\n", PARAM_DATA.p_i);
    fprintf(output, "Initial Time %e\n", PARAM_DATA.t_i);
    fprintf(output, "Final Time %e\n", PARAM_DATA.t_f);
    fprintf(output, "Number of Time Intervals %d\n", PARAM_DATA.it_max);
    fprintf(output, "Time Step Size %e\n", PARAM_DATA.h);
    fprintf(output, "Choice %d\n", PARAM_DATA.choice);
    fprintf(output, "Number of Diff Equations %d\n", PARAM_DATA.num_eq);
    fprintf(output, "Spring Constant %e\n", PARAM_DATA.k_spring);
    fclose(output);//close files
    return;
}

void Initialize(double *x, double *p){
    double x_i, p_i, h;
    int choice;
    x_i = PARAM_DATA.x_i; //get values from params
    p_i = PARAM_DATA.p_i; 
    h = PARAM_DATA.h;
    choice = PARAM_DATA.choice;
    if(choice == 3){//for Leapfrong 1 set inital values of p and x
        p[0] = p_i;
        x[0] = x_i + (h/2.0)*Velocity(p_i);
    }
    else if(choice == 4){//for Leapfrong 2 set inital values of p and x
        x[0] = x_i;
        p[0] = p_i + (h/2.0)*Force(x_i);
    }
    else{//runs for all other choices
        x[0] = x_i;
        p[0] = p_i;
    }
    return;
}

