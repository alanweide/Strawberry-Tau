#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <string>

using namespace std;

class RegisterFile
{
public:
	RegisterFile();
	// long register ops
	long ReadOneRegister(string address);
	long* ReadTwoRegisters(string address1, string address2);
	void Write(string address, long value);
	// fp register ops
	double ReadOneFPRegister(string address);
	double* ReadTwoFPRegisters(string address1, string address2);
	void WriteFP(string address, double value);
private:
	long registers[16];
	double fregisters[16];
	int findRegister(string address);
	int findFPRegister(string address);
};

#endif
