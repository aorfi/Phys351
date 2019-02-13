#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "analysis.h"

double KineticEnergy(double *q){//calulates kinetic energy
    double K = (1/2)*(PARAM_DATA.I_prin[1]*pow(q[1],2)+PARAM_DATA.I_prin[2]*pow(q[2],2)+PARAM_DATA.I_prin[0]*pow(q[0],2));
    return K;
}

