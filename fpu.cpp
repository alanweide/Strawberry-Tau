#include "fpu.h"

FPU::FPU()
{

}

double FPU::Add(double a, double b)
{
	return a+b;
}

double FPU::Subtract(double a, double b)
{
	return a-b;
}

double FPU::Multiply(double a, double b)
{
	return a*b;
}

double* FPU::Divide(double a, double b)
{
	double quotient=a/b;;
	return quotient;
}

double FPU::SquareRoot(double a)
{
	double ans;
	// implement Taylor series for square root
	return ans;
}

double FPU::Sin(double a)
{
	double ans;
	// implement Taylor series for Sine
	return ans;
}

double FPU::Exp(double a)
{
	double ans;
	// implement Taylor series for Exponent
	return ans;
}
