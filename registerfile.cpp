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

RegisterFile::RegisterFile()
{
	for (int i = 0; i < 16; i++)
	{
		registers[i] = 0;
	}
}

long RegisterFile::ReadOneRegister(string address)
{
	int addr = this->findRegister(address);
	return registers[addr];
}

long* RegisterFile::ReadTwoRegisters(string address1, string address2)
{
	int addr1 = this->findRegister(address1);
	int addr2 = this->findRegister(address2);
	long vals = {registers[addr1], registers[addr2]};
	return *vals;
}

void RegisterFile::Write(string address)
{

}

int RegisterFile::findRegister(string address)
{
	if (address.compare("reg0") == 0)
	{
		return registers[0];
	}
	else if (address.compare("reg1") == 0)
	{
		return registers[1];
	}
	else if (address.compare("reg2") == 0)
	{
		return registers[2];
	}
	else if (address.compare("reg3") == 0)
	{
		return registers[3];
	}
	else if (address.compare("reg4") == 0)
	{
		return registers[4];
	}
	else if (address.compare("reg5") == 0)
	{
		return registers[5];
	}
	else if (address.compare("reg6") == 0)
	{
		return registers[6];
	}
	else if (address.compare("reg7") == 0)
	{
		return registers[7];
	}
	else if (address.compare("reg8") == 0)
	{
		return registers[8];
	}
	else if (address.compare("reg9") == 0)
	{
		return registers[9];
	}
	else if (address.compare("reg10") == 0)
	{
		return registers[10];
	}
	else if (address.compare("reg11") == 0)
	{
		return registers[11];
	}
	else if (address.compare("reg12") == 0)
	{
		return registers[12];
	}
	else if (address.compare("reg13") == 0)
	{
		return registers[13];
	}
	else if (address.compare("reg14") == 0)
	{
		return registers[14];
	}
	else if (address.compare("reg15") == 0)
	{
		return registers[15];
	}
	else
	{
		cout << "Invalid register name.  arg = " + address;
		return NULL;
	}


}
