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
	for (int i = 0; i < 16; i++)
	{
		registers[i] = 0;
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
	int addr = this->findRegister(reg);
	if (addr == 0)
	{
		cout << "Cannot write to reg0 (constant 0)\n";
	}
	else if (addr == -1)
	{
		cout << "Invalid Register name. address = " << reg << "\n";
	}
	else
	{
		registers[addr] = value;
	}
}

int RegisterFile::findRegister(string reg)
{
	regex regTest("reg(1[0-5]|\d)$");
	bool valid = regex_match(reg, regTest);
	if (valid) {
		// converts the register number to an int and returns that value
		int regNo = atoi(reg.substr(3, reg.length()-3).c_str());
		return regNo;
	} else {
		cout << "Invalid register string";
		return -1;
	}
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
