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
	if (mnem.compare("add") == 0) {
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
	instruction += '\0';
	string* tokens = new string[4];
	int i = 0;
	while (instruction[i] != ' ') {
		tokens[0] += instruction[i];
		i++;
	}
	i++;
	cout << tokens[0] << "\n";
	while (instruction[i] != ' ') {
		tokens[1] += instruction[i];
		i++;
	}
	i++;
	cout << "first reg: " << tokens[1] << "\n";
	while (instruction[i] != ' ') {
		tokens[2] += instruction[i];
		i++;
	}
	i++;
	cout << "second reg: " << tokens[2] << "\n";
	while (instruction[i] != '\0') {
		tokens[3] += instruction[i];
		i++;
	}
	cout << "last reg: " << tokens[3] << "\n";

	/*
    smatch smTokens;
	regex instRx ("^(\w+)\s(w+)\s(w+)\s(\w+)$");
	bool match = regex_match(instruction,
			smTokens,
			instRx,
			regex_constants::match_default);
	cout << match << "\n";
	cout << "smTokens size: " << smTokens.size() << "\n";
	for (int i = 0; i < smTokens.size(); i++) {
		cout << smTokens[i] << "\n";
		tokens[i] = smTokens[i];
	}
	 */
	return tokens;
}

void Computer::Execute(string instruction)
{
	string* tokens = TokenizeInstruction (instruction);
	long output[3]; // long values of argument registers after execution

	// convert strings to char* for output in printf statement
	// Is there a better way to do this?
	char* inst = strdup(tokens[0].c_str());
	char** args = new char*[3];
	args[0] = strdup(tokens[1].c_str());
	args[1] = strdup(tokens[2].c_str());
	args[2] = strdup(tokens[3].c_str());
	//strcpy (args[0], tokens[1].c_str());
	//strcpy (args[1], tokens[2].c_str());
	//strcpy (args[2], tokens[3].c_str());

	// convert instruction string to mnemonic enum for switch
	cout << tokens[0] << "\n";
	mnemonic mnem = mnemonify (tokens[0]);

	// flags
	bool err = false;
	bool twoReg = true;
	bool fp_op = false;

	// initialize longs to store register values
	long regA, regB, imm;
	long *regSrcs = new long[2];
	long *divRes = new long[2];

	// initialize doubless to store register values
	double fp_regA, fp_regB, fp_imm;
	double *fp_regSrcs = new double[2];
	double *fp_divRes = new double[2];

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
		imm = atol(args[2]);
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
		imm = atol(args[2]);
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
		imm = atol(args[2]);
		regA = alu.Multiply((int)regB, (int)imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case divd:
		twoReg = false;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		divRes = alu.Divide(regSrcs[0], regSrcs[1]);
		regA = divRes[0];
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case divi:
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = atol(args[2]);
		divRes = alu.Divide(regB, imm);
		regA = divRes[0];
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case fadd:
		twoReg = false;
		fp_op = true;
		regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		regA = alu.Add(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case faddi:
		fp_op = true;
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = atod(args[2]);
		regA = alu.Add(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case fsub:
		twoReg = false;
		fp_op = true;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Subtract(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case fsubi:
		fp_op = true;
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = atol(args[2]);
		regA = alu.Subtract(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case fmul:
		twoReg = false;
		fp_op = true;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Multiply((int)regSrcs[0], (int)regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case fmuli:
		fp_op = true;
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = atol(args[2]);
		regA = alu.Multiply((int)regB, (int)imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case fdiv:
		twoReg = false;
		fp_op = true;
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		divRes = alu.Divide(regSrcs[0], regSrcs[1]);
		regA = divRes[0];
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case fdivi:
		fp_op = true;
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = atol(args[2]);
		divRes = alu.Divide(regB, imm);
		regA = divRes[0];
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case sqrt:
		fp_op = true;

		break;
	case sin:
		fp_op = true;

		break;
	case exp:
		twoReg = false;
		fp_op = true;
		break;
	case expi:
		fp_op = true;
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
			printf("Instruction: %s\nRegister contents:\n  %s: %ld\n  %s: %ld\n",
					inst, args[0], output[0],
					args[1], output[1]);
		} else {
			printf("Instruction: %s\nRegister contents:\n  %s: %ld\n  %s: %ld\n  %s: %ld\n",
					inst, args[0], output[0],
					args[1], output[1],
					args[2], output[2]);
		}
	}
	delete[] inst;
	free (args[0]);
	free (args[1]);
	free (args[2]);
	delete[] args;
	delete[] tokens;
	delete[] regSrcs;
	delete[] divRes;
}

void Computer::PrintState(void)
{

}
