#ifndef PARAMS_H
#define PARAMS_H

typedef struct params{
    double mass; //mass
    double x_i;  //initial position
    double p_i;  //initial momentum
    double t_i;  //initial time
    double t_f;  //final time
    int it_max;  //number of time intervals
    double h;    //time step size
    int num_eq;  //number of first order diff equations
    double k_spring; //for SHO
}

Params;
Params PARAM_DATA; //so can be shared globally when params.h

void ReadInParams(char *input_file){
    FILE *input;
    input = fopen(input_file, "r");//open file for reading
    fscanf(input, "Mass = %lf", &PARAM_DATA.mass);
    fscanf(input, "\nInitial Position = %lf", &PARAM_DATA.x_i);
    fscanf(input, "\nInitial Momentum = %lf", &PARAM_DATA.p_i);
    fscanf(input, "\nInitial Time = %lf", &PARAM_DATA.t_i);
    fscanf(input, "\nFinal Time = %lf", &PARAM_DATA.t_f);
    fscanf(input, "\nNumber of Time Intervals = %d", &PARAM_DATA.it_max);
    fscanf(input, "\nNumber of Diff Equations = %d", &PARAM_DATA.num_eq);
    fscanf(input, "\nSpring Constant = %lf", &PARAM_DATA.k_spring);
    PARAM_DATA.h = (PARAM_DATA.t_f - PARAM_DATA.t_i)/((double) PARAM_DATA.it_max);
    fclose(input);


}

void PrintParams() {
    FILE *output;
    output = fopen("InitParams.dat", "w"); //open file for writing
    fprintf(output, "Mass %lf\n" , PARAM_DATA.mass);
    fprintf(output, "Initial Position %lf\n", PARAM_DATA.x_i);
    fprintf(output, "Initial Momentum %lf\n", PARAM_DATA.p_i);
    fprintf(output, "Initial Time %lf\n", PARAM_DATA.t_i);
    fprintf(output, "Final Time %lf\n", PARAM_DATA.t_f);
    fprintf(output, "Number of Time Intervals %d\n", PARAM_DATA.it_max);
    fprintf(output, "Time Step Size %lf\n", PARAM_DATA.h);
    fprintf(output, "Number of Diff Equations %d\n", PARAM_DATA.num_eq);
    fprintf(output, "Spring Constant %lf\n", PARAM_DATA.k_spring);
    fclose(output);

}

#endif