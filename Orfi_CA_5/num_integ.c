#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "num_integ.h"

#define error_handler(tag) { printf(tag); exit(0);}//defined error handler


double test_func(double x); //to test
int TestNumInteg();

double NumIntegrate (double *f, double h, int down, int up, int nmax){
    int tmp; 
    double sum;

    if(up > nmax || down > nmax) error_handler("up or down is larger than nmax ") //exits 
    if(up < 0 || down < 0) error_handler("up or down is less than zero ")

    if(down > up){//switched sign of integral
        tmp = up;
        up = down;
        down = tmp;
        h = -h;
    }

    if(up == down){
        return 0; 
    }
    else if(up == down +1){ //single interval
        sum = f[down] + f[down +1];
        sum *= h/2.0;
    }
    else if(up == down +2){ // 2 intervals (Simpson's Rule)
        sum = f[down] + 4*f[down +1] + f[down +2];
        sum *= h/3.0;
    }
    else if(up == down +3){ // 3 intervals (simpson's 3/8 rule)
        sum = 3*f[down] + 9*f[down +1] + 9*f[down +2] + 3*f[down +3];
        sum *= h/8.0;
    }
    else if(up == down +4){ // 4 intervals (Boole's rule)
        sum = 14*f[down] + 64*f[down +1] + 24*f[down +2] + 64*f[down +3] +14*f[down +4];
        sum *= h/45.0;
    }
    else if(up == down +5){ // 5 intervals (6 point rule)
        sum = 19*f[down] + 75*f[down +1] + 50*f[down +2] + 50*f[down +3] +75*f[down +4]+19*f[down +5];
        sum *= 5*h/45.0;
    }
    else { // more than 6 points
        sum = (3/8.0)*f[down] + (7/6.0)*f[down +1] + (23/24.0)*f[down +2] + (23/24.0)*f[down +(nmax -2)] + (7/6.0)*f[down +(nmax-1)]+ (3/8.0)*f[down + nmax];
        for(int i = 3; i < (nmax -3); i++){
            sum += f[down +i];
        }
        sum *= h; 
    }
}



int main(){
    NumIntegrate(3,4,2,3,2);
}