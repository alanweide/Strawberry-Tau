//
//  main.cpp
//  Strawberry Tau
//
//  Created by Alan Weide, Frank Fulajtar, and Jacob Oost on 4/5/14.
//
//
#include "computer.h"

using namespace std;

int main(void) {
	string instruction;
	Computer computer;
	cout << "Enter an instruction: ";
	getline (cin, instruction);
	while(instruction != "endprogram")
	{
		computer.Execute(instruction);
		computer.PrintState();
		cout << "Enter an instruction: ";
		getline (cin, instruction);
	}
	return 0;
}
