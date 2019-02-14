#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "analysis.h"

double KineticEnergy(double *q){//calulates kinetic energy
    double k, I1, I2, I3 , q1, q2, q3; 
    I1 = PARAM_DATA.I_prin[1];
    I2 = PARAM_DATA.I_prin[2];
    I3 = PARAM_DATA.I_prin[0];

    q1 = q[1];
    q2 = q[2];
    q3 = q[0]; 

    k = (0.5)*( I1 * pow(q1,2) + I2 * pow(q2,2) + I3 * pow(q3,2));
    return k;
}

