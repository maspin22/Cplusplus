//
// CS2024 -- Assignment 3
//
// Michael Aspinwall
// 9-17-2019

#include <iostream>
#include "MenuH.h"
using namespace std;

//Prints my name 3 times
void printMyName() 
{
	for (int i = 0; i < 3; i++) {
		std::cout << "Michael Aspinwall" << std::endl;
	}
}

//Prompts user for a number... prints the input squared
void squareANumber()
{
	int x;
	cout << "Enter a Number:" << endl;
	cin >> x;
	cout << x * x << endl;
}

//Displays menu, prompts user for input and executes those commands once...
//countiunes loop until user sends cQuitItem
int main(int argc, char* argv[]) 
{
	Menu m;
	MenuItemCode x;
	bool con = true;

	do {
		m.showMenu();
		x = m.promptUser();
		switch (x)
		{
		case cPrintMyNameItem:
			printMyName();
			break;
		case cSquareANumberItem:
			squareANumber();
			break;
		case cQuitItem:
			cout << "Quiting" << endl;
			con = false;
			break;
		case cUnknownItem:
			cout << "Unkown Selection" << endl;
			break;
		}
	} while (con);
}



