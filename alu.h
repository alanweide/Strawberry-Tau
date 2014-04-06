#ifndef ALU_H
#define ALU_H

#include "circuit.h"

class ALU:public Circuit
{
public:
  ALU();
  int Add(int a, int b); // a+b
  int Subtract(int a, int b); // a-b
  int Multiply(int a, int b); // a*b
  int* Divide(int a, int b); // returns array containing quotient and remainder
private:
  // ?
};

// aos;dofjaidl

#endif
