#include <iostream>
#include <string>
#include "computer.h"

using namespace std;

int main(void) {
  string instruction;
  Computer computer;
  
  while(string!="EndProgram")
  {
    cout<<"Enter an instruction: ";
    cin>>instruction;
    computer.Execute(instruction);
    computer.PrintState();
  }
  return 0;
}
