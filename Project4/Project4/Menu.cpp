#include "MenuH.h"
#include <iostream>

using namespace std;

//implements menu display
void Menu::showMenu()
{
	cout << "\n---- MENU ----" << endl;
	cout << "(1) New Account" << endl;
	cout << "(2) List Accounts" << endl;
	cout << "(3) Quit" << endl;
}

//implements method to receive user input and return commands
MenuItemCode Menu::promptUser() {
	int x;
	cout << "Enter Choice:" << endl;
	cin >> x;

	switch (x) {
	case 1:
		return cNewAcc;
	case 2:
		return cLstAcc;
	case 3:
		return cQuitItem;
	default:
		return cUnknownItem;
	}
}

