#ifndef ALU_H
#define ALU_H

class ALU
{
public:
	ALU();
	long Add(long a, long b); // a+b
	long Subtract(long a, long b); // a-b
	long Multiply(int a, int b); // a*b
	long* Divide(long a, long b); // returns array containing quotient and remainder
private:
	// ?
};

#endif
