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

Computer::Computer()
{

}

private Memory mem;
private ALU alu;
private FPU fpu;
private RegisterFile regFile;

private string* Computer::TokenizeInstruction(string instruction)
{
	return instruction;
}

void Computer::Execute(string instruction)
{
	
}

void Computer::PrintState(void)
{

}