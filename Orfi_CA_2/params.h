#ifndef PARAMS_H
#define PARAMS_H

typedef struct params{
    double mass; //mass
    double x_i;  //initial position
    double p_i;  //initial momentum
    double t_i;  //initial time
    double t_f;  //final time
    int it_max;  //number of time intervals
    int choice; //algorithm choice
    double h;    //time step size
    int num_eq;  //number of first order diff equations
    double k_spring; //for SHO
}

Params;
Params PARAM_DATA; //so can be shared globally when params.h

#endif