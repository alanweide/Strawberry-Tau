#ifndef MEMORY_H
#define MEMORY_H

#include "circuit.h"

class Memory: public Circuit
{
public:
    Memory();
    long ReadAddress(long address);
    long WriteToAddress(long address);
private:
};

#endif
