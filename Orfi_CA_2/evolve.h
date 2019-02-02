#ifndef EVOLVE_H
#define EVOLVE_H
//calls AdvanceOneStep, OneStep, ForwardEulerStep, BackwardEulerStep, Leapfrog1Step, Leapfrog2Step

void AdvanceOneStep(double *x, double *p, int it_now, int choice);
void OneStep(double x_now, double p_now, double x_in, double p_in, double *x_next, double *p_next, double h);

void ForwardEulerStep(double x_now, double p_now, double *x_next, double *p_next, double h);
void BackwardEulerStep(double x_now, double p_now, double *x_next, double *p_next, double h);

void Leapfrog1Step(double x_now, double p_now, double *x_next, double *p_next, double h);
void Leapfrog2Step(double x_now, double p_now, double *x_next, double *p_next, double h);

// void VelocityVerletStep(double x_now, double p_now, double *x_next, double *p_next, double h);
// void PositionVerletStep(double x_now, double p_now, double *x_next, double *p_next, double h);
// void HeunStep(double x_now, double p_now, double *x_next, double *p_next, double h);
// void Heun3Step(double x_now, double p_now, double *x_next, double *p_next, double h);
// void RK4Step(double x_now, double p_now, double *x_next, double *p_next, double h);
// void RuthForestStep(double x_now, double p_now, double *x_next, double *p_next, double h);
// void PEFRLStep(double x_now, double p_now, double *x_next, double *p_next, double h);
// int OneStepWithErr(double x_now, double p_now, double *x_next, double *p_next,double *h_next, double h);
// void AdaptiveVerletStep(double x_now, double p_now, double *x_next, double *p_next, double h);
#endif