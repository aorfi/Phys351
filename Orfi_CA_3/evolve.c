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
    output = fopen("Orfi_results.dat", "w"); //open file for writing, write each value
    printf("test1\n");
    
    num_eq = PARAM_DATA.num_eq;
    t_i = PARAM_DATA.t_i;
    t_f = PARAM_DATA.t_f;
    h = PARAM_DATA.h;
    it_max = PARAM_DATA.it_max;
    QVelos = PARAM_DATA.QVelos;
    q_next = vector_malloc(PARAM_DATA.num_eq);//allocated memory for q
       
    t_now = t_i;//set this to start
    printf("test2\n");
    

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
        t_now = t_now+h;
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
    for(int i = 0; i < num_eq; i++){//runs through number of equations
        q_next[i]= q_now[i] + h*(*QVelos[i])(q_in, t_in, num_eq);//sets next value of q
    }
    return;
}

void RK4Step(double *q, double *q_next, FuncPt *QVelos, double t_now, double h, int num_eq){
    int n;
    double t_half, t_next; 
    static int ind = 0;
    static double *q_local, *q_sum;
    ind++;
    if(ind == 1){//first time function is called
        q_local = vector_malloc(num_eq);
        q_sum = vector_malloc(num_eq);
    }
    t_half = t_now + h/2;
    t_next = t_now + h;
    Vector_Clear(q_sum, num_eq);
    OneStepNeq(q, q, q_local, QVelos, t_now, 0.5*h, num_eq);//RK fist step
    Vector_APlusScaledBtoA(q_sum, q_local, 1.0/3.0, num_eq);//add 1/3 of the first vector to q_sum
    
    OneStepNeq(q, q_local, q_next, QVelos, t_half, 0.5*h, num_eq);//RK second step
    Vector_APlusScaledBtoA(q_sum, q_next, 2.0/3.0, num_eq);//add 2/3 of the second vector to q_sum
    
    OneStepNeq(q, q_next, q_local, QVelos, t_half, h, num_eq);//RK third step
    Vector_APlusScaledBtoA(q_sum, q_local, 2.0/3.0, num_eq);//add 1/3 of the third vector to q_sum
   
    OneStepNeq(q, q_local, q_next, QVelos, t_next, h, num_eq);//RK fourth step
    Vector_APlusScaledBtoA(q_sum, q_next, 2.0/3.0, num_eq);//add 1/6 of the fourth vector to q_sum

    Vector_APlusScaledBtoA(q_sum, q, -1.0/2.0, num_eq);//add -1/2 of q to q_sum

    Vector_Copy(q_sum, q_next, num_eq);
    return;
}