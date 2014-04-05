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
	double quotient=a/b;
	double remainder=a%b;
	double answer[2]={quotient,remainder};
	return answer;
}

double FPU::SquareRoot(double a)
{
	// implement Taylor series for square root
}

double FPU::Sin(double a)
{
	// implement Taylor series for Sine
}

double FPU::Exp(double a)
{
	// implement Taylor series for Exponent
}