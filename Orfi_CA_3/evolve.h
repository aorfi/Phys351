#ifndef EVOLVE_H
#define EVOLVE_H

void EvolveNeq(double *q);

void OneStepNeq(double *q_now, double *q_in, double *q_next, FuncPt *QVelos, double t_in, double h, int num_eq);

#endif