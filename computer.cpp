//
//  computer.cpp
//  Strawberry Tau
//
//  Created by Alan Weide, Frank Fulajtar, and Jacob Oost on 4/5/14.
//
//

#include "computer.h"

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
	fsqrt,
	fsin,
	fexp,
	fexpi,
	ld,
	st,
	fld,
	fst,
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
	} else if (mnem.compare("addi") == 0) {
		return addi;
	} else if (mnem.compare("sub") == 0) {
		return sub;
	} else if (mnem.compare("subi") == 0) {
		return subi;
	} else if (mnem.compare("mul") == 0) {
		return mul;
	} else if (mnem.compare("muli") == 0) {
		return muli;
	} else if (mnem.compare("div") == 0) {
		return divd;
	} else if (mnem.compare("divi") == 0) {
		return divi;
	} else if (mnem.compare("fadd") == 0) {
		return fadd;
	} else if (mnem.compare("faddi") == 0) {
		return faddi;
	} else if (mnem.compare("fsub") == 0) {
		return fsub;
	} else if (mnem.compare("fsubi") == 0) {
		return fsubi;
	} else if (mnem.compare("fmul") == 0) {
		return fmul;
	} else if (mnem.compare("fmuli") == 0) {
		return fmuli;
	} else if (mnem.compare("fdiv") == 0) {
		return fdiv;
	} else if (mnem.compare("fdivi") == 0) {
		return fdivi;
	} else if (mnem.compare("sqrt") == 0) {
		return fsqrt;
	} else if (mnem.compare("sin") == 0) {
		return fsin;
	} else if (mnem.compare("exp") == 0) {
		return fexp;
	} else if (mnem.compare("expi") == 0) {
		return fexpi;
	} else if (mnem.compare("ld") == 0) {
		return ld;
	} else if (mnem.compare("st") == 0) {
		return st;
	} else if (mnem.compare("fld") == 0) {
		return fld;
	} else if (mnem.compare("fst") == 0) {
		return fst;
	}	else {

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
	while (instruction[i] != ' ') {
		tokens[1] += instruction[i];
		i++;
	}
	i++;
	while (instruction[i] != ' ') {
		tokens[2] += instruction[i];
		i++;
	}
	i++;
	while (instruction[i] != '\0') {
		tokens[3] += instruction[i];
		i++;
	}

	return tokens;
}

void Computer::Execute(string instruction)
{
	string* tokens = TokenizeInstruction (instruction);
	long output[3]; // long values of argument registers after execution
	double fp_output[3]; // double values of argument registers after execution

	// convert instruction string to mnemonic enum for switch
	cout << tokens[0] << "\n";
	mnemonic mnem = mnemonify (tokens[0]);

	// initialize longs to store register values
	long regA, regB, imm;
	long *regSrcs = new long[2];
	long *divRes = new long[2];

	// initialize doubles to store register values
	double fp_regA, fp_regB, fp_imm;
	double *fp_regSrcs = new double[2];
	double *fp_divRes = new double[2];

	switch (mnem) {
	case add:
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Add(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case addi:
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = stol(tokens[3]);
		regA = alu.Add(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case sub:
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Subtract(regSrcs[0], regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case subi:
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = stol(tokens[1]);
		regA = alu.Subtract(regB, imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case mul:
		regSrcs = regFile.ReadTwoRegisters(tokens[2], tokens[3]);
		regA = alu.Multiply((int)regSrcs[0], (int)regSrcs[1]);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regSrcs[0];
		output[2] = regSrcs[1];
		break;
	case muli:
		regB = regFile.ReadOneRegister(tokens[2]);
		imm = stol(tokens[3]);
		regA = alu.Multiply((int)regB, (int)imm);
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case divd:
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
		imm = stol(tokens[3]);
		divRes = alu.Divide(regB, imm);
		regA = divRes[0];
		regFile.Write(tokens[1], regA);
		output[0] = regA;
		output[1] = regB;
		break;
	case fadd:
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Add(fp_regSrcs[0], fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case faddi:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = stof(tokens[3]);
		fp_regA = fpu.Add(fp_regB, fp_imm);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fsub:
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Subtract(regSrcs[0], fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fsubi:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = stof(tokens[3]);
		fp_regA = fpu.Subtract(fp_regB, fp_imm);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fmul:
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Multiply((int)fp_regSrcs[0], (int)fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fmuli:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = stof(tokens[3]);
		fp_regA = fpu.Multiply((int)fp_regB, (int)fp_imm);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fdiv:
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_divRes = fpu.Divide(regSrcs[0], regSrcs[1]);
		fp_regA = fp_divRes[0];
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fdivi:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = stof(tokens[3]);
		fp_divRes = fpu.Divide(fp_regB, fp_imm);
		fp_regA = divRes[0];
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fsqrt:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_regA = fpu.SquareRoot(fp_regB);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fsin:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_regA = fpu.Sin(fp_regB);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fexp:
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_regA = fpu.Exp(fp_regB);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case ld:
		regA = regFile.ReadOneRegister(tokens[2]);
		regB = mem.ReadLAddress(regA);
		regFile.Write(tokens[1], regB);
		break;
	case st:
		regA = regFile.ReadOneRegister(tokens[2]);
		regB = regFile.ReadOneRegister(tokens[1]);
		mem.WriteToLAddress(regB, regA);
		break;
	case fld:
		regA = regFile.ReadOneFPRegister(tokens[2]);
		fp_regB = mem.ReadFPAddress(regA);
		regFile.WriteFP(tokens[1], fp_regB);
		break;
	case fst:
		regA = regFile.ReadOneRegister(tokens[2]);
		fp_regB = regFile.ReadOneRegister(tokens[1]);
		mem.WriteToFPAddress(regA, fp_regB);
		break;
	default:
		cout << "Invalid instruction\n";
		break;
	}
	delete[] tokens;
	delete[] regSrcs;
	delete[] divRes;
	delete[] fp_regSrcs;
	delete[] fp_divRes;
}

void Computer::PrintState(void)
{
	cout << regFile.PrintRegs();
}
