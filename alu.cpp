#include "alu.h"

ALU::ALU()
{

}

long ALU::Add(long a, long b)
{
	return a+b;
}

long* ALU::Divide(long a, long b)
{
	long quotient=a/b;
	long remainder=a%b;
	long* answer = new long[2];
	answer[0] = quotient;
	answer[1] = remainder;
	return answer;
}

long ALU::Multiply(int a, int b)
{
	// I'm leaving the parameters as ints so we don't have to
	// worry about overflow if we multiply two large long values
	return a*b;
}

long ALU::Subtract(long a, long b)
{
	return a-b;
}
