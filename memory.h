//
//  memory.h
//  Strawberry Tau
//
//  Created by Alan Weide, Frank Fulajtar, and Jacob Oost on 4/5/14.
//
//

#ifndef MEMORY_H
#define MEMORY_H

using namespace std;

class Memory
{
public:
	Memory();
	long ReadLAddress(long address);
	void WriteToLAddress(long address, long value);
	double ReadFPAddress(long address);
	void WriteToFPAddress(long address, double value);
private:
	long* lmem;
	double* fmem;
};

#endif
