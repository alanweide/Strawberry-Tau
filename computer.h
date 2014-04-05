#ifndef COMPUTER_H
#define COMPUTER_H

#include "circuit.h"
#include "memory.h"
#include "alu.h"
#include "fpu.h"
#include "registerfile.h"
#include <string>
#include <iostream>

class Computer:public Circuit
{
public:
  Computer();
  void Execute(string instruction);
  void PrintState(void); // prints contents of regs, mem, etc.
private:
  Memory mem;
  ALU alu;
  FPU fpu;
  RegisterFile regFile;
  string* InstructionTokenizer(string instruction);
};

#endif
