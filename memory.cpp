//
//  memory.cpp
//  Strawberry Tau
//
//  Created by Alan Weide on 4/5/14.
//
//

#include "memory.h"

using namespace std;

Memory::Memory()
{

}

long Memory::ReadAddress(long address)
{
	return mem[address];
}

void Memory::WriteToAddress(long address, long value)
{
	mem[address] = value;
}


