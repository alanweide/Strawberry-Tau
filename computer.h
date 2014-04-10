//
//  computer.h
//  Strawberry Tau
//
//  Created by Alan Weide, Frank Fulajtar, and Jacob Oost on 4/5/14.
//
//

#ifndef COMPUTER_H
#define COMPUTER_H

#include "memory.h"
#include "alu.h"
#include "fpu.h"
#include "registerfile.h"
#include <string>
#include <iostream>
#include <regex>
#include <stdlib.h>

using namespace std;

class Computer
{
public:
	Computer();
	void Execute(string instruction);
	void PrintState(void); // prints contents of registers
private:
	Memory mem;
	ALU alu;
	FPU fpu;
	RegisterFile regFile;
	string* TokenizeInstruction(string instruction);
};

#endif
