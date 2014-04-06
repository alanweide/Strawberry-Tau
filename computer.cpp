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

Computer::Computer()
{
	
}

private Memory mem;
private ALU alu;
private FPU fpu;
private RegisterFile regFile;

private string* InstructionTokenizer(string instruction)
{
	string ans;
	return ans;
}

void Execute(string instruction)
{
	
}

void PrintState(void)
{
	
}