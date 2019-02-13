#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "evolve.h"
#include "forces.h"
#include "params.h"
#include "vector_mtx.h"
#include "analysis.h"

void RecordAStep (FILE *output, double t_now, double *q, int numb_eq);

void EvolveNeq(double *q){
    int it, it_max, i, num_eq, count; 
    double t_now, t_i, h, t_f, t_next, err, tol;
    FuncPt *QVelos; 
    double *q_next, *q_tmp;
    FILE *output;

    t_i = PARAM_DATA.t_i;
    t_f = PARAM_DATA.t_f;
    h = PARAM_DATA.h;
    it_max = PARAM_DATA.it_max;
    QVelos = PARAM_DATA.QVelos;
    q_next = vector_malloc(PARAM_DATA.num_eq);//allocated memory for q
    output = fopen("Orfi_results.dat", "w"); //open file for writing, write each value
    t_now = t_i;//set this to start

    if(t_f < t_i){
        fprintf(stderr, "t_f is smaller than t_i");
        exit(1);//exits the program
    }

    for(it = 0; it < it_max; it++){
        RecordAStep(output, t_now, q, num_eq);//t_i
        RK4Step(q, q_next, QVelos, t_now, h, num_eq);
        q_tmp = q;
        q = q_next;
        q_next = q_tmp;
    }
    RecordAStep(output, t_now, q, num_eq);//t_f
    fclose(output);//close files
}

void RecordAStep (FILE *output, double t_now, double *q, int numb_eq){
    double ene; 
    ene = KineticEnergy(q);//calulate KE
    fprintf(output, "\n%e  %e %e %e" , t_now, q[0], q[1], q[2], ene);//figure out how to loop this
    return;
}

void OneStepNeq(double *q_now, double *q_in, double *q_next, FuncPt *QVelos, double t_in, double h, int num_eq){
    for(int i = 0; i < PARAM_DATA.num_eq; i++){//runs through number of equations
        q_next[i]= q_now[i] + h*(*QVelos[i])(q_in, t_in, PARAM_DATA.num_eq);//sets next value of q
    }
    return;
}

