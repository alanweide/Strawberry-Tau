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

using namespace std;

RegisterFile::RegisterFile()
{
	for (int i = 0; i < 16; i++)
	{
		registers[i] = 0;
		fregisters[i] = 0;
	}
}

long RegisterFile::ReadOneRegister(string address)
{
	int addr = this->findRegister(address);
	return registers[addr];
}

long* RegisterFile::ReadTwoRegisters(string address1, string address2)
{
	int reg1 = this->findRegister(address1);
	int reg2 = this->findRegister(address2);
	long vals[2] = {registers[reg1], registers[reg2]};
	return vals;
}

void RegisterFile::Write(string address, long value)
{
	int addr = this->findRegister(address);
	if (addr == 0)
	{
		cout << "Cannot write to reg0 (constant 0)";
	}
	else if (addr == NULL)
	{
		cout << "Invalid Register name. address = " + address;
	}
	else
	{
		registers[addr] = value;
	}
}

double RegisterFile::ReadOneFPRegister(string address)
{
	int addr = this->findFPRegister(address);
	return fregisters[addr];
}

double* RegisterFile::ReadTwoFPRegisters(string address1, string address2)
{
	int reg1 = this->findFPRegister(address1);
	int reg2 = this->findFPRegister(address2);
	double vals[2] = {fregisters[reg1], fregisters[reg2]};
	return vals;
}

void RegisterFile::WriteFP(string address, double value)
{
	int addr = this->findFPRegister(address);
	if (addr == 0)
	{
		cout << "Cannot write to reg0 (constant 0)";
	}
	else if (addr == NULL)
	{
		cout << "Invalid Register name. address = " + address;
	}
	else
	{
		fregisters[addr] = value;
	}
}

int RegisterFile::findRegister(string address)
{
	if (address.compare("reg0") == 0)
	{
		return 0;
	}
	else if (address.compare("reg1") == 0)
	{
		return 1;
	}
	else if (address.compare("reg2") == 0)
	{
		return 2;
	}
	else if (address.compare("reg3") == 0)
	{
		return 3;
	}
	else if (address.compare("reg4") == 0)
	{
		return 4;
	}
	else if (address.compare("reg5") == 0)
	{
		return 5;
	}
	else if (address.compare("reg6") == 0)
	{
		return 6;
	}
	else if (address.compare("reg7") == 0)
	{
		return 7;
	}
	else if (address.compare("reg8") == 0)
	{
		return 8;
	}
	else if (address.compare("reg9") == 0)
	{
		return 9;
	}
	else if (address.compare("reg10") == 0)
	{
		return 10;
	}
	else if (address.compare("reg11") == 0)
	{
		return 11;
	}
	else if (address.compare("reg12") == 0)
	{
		return 12;
	}
	else if (address.compare("reg13") == 0)
	{
		return 13;
	}
	else if (address.compare("reg14") == 0)
	{
		return 14;
	}
	else if (address.compare("reg15") == 0)
	{
		return 15;
	}
	else
	{
		cout << "Invalid register name.  arg = " + address;
		return NULL;
	}

}

int RegisterFile::findFPRegister(string address)
{
	if (address.compare("freg0") == 0)
	{
		return 0;
	}
	else if (address.compare("freg1") == 0)
	{
		return 1;
	}
	else if (address.compare("freg2") == 0)
	{
		return 2;
	}
	else if (address.compare("freg3") == 0)
	{
		return 3;
	}
	else if (address.compare("freg4") == 0)
	{
		return 4;
	}
	else if (address.compare("freg5") == 0)
	{
		return 5;
	}
	else if (address.compare("freg6") == 0)
	{
		return 6;
	}
	else if (address.compare("freg7") == 0)
	{
		return 7;
	}
	else if (address.compare("freg8") == 0)
	{
		return 8;
	}
	else if (address.compare("freg9") == 0)
	{
		return 9;
	}
	else if (address.compare("freg10") == 0)
	{
		return 10;
	}
	else if (address.compare("freg11") == 0)
	{
		return 11;
	}
	else if (address.compare("freg12") == 0)
	{
		return 12;
	}
	else if (address.compare("freg13") == 0)
	{
		return 13;
	}
	else if (address.compare("freg14") == 0)
	{
		return 14;
	}
	else if (address.compare("freg15") == 0)
	{
		return 15;
	}
	else
	{
		cout << "Invalid register name.  address = " + address;
		return NULL;
	}

}
