#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "evolve.h"
#include "forces.h"

void Evolve(double *x, double *p){//runs advanceonestep for each time interval
    int it, it_max, choice;
    //double  x_test, p_test;
    // x_test = *x;
    // p_test = *p;
    it_max = PARAM_DATA.it_max;
    choice = PARAM_DATA.choice;
    printf("choice = %d \n", choice);
    for(it = 0; it < it_max; it++){
        AdvanceOneStep(x, p, it, choice);
    }
    return;
}

void AdvanceOneStep(double *x, double *p, int it_now, int choice){//depending on choice runs different evolves
    double x_now, p_now, x_next, p_next;
    double v, f, h;
    h = PARAM_DATA.h;
    int it_next;
    x_now = x[it_now];
    p_now = p[it_now];
    it_next = it_now +1;
    if(choice == 1){//Forward Euler
        ForwardEulerStep(x_now, p_now, &x_next, &p_next,h);
    }
    else if(choice == 2){//Backward Euler
        BackwardEulerStep(x_now, p_now, &x_next, &p_next,h);
    }
    else if(choice == 3){//Leapfrog 1
        Leapfrog1Step(x_now, p_now, &x_next, &p_next, h);
    }
    else if(choice == 4){ // Leapfrog 2
        Leapfrog2Step(x_now, p_now, &x_next, &p_next, h);
    }
    else{
        fprintf(stderr, "choice = %d is not yet implemented.\n", choice);
        exit(1);//exits the program
    }
    x[it_next] = x_next;
    p[it_next] = p_next;
    return;
}

void OneStep(double x_now, double p_now, double x_in, double p_in, double *x_next, double *p_next, double h){
    double x, p;
    x = x_now + h*Velocity(p_in);
    p = p_now + h*Force(x_in);
    *x_next = x;
    *p_next = p;
    return;
}

void ForwardEulerStep(double x_now, double p_now, double *x_next, double *p_next, double h){
    double x, p; 
    x = x_now;
    p = p_now;
    OneStep(x_now, p_now, x, p, x_next, p_next, h);
    return;
}

void BackwardEulerStep(double x_now, double p_now, double *x_next, double *p_next, double h){
    double x_1, p_1, x_2, p_2;
    double err, TOL;
    int iter, iter_max;
    iter_max = 100;
    TOL = 10^(-10);
    x_1 = x_now;
    p_1 = p_now;
    for(iter = 0; iter < iter_max; iter++){
        OneStep(x_now, p_now, x_1, p_1, &x_2, &p_2, h);
        err = fabs(p_2-p_1)+fabs(x_2-x_1);
        if(err < TOL){
            break;
        }
        p_1 = p_2;
        x_1 = x_2;
        if(err >= TOL){
        fprintf(stderr, "could not converge");
        exit(1);//exits the program
        }
        else{
        *x_next = x_2;
        *p_next = p_2;
        }
    }
    return;
}

void Leapfrog1Step(double x_now, double p_now, double *x_next, double *p_next, double h){
    double p_step, x_step;
    p_step = p_now + Force(x_now)*h;
    x_step = x_now + Velocity(p_step)*h;
    *x_next = x_step;
    *p_next = p_step;
    return;
}

void Leapfrog2Step(double x_now, double p_now, double *x_next, double *p_next, double h){
    double p_step, x_step;
    p_step = p_now + Force(x_step)*h;
    x_step = x_now + Velocity(p_now)*h;
    *x_next = x_step;
    *p_next = p_step;
    return;
}

