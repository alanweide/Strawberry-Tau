#ifndef FPU_H
#define FPU_H

#include <cmath>

class FPU
{
public:
	FPU();
	double Add(double a, double b);
	double Subtract(double a, double b);
	double Multiply(double a, double b);
	double* Divide(double a, double b);
	double SquareRoot(double a);
	double Sin(double a);
	double Exp(double a, double b);
};

#endif
