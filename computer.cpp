//
//  computer.cpp
//  Strawberry Tau
//
//  Created by Alan Weide on 4/5/14.
//
//

#include "computer.h"
//#include "memory.h"
//#include "alu.h"
//#include "fpu.h"
//#include "registerfile.h"
//#include <string>
//#include <iostream>
//#include <regex>
//#include <stdlib.h>

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
	memld,
	memst,
	fmemld,
	fmemst,
	regld,
	regst,
	fregld,
	fregst,
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
	} else if (mnem.compare("memld") == 0) {
		return memld;
	} else if (mnem.compare("memst") == 0) {
		return memst;
	} else if (mnem.compare("regld") == 0) {
		return regld;
	} else if (mnem.compare("regst") == 0) {
		return regst;
	} else if (mnem.compare("fregld") == 0) {
		return fregld;
	} else if (mnem.compare("fregst") == 0) {
		return fregst;
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
	double fp_output[3]; // double values of argument registers after execution
	// convert strings to char* for output in printf statement
	// Is there a better way to do this?
	char* inst = strdup(tokens[0].c_str());
	char** args = new char*[6];
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
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Add(fp_regSrcs[0], fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case faddi:
		fp_op = true;
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = atof(args[2]);
		fp_regA = fpu.Add(fp_regB, fp_imm);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fsub:
		twoReg = false;
		fp_op = true;
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Subtract(regSrcs[0], fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fsubi:
		fp_op = true;
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = atof(args[2]);
		fp_regA = fpu.Subtract(fp_regB, fp_imm);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fmul:
		twoReg = false;
		fp_op = true;
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Multiply((int)fp_regSrcs[0], (int)fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fmuli:
		fp_op = true;
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = atof(args[2]);
		fp_regA = fpu.Multiply((int)fp_regB, (int)fp_imm);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fdiv:
		twoReg = false;
		fp_op = true;
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_divRes = fpu.Divide(regSrcs[0], regSrcs[1]);
		fp_regA = fp_divRes[0];
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fdivi:
		fp_op = true;
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_imm = atof(args[2]);
		fp_divRes = fpu.Divide(fp_regB, fp_imm);
		fp_regA = divRes[0];
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fsqrt:
		fp_op = true;
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_regA = fpu.SquareRoot(fp_regB);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fsin:
		fp_op = true;
		fp_regB = regFile.ReadOneFPRegister(tokens[2]);
		fp_regA = fpu.Sin(fp_regB);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regB;
		break;
	case fexp:
		twoReg = false;
		fp_op = true;
		fp_regSrcs = regFile.ReadTwoFPRegisters(tokens[2], tokens[3]);
		fp_regA = fpu.Exp(fp_regSrcs[0], fp_regSrcs[1]);
		regFile.WriteFP(tokens[1], fp_regA);
		fp_output[0] = fp_regA;
		fp_output[1] = fp_regSrcs[0];
		fp_output[2] = fp_regSrcs[1];
		break;
	case fexpi:
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
		if (!fp_op)
		{
			if (twoReg) {
				cout << "Instruction: " << inst << "\nRegister contents:\n  " <<
						args[0] << ": " << output[0] << "\n  "
						<< args[1] << ": " << output[1] << "\n";
				//			printf("Instruction: %s\nRegister contents:\n  %s: %ld\n  %s: %ld\n",
				//					inst, args[0], output[0],
				//					args[1], output[1]);
			} else {
				cout << "Instruction: " << inst << "\nRegister contents:\n  " <<
						args[0] << ": " << output[0] << "\n  " << args[1] << ": " <<
						output[1] << "\n  " << args[2] << ": " << output[2] << "\n";
				//			printf("Instruction: %s\nRegister contents:\n  %s: %ld\n  %s: %ld\n  %s: %ld\n",
				//					inst, args[0], output[0],
				//					args[1], output[1],
				//					args[2], output[2]);
			}
		}
		else
		{
			if (twoReg) {
				cout << "Instruction: " << inst << "\nRegister contents:\n  " <<
						args[0] << ": " << fp_output[0] << "\n  " <<
						args[1] << ": " << fp_output[1] << "\n";
				//			printf("Instruction: %s\nRegister contents:\n  %s: %ld\n  %s: %ld\n",
				//					inst, args[0], output[0],
				//					args[1], output[1]);
			} else {
				cout << "Instruction: " << inst << "\nRegister contents:\n  " <<
						args[0] << ": " << fp_output[0] << "\n  " <<
						args[1] << ": " << fp_output[1] << "\n  " <<
						args[2] << ": " << fp_output[2] << "\n";
				//			printf("Instruction: %s\nRegister contents:\n  %s: %ld\n  %s: %ld\n  %s: %ld\n",
				//					inst, args[0], output[0],
				//					args[1], output[1],
				//					args[2], output[2]);
			}
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
	delete[] fp_regSrcs;
	delete[] fp_divRes;
}

void Computer::PrintState(void)
{

}
