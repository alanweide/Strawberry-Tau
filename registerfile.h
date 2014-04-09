#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <string>
#include <iostream>
#include <regex>

using namespace std;

class RegisterFile
{
public:
	RegisterFile();
	long ReadOneRegister(string reg);
	long* ReadTwoRegisters(string regA, string regB);
	void Write(string reg, long value);

private:
	long* registers;
	int findRegister(string address);
};

#endif
