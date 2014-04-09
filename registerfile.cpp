//
//  registerfile.cpp
//  Strawberry Tau
//
//  Created by Alan Weide on 4/5/14.
//
//

#include "registerfile.h"
#include <string>
#include <iostream>
#include <regex>

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
		cout << "Invalid Register name. address = " + freg;
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

	/*
	if (reg.compare("reg0") == 0)
	{
		return 0;
	}
	else if (reg.compare("reg1") == 0)
	{
		return 1;
	}
	else if (reg.compare("reg2") == 0)
	{
		return 2;
	}
	else if (reg.compare("reg3") == 0)
	{
		return 3;
	}
	else if (reg.compare("reg4") == 0)
	{
		return 4;
	}
	else if (reg.compare("reg5") == 0)
	{
		return 5;
	}
	else if (reg.compare("reg6") == 0)
	{
		return 6;
	}
	else if (reg.compare("reg7") == 0)
	{
		return 7;
	}
	else if (reg.compare("reg8") == 0)
	{
		return 8;
	}
	else if (reg.compare("reg9") == 0)
	{
		return 9;
	}
	else if (reg.compare("reg10") == 0)
	{
		return 10;
	}
	else if (reg.compare("reg11") == 0)
	{
		return 11;
	}
	else if (reg.compare("reg12") == 0)
	{
		return 12;
	}
	else if (reg.compare("reg13") == 0)
	{
		return 13;
	}
	else if (reg.compare("reg14") == 0)
	{
		return 14;
	}
	else if (reg.compare("reg15") == 0)
	{
		return 15;
	}
	else
	{
		cout << "Invalid register name: " << reg << "\n";
		return NULL;
	}
	*/
}

int RegisterFile::findFPRegister(string freg)
{

	// converts the register number to an int and returns that value
	int fregNo = atoi(freg.substr(4, freg.length()-4).c_str());
	return fregNo;

	/*
	if (freg.compare("freg0") == 0)
	{
		return 0;
	}
	else if (freg.compare("freg1") == 0)
	{
		return 1;
	}
	else if (freg.compare("freg2") == 0)
	{
		return 2;
	}
	else if (freg.compare("freg3") == 0)
	{
		return 3;
	}
	else if (freg.compare("freg4") == 0)
	{
		return 4;
	}
	else if (freg.compare("freg5") == 0)
	{
		return 5;
	}
	else if (freg.compare("freg6") == 0)
	{
		return 6;
	}
	else if (freg.compare("freg7") == 0)
	{
		return 7;
	}
	else if (freg.compare("freg8") == 0)
	{
		return 8;
	}
	else if (freg.compare("freg9") == 0)
	{
		return 9;
	}
	else if (freg.compare("freg10") == 0)
	{
		return 10;
	}
	else if (freg.compare("freg11") == 0)
	{
		return 11;
	}
	else if (freg.compare("freg12") == 0)
	{
		return 12;
	}
	else if (freg.compare("freg13") == 0)
	{
		return 13;
	}
	else if (freg.compare("freg14") == 0)
	{
		return 14;
	}
	else if (freg.compare("freg15") == 0)
	{
		return 15;
	}
	else
	{
		cout << "Invalid register name.  address = " + freg;
		return NULL;
	}
	*/
}
