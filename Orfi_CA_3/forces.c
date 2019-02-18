#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "params.h"
#include "forces.h"

double QVelo0(double *q, double t, int num_elems){ //defines the velocity function
    double f;
    double I1 = PARAM_DATA.I_prin[1]; //get I parameters
    double I2 = PARAM_DATA.I_prin[2]; 
    double I3 = PARAM_DATA.I_prin[0];
    double q_1 = *(q+1);//get the correct value of q
    double q_2 = *(q+2);
    f = ((I1-I2)/I3)*q_1*q_2; //calculate force
    return f;
}

double QVelo1(double *q, double t, int num_elems){ //defines the velocity function
    double f;
    double I1 = PARAM_DATA.I_prin[1]; //get I parameters
    double I2 = PARAM_DATA.I_prin[2]; 
    double I3 = PARAM_DATA.I_prin[0];
    double q_2 = *(q+2);//get the correct value of q
    double q_3 = *q;
    f = ((I2-I3)/I1)*q_2*q_3; //calculate force
    return f;
}

double QVelo2(double *q, double t, int num_elems){ //defines the velocity function
    double f;
    double I1 = PARAM_DATA.I_prin[1]; //get I parameters
    double I2 = PARAM_DATA.I_prin[2]; 
    double I3 = PARAM_DATA.I_prin[0];
    double q_1 = *(q+1);//get the correct value of q
    double q_3 = *q;
    f = ((I3-I1)/I2)*q_3*q_1; //calculate force
    return f;
}

