//
// CS2024 -- Assignment 7
//
// Michael Aspinwall
// 10-24-2019

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
	MenuItem menuItems[] = { MenuItem("Print My Name",'a'), MenuItem("Square a Number",'b'), MenuItem("Quit",'q') };
	Menu theMenu(menuItems, 3);
	bool con = true;

	do {
		cout << theMenu;
		char x = theMenu.promptUser();
		switch (x)
		{
		case 'a':
			printMyName();
			break;
		case 'b':
			squareANumber();
			break;
		case 'q':
			cout << "Quiting" << endl;
			con = false;
			break;
		case -1:
			cout << "Unkown Selection" << endl;
			break;
		}
	} while (con);
}



