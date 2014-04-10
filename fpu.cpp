//
//  fpu.cpp
//  Strawberry Tau
//
//  Created by Alan Weide, Frank Fulajtar, and Jacob Oost on 4/5/14.
//
//

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
	double quotient= a/b;
	double remainder= a - ((int)quotient * b);
	double* answer = new double[2];
	answer[0] = quotient;
	answer[1] = remainder;
	return answer;
}

double FPU::SquareRoot(double a)
{
	double ans = 1;
	ans = sqrt(a);
	return ans;
}

double FPU::Sin(double a)
{
	double ans = 0;
	ans = sin(a);
	return ans;
}

double FPU::Exp(double a)
{
	double ans = 1;
	ans = exp(a);
	return ans;
}
