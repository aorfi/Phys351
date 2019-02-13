#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "params.h"
#include "forces.h"

double QVelo0(double *q, double t, int num_elems){ //defines the velocity function
    double f;
    double q_1 = *(q+1);
    double q_2 = *(q+2);
    f = (q_1)*(q_2)*(PARAM_DATA.I_prin[1]-PARAM_DATA.I_prin[2])/(PARAM_DATA.I_prin[0]);
    return f;
}

double QVelo1(double *q, double t, int num_elems){ //defines the velocity function
    double f;
    double q_2 = *(q+2);
    double q_3 = *(q);
    f = (q_2)*(q_3)*(PARAM_DATA.I_prin[2]-PARAM_DATA.I_prin[0])/(PARAM_DATA.I_prin[1]);
    return f;
}

double QVelo2(double *q, double t, int num_elems){ //defines the velocity function
    double f;
    double q_1 = *(q);
    double q_3 = *(q+2);
    f = (q_1)*(q_3)*(PARAM_DATA.I_prin[0]-PARAM_DATA.I_prin[1])/(PARAM_DATA.I_prin[2]);
    return f;
}

