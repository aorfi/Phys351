#ifndef PARAMS_H
#define PARAMS_H

typedef double (*FuncPt)(double *q, double t, int num_elems);//defines function type

typedef struct neq_params{
    int num_eq;  //number of first order diff equations
    double *q_i; //intial values for dynamic variables
    double t_i;  //initial time
    double t_f;  //final time
    int it_max;  //number of time intervals
    double h;    //time step size
    double *I_prin; //initial values for inertia tensor

    FuncPt *QVelos;
    
}

NeqParams;
NeqParams PARAM_DATA; //so can be shared globally when params.h

#endif