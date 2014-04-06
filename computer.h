#ifndef COMPUTER_H
#define COMPUTER_H

#include "memory.h"
#include "alu.h"
#include "fpu.h"
#include "registerfile.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;

using namespace std;

class Computer
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
	string* TokenizeInstruction(string instruction);
};

#endif
