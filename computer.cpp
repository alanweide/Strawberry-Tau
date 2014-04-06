//
//  computer.cpp
//  Strawberry Tau
//
//  Created by Alan Weide on 4/5/14.
//
//

#include "computer.h"
#include "memory.h"
#include "alu.h"
#include "fpu.h"
#include "registerfile.h"
#include <string>
#include <iostream>
//#include <regex>

using namespace std;

Computer::Computer()
{
	  Memory mem = new Memory();
	  ALU alu = new ALU();
	  FPU fpu = new FPU();
	  RegisterFile regFile = new RegisterFile();
}

string* Computer::TokenizeInstruction(string instruction)
{
	return instruction;
}

void Computer::Execute(string instruction)
{
	
}

void Computer::PrintState(void)
{

}
