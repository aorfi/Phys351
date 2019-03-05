#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "evolve.h"
#include "forces.h"
#include "params.h"
#include "vector_mtx.h"
#include "rk4.h"

double GetAngle(double q);//calculates angle

void RecordAStep(FILE *output, double t_now, double *q, int num_eq);

void EvolveNeq(double *q){
    int num_eq; 
    double t_now, t_i, h, t_f, prec_goal, t_next, err, tol;
    FuncPt *QVelos; 
    double *q_next, *q_tmp;
    FILE *output;

    for(int m=0; m<=1; m++){
        PARAM_DATA.q_i[3] = 2.00 + 0.01*m;
        num_eq = PARAM_DATA.num_eq; //get values
        t_i = PARAM_DATA.t_i;
        t_f = PARAM_DATA.t_f;
        QVelos = PARAM_DATA.QVelos;
        prec_goal=PARAM_DATA.prec_goal;
        q_next = vector_malloc(num_eq);
        output = fopen("Orfi_output.dat", "w+");
        
        if(t_f < t_i){
        fprintf(stderr, "t_f is smaller than t_i");
        exit(1);//exitsif tf is larger than ti 
        }
        
        t_now=t_i; //initialize

        int i = 0;
        do{
            RecordAStep(output, t_now, q, num_eq);//writes values before starting
            h = PARAM_DATA.h; 
            do{
                err = AdaptiveRK4Step(q, q_next, QVelos, t_now, &t_next, h, num_eq); //checking the error 
                i+=3;   
                h = EstimateNextH(err, prec_goal, h); 
            } while(err > prec_goal); // continues this if err is bigger than precision goal
        
            t_now=t_next;
            Vector_Copy(q_next, q, num_eq);
            } while(t_now<=t_f);
        RecordAStep(output, t_now, q, num_eq); // record values after finishing 
        fclose(output); //closing the file 
        }
            return;
}

void RecordAStep(FILE *output, double t_now, double *q, int num_eq){//records variables
    double ang1, ang2,x1,y1,x2,y2,ene;
    ang1=GetAngle(q[0]);
    ang2=GetAngle(q[1]);

    x1= PARAM_DATA.length1*sin(ang1);//calculates positions
    y1= -1*PARAM_DATA.length1*cos(ang1);
    x2= x1+PARAM_DATA.length2*sin(ang2);
    y2= y1-PARAM_DATA.length2*cos(ang2);
    ene=TotalEnergy(q);//total energy
    fprintf(output, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n",t_now,ang1,ang2,q[2],q[3],x1,y1,x2,y2,ene);//prints values
    return;
}

double GetAngle(double q){
    double f,n;
    f=q;
    n= floor(f/(2.0*PI)); // rounds down
    f -= 2*PI*n;
    return f;
} 