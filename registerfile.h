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
	string PrintRegs(void);
	// long register ops
	long ReadOneRegister(string reg);
	long* ReadTwoRegisters(string regA, string regB);
	void Write(string reg, long value);
	// fp register ops
	double ReadOneFPRegister(string freg);
	double* ReadTwoFPRegisters(string fregA, string fregB);
	void WriteFP(string freg, double value);
private:
	long* registers;
	double* fregisters;
	int findRegister(string reg);
	int findFPRegister(string freg);
};

#endif
