#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "evolve.h"
#include "forces.h"

void Evolve(double *x, double *p){//runs advanceonestep for each time interval
    int it, it_max, choice;
    it_max = PARAM_DATA.it_max;//get values from param
    choice = PARAM_DATA.choice;
    //printf("choice = %d \n", choice);
    for(it = 0; it < it_max; it++){//loops through time and runs AdavanceOneStep each loop
        AdvanceOneStep(x, p, it, choice);
    }
    return;
}

void AdvanceOneStep(double *x, double *p, int it_now, int choice){//depending on choice runs different evolves
    double x_now, p_now, x_next, p_next;
    double v, f, h;
    h = PARAM_DATA.h;//get values from params
    int it_next;
    x_now = x[it_now];//set now to the position and momentum at it_now
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
        fprintf(stderr, "choice = %d is not yet implemented.\n", choice);//when choice value is out of range
        exit(1);//exits the program
    }
    x[it_next] = x_next;//set next to be position and momentum at it_next
    p[it_next] = p_next;
    return;
}

void OneStep(double x_now, double p_now, double x_in, double p_in, double *x_next, double *p_next, double h){//sets x and p
    double x, p;
    x = x_now + h*Velocity(p_in);//sets x given an inputed x_now, x_in
    p = p_now + h*Force(x_in);//sets p given an inputed p_now, p_in
    *x_next = x;//sets value at x_next as x
    *p_next = p;//sets value at p_next as p
    return;
}

void ForwardEulerStep(double x_now, double p_now, double *x_next, double *p_next, double h){
    double x, p; 
    x = x_now;
    p = p_now;
    OneStep(x_now, p_now, x, p, x_next, p_next, h);//runs oneStep with x and p in for p_in and x_in
    return;
}

void BackwardEulerStep(double x_now, double p_now, double *x_next, double *p_next, double h){
    double x_1, p_1, x_2, p_2;
    double err, TOL;
    int iter, iter_max;
    iter_max = 100;//max amount of iterations
    TOL = pow(10,-10);//set 
    x_1 = x_now;
    p_1 = p_now;
    for(iter = 0; iter < iter_max; iter++){//iterates through onstep with x_1 and p_2 as x_in and p_in
        OneStep(x_now, p_now, x_1, p_1, &x_2, &p_2, h);
        err = fabs(p_2-p_1)+fabs(x_2-x_1);//calculate err
        p_1 = p_2;
        x_1 = x_2;
    }
    if(err >= TOL){//when error is too large
        fprintf(stderr, "could not converge");
        exit(1);//exits the program
    }
    else{//is error is small enough update x_next and p_next
        *x_next = x_2;
        *p_next = p_2;
    }
    return;
}

void Leapfrog1Step(double x_now, double p_now, double *x_next, double *p_next, double h){
    double p_step, x_step;
    p_step = p_now + Force(x_now)*h;//defines p_step
    x_step = x_now + Velocity(p_step)*h;//defines x_step
    *x_next = x_step;//reassigns x_next and p_next
    *p_next = p_step;
    return;
}

void Leapfrog2Step(double x_now, double p_now, double *x_next, double *p_next, double h){
    double p_step, x_step;
    x_step = x_now + Velocity(p_now)*h;//defines x_step
    p_step = p_now + Force(x_step)*h;//defines p_step
    *x_next = x_step;//reassigns x_next and p_next
    *p_next = p_step;
    return;
}

