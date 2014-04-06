#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <string>

class RegisterFile
{
public:
	RegisterFile();
	long ReadOneRegister(string address);
	long* ReadTwoRegisters(string address1, string address2);
	void Write(string address);
	int findRegister(string address);
private:
	long registers[16];
};

#endif
