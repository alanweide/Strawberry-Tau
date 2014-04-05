#include "circuit.h"

Circuit::Circuit()
{

}

void Circuit::Input(double* )
{
  
}

double* Circuit::Output(void )
{
  double foo;
  return &foo;
}

int Circuit::GetState(void )
{
  return this->state;
}

double Circuit::ReadMemory(int index)
{
  double foo;
  return foo;
}

void Circuit::WriteMemory(int index)
{
// do nothing
}
