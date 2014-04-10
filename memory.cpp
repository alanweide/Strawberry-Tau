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
	lmem = new long[256];
	fmem = new double[256];
}

long Memory::ReadLAddress(long address)
{
	return lmem[address];
}

void Memory::WriteToLAddress(long address, long value)
{
	lmem[address] = value;
}

double Memory::ReadFPAddress(long address)
{
	return fmem[address];
}

void Memory::WriteToFPAddress(long address, double value)
{
	fmem[address] = value;
}


