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
#include <regex>

using namespace std;

enum mnemonic {
	add,
	addi,
	sub,
	subi,
	mul,
	muli,
	divd,
	divi,
	fadd,
	faddi,
	fsub,
	fsubi,
	fmul,
	fmuli,
	fdiv,
	fdivi,
	sqrt,
	sin,
	exp,
	expi,
	memld,
	memst,
	regld,
	regst,
	nop
};

Computer::Computer()
{
	  Memory* mem = new Memory();
	  ALU* alu = new ALU();
	  FPU* fpu = new FPU();
	  RegisterFile* regFile = new RegisterFile();
}

mnemonic mnemonify (string mnem) {
	if (mnem == "add") {
		return add;
	} else if (mnem == "addi") {
		return addi;
	} else if (mnem == "sub") {
		return sub;
	} else if (mnem == "subi") {
		return subi;
	} else if (mnem == "mul") {
		return mul;
	} else if (mnem == "muli") {
		return muli;
	} else if (mnem == "div") {
		return divd;
	} else if (mnem == "divi") {
		return divi;
	} else if (mnem == "fadd") {
		return fadd;
	} else if (mnem == "faddi") {
		return faddi;
	} else if (mnem == "fsub") {
		return fsub;
	} else if (mnem == "fsubi") {
		return fsubi;
	} else if (mnem == "fmul") {
		return fmul;
	} else if (mnem == "fmuli") {
		return fmuli;
	} else if (mnem == "fdiv") {
		return fdiv;
	} else if (mnem == "fdivi") {
		return fdivi;
	} else if (mnem == "sqrt") {
		return sqrt;
	} else if (mnem == "sin") {
		return sin;
	} else if (mnem == "exp") {
		return exp;
	} else if (mnem == "expi") {
		return expi;
	} else if (mnem == "memld") {
		return memld;
	} else if (mnem == "memst") {
		return memst;
	} else if (mnem == "regld") {
		return regld;
	} else if (mnem == "regst") {
		return regst;
	} else {
		return nop;
	}
}

string* Computer::TokenizeInstruction(string instruction)
{
	cmatch cmTokens;
	string* tokens;
	regex instRx("(\w)+\s+(reg\d\d)\s+(reg\d\d)\s*(\w*)($|)");
	regex_search(instruction.c_str(),
			cmTokens,
			instRx,
			regex_constants::match_default);
	for (int i = 0; i < cmTokens.length(); i++) {
		tokens[i] = cmTokens[i];
	}
	return tokens;
}

void Computer::Execute(string instruction)
{
	string* tokens = TokenizeInstruction (instruction);
	long output[3]; // long values of argument registers after execution

	// convert strings to char* for output in printf statement
	// Is there a better way to do this?
	char* inst = strdup(tokens[0].c_str());
	char* args[3] = {
						strdup(tokens[1].c_str()),
						strdup(tokens[2].c_str()),
						strdup(tokens[3].c_str())
					};

	// convert instruction string to mnemonic enum for switch
	mnemonic mnem = mnemonify (tokens[0]);

	// flags
	bool err = false;
	bool twoReg = true;

	// initialize longs to store register values
	long regA, regB, regSrcs[2];

	switch (mnem) {
	case add:
		twoReg = false;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Add(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case addi:
		regB = regFile.ReadOneRegister(tokens[2]);
		long imm = atol(args[2]);
		regA = alu.Add(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case sub:
		twoReg = false;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Subtract(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case subi:
		regB = regFile.ReadOneRegister(tokens[2]);
		long imm = atol(args[2]);
		regA = alu.Subtract(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case mul:
		twoReg = false;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Multiply((int)regSrcs[0], (int)regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case muli:
		regB = regFile.ReadOneRegister(tokens[2]);
		long imm = atol(args[2]);
		regA = alu.Multiply((int)regB, (int)imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case divd:
		twoReg = false;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Divide(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case divi:
		regB = regFile.ReadOneRegister(tokens[2]);
		long imm = atol(args[2]);
		regA = alu.Divide(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case fadd:
		twoReg = false;

		break;
	case faddi:

		break;
	case fsub:
		twoReg = false;

		break;
	case fsubi:

		break;
	case fmul:
		twoReg = false;

		break;
	case fmuli:

		break;
	case fdiv:
		twoReg = false;

		break;
	case fdivi:

		break;
	case sqrt:

		break;
	case sin:

		break;
	case exp:
		twoReg = false;

		break;
	case expi:

		break;
	case memld:

		break;
	case memst:

		break;
	case regld:

		break;
	case regst:

		break;
	default:
		cout << "Invalid instruction\n";
		err = true;
		break;
	}
	if (!err) {
		if (twoReg) {
			printf("Instruction: %s\nRegister contents:\n  %s: %d\n  %s: %d\n",
					inst, args[0], output[0],
					args[1], output[1]);
		} else {
			printf("Instruction: %s\nRegister contents:\n  %s: %d\n  %s: %d\n  %s: %d\n",
					inst, args[0], output[0],
					args[1], output[1],
					args[2], output[2]);
		}
	}
	free(inst);
	free(args[0]);
	free(args[1]);
	free(args[2]);
}

void Computer::PrintState(void)
{

}
