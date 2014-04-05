#ifndef FPU_H
#define FPU_H

#include "circuit.h"

class FPU:public Circuit
{
public:
  FPU();
  double Add(double a, double b);
  double Subtract(double a, double b);
  double Multiply(double a, double b);
  double Divide(double a, double b);
  double SquareRoot(double a);
  double Sin(double a);
  double Exp(double a);
private:
};

#endif
