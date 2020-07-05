#include "MenuH.h"
#include <iostream>

using namespace std;

//implements menu display
void Menu::showMenu() 
{
	cout << "---- MENU ----"<< endl;
	cout << "(1) Print My Name 3 Times" << endl;
	cout << "(2) Square A Number" << endl;
	cout << "(3) Quit" << endl;
}

//implements method to receive user input and return commands
MenuItemCode Menu::promptUser() {
	int x;
	cout << "Enter Choice:" << endl;
	cin >> x;

	switch (x) {
		case 1:
			return cPrintMyNameItem;
		case 2:
			return cSquareANumberItem;
		case 3: 
			return cQuitItem;
		default:
			return cUnknownItem;
	}
}


