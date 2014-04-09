#include <iostream>
#include <string>
#include "computer.h"

using namespace std;

int main(void) {
	string instruction;
	Computer computer;

	while(instruction != "EndProgram")
	{
		cout << "Enter an instruction: ";
		getline (cin, instruction);
		cout << instruction << "\n";
		computer.Execute(instruction);
		computer.PrintState();
	}
	return 0;
}
