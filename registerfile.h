#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

class RegisterFile
{
public:
	RegisterFile();
	int ReadOneRegister(int address);
	int* ReadTwoRegisters(int address1, int address2);
	int Write(int address);
private:

};

#endif
