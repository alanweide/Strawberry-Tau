#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <string>

using namespace std;

class RegisterFile
{
public:
	RegisterFile();
	long ReadOneRegister(string address);
	long* ReadTwoRegisters(string address1, string address2);
	void Write(string address, long value);

private:
	long registers[16];
	int findRegister(string address);
};

#endif
