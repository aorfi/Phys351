#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "params.h"
#include "analysis.h"

void WriteResults(double *x, double *p){//defines function to write the results
    int it, it_max;
    FILE *output;
    double t, h, x_now, p_now;
    it_max = PARAM_DATA.it_max;//get values from params
    h = PARAM_DATA.h;
    output = fopen("result.dat", "w");//set output file as result.dat
    for(it = 0; it < it_max; it++){//for each time print t, x_now, and p_now
        t = h*it;
        GetXP(x, p, &x_now, &p_now, it);//use GetXP to get the values of x and p for each evolve types
        fprintf(output, "\n%e  %e %e" , t, x_now, p_now);
    }
    fclose(output);
    return;
}

void GetXP(double *x, double *p, double *x_now, double *p_now, int it){//gets values of x and p 
    int choice, it_max;
    double h;
    choice = PARAM_DATA.choice;//get values from params
    it_max = PARAM_DATA.it_max;
    if(choice == 3){ // for Leapfrog 1, need to go back half a step for position
        *p_now = p[it];
        if(it == 0){//For it = 0, we use x_i
            *x_now = PARAM_DATA.x_i;
        }
        else{
            *x_now = (x[it-1]+x[it])/2.0; //go back half a step and get the value there
        }
    }
    else if(choice == 4){ // for Leapfrog 2, need to go back half a step for momentum
        *x_now = x[it];
        if(it == 0){ // For it = 0 use p_i
            *p_now = PARAM_DATA.p_i;
        }
        else{
            *p_now = (p[it-1]+p[it])/2.0; //go back half a step and get the value there
        }
    }
    else{// for other choices, 
        *x_now = x[it];
        *p_now = p[it];
    }
    return;
}