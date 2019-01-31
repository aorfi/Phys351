#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "analysis.h"

void WriteResults(double *x, double *p){
    int it, it_max;
    FILE *output;
    double t, h, x_now, p_now;
    it_max = PARAM_DATA.it_max;
    h = PARAM_DATA.h;
    output = fopen("result.dat", "w");
    for(it = 0; it < it_max; it++){
        t = h*it;
        GetXP(x, p, &x_now, &p_now, it);
        fprintf(output, "\n%e  %e %e" , t, x_now, p_now);
    }
    fclose(output);
    return;
}

void GetXP(double *x, double *p, double *x_now, double *p_now, int it){
    int choice, it_max;
    double h;
    choice = PARAM_DATA.choice;
    it_max = PARAM_DATA.it_max;
    if(choice == 3){ // Leapfrog 1. x[0] = x(h/2), p[0] = p(0)
        *p_now = p[it];// For the position, we need to go back half a step
        if(it == 0){//For it = 0, we use x_i
            *x_now = PARAM_DATA.x_i;
        }
        else{
            *x_now = (x[it-1]+x[it])/2.0; //go back half a step
        }
    }
    else if(choice == 4){ // leapfrog 2. x[0] = x(0), p[0] = p(h/2)
        *x_now = x[it];// For the mometum, we need to go back half a step
        if(it == 0){ // For it = 0 use p_i
            *p_now = PARAM_DATA.p_i;
        }
        else{//go back half a step
            *p_now = (p[it-1]+p[it])/2.0;
        }
    }
    else{// for other choices, 
        *x_now = x[it];
        *p_now = p[it];
    }
    return;
}