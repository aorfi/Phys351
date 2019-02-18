#ifndef EVOLVE_H
#define EVOLVE_H
#include "params.h"
//calls evolveNeq OneStepNeq RK4Step

void EvolveNeq(double *q);

void OneStepNeq(double *q_now, double *q_in, double *q_next, FuncPt *QVelos, double t_in, double h, int num_eq);

void RK4Step(double *q, double *q_next, FuncPt *QVelos, double t_now, double h, int num_eq);
#endif