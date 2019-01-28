#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "params.h"
#include "forces.h"

double Velocity(double p){ //defines the velocity function
    double v,mass;
    mass = PARAM_DATA.mass;
    v = p/mass;
    return v;
}

double Force(double x){ //defines the force function
    double f,k;
    k = PARAM_DATA.k_spring;
    f = -1.0*k*x;
    return f;
}