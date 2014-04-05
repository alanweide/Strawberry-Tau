#ifndef CIRCUIT_H
#define CIRCUIT_H

class Circuit
{
public:
  Circuit();
  virtual void Input(double*);
  virtual double* Output(void);
  int GetState(void);
private:
  virtual void WriteMemory(int index);
  virtual double ReadMemory(int index);
  double *memory;
  int state;
};

#endif
