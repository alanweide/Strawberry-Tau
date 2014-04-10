//
//  registerfile.cpp
//  Strawberry Tau
//
//  Created by Alan Weide, Frank Fulajtar, and Jacob Oost on 4/5/14.
//
//

#include "registerfile.h"

using namespace std;

RegisterFile::RegisterFile()
{
	registers = new long[16];
	fregisters = new double[16];
	for (int i = 0; i < 16; i++)
	{
		registers[i] = 0;
		fregisters[i] = 0;
	}
}

string RegisterFile::PrintRegs(void) {
	string out = "Integer Registers:\n";
	int i = 0;
	while (i < 10) {
		out += to_string(i) + ":  " + to_string(registers[i]) + "\n";
		i++;
	}
	while (i < 16) {
		out += to_string(i) + ": " + to_string(registers[i]) + "\n";
		i++;
	}
	i = 0;
	out += "------------------------------------\n";
	out += "Floating Point Registers:\n";
	while (i < 10) {
		out += to_string(i) + ":  " + to_string(fregisters[i]) + "\n";
		i++;
	}
	while (i < 16) {
		out += to_string(i) + ": " + to_string(fregisters[i]) + "\n";
		i++;
	}
	out += "------------------------------------\n";
	return out;
}

long RegisterFile::ReadOneRegister(string reg)
{
	int addr = this->findRegister(reg);
	return registers[addr];
}

long* RegisterFile::ReadTwoRegisters(string regA, string regB)
{
	int reg1 = this->findRegister(regA);
	int reg2 = this->findRegister(regB);
	long* vals = new long[2];
	vals[0] = registers[reg1];
	vals[1] = registers[reg2];
	return vals;
}

void RegisterFile::Write(string reg, long value)
{
	int regNo = this->findRegister(reg);
	if (regNo == 0)
	{
		cout << "Cannot write to reg0 (constant 0)\n";
	}
	else if (regNo == -1)
	{
		cout << "Invalid Register name. address = " << reg << "\n";
	}
	else
	{
		registers[regNo] = value;
	}
}

double RegisterFile::ReadOneFPRegister(string freg)
{
	int addr = this->findFPRegister(freg);
	return fregisters[addr];
}

double* RegisterFile::ReadTwoFPRegisters(string fregA, string fregB)
{
	int reg1 = this->findFPRegister(fregA);
	int reg2 = this->findFPRegister(fregB);
	double* vals = new double[2];
	vals[0] = fregisters[reg1];
	vals[1] = fregisters[reg2];
	return vals;
}

void RegisterFile::WriteFP(string freg, double value)
{
	int fregNo = this->findFPRegister(freg);
	if (fregNo == 0)
	{
		cout << "Cannot write to reg0 (constant 0)";
	}
	else if (fregNo == -1)
	{
		cout << "Invalid Register name: address = " + freg;
	}
	else
	{
		fregisters[fregNo] = value;
	}
}

int RegisterFile::findRegister(string reg)
{
	// converts the register number to an int and returns that value
	int regNo = atoi(reg.substr(3, reg.length()-3).c_str());
	return regNo;
}

int RegisterFile::findFPRegister(string freg)
{

	// converts the register number to an int and returns that value
	int fregNo = atoi(freg.substr(4, freg.length()-4).c_str());
	return fregNo;
}
