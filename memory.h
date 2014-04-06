#ifndef MEMORY_H
#define MEMORY_H

using namespace std;

class Memory
{
public:
	Memory();
	long ReadAddress(long address);
	void WriteToAddress(long address, long value);
private:
	long mem[32];
};

#endif
