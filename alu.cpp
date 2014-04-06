#include "alu.h"

ALU::ALU()
{

}

int ALU::Add(int a, int b)
{
	return a+b;
}

int* ALU::Divide(int a, int b)
{
	int quotient=a/b;
	int remainder=a%b;
	int answer[2]={quotient,remainder};
	return answer;
}

int ALU::Multiply(int a, int b)
{
	return a*b;
}

int ALU::Subtract(int a, int b)
{
	return a-b;
}
