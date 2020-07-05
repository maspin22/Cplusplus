//
// CS2024 -- Assignment 4
//
// Michael Aspinwall
// 9-24-2019

#include <iostream>
#include "MenuH.h"
#include "BankAccountH.h"
using namespace std;

//prompts user for input and calls its eponymous BankAccount member function
void newBankAcc()
{
	int number;
	string name;
	int balance;
	
	cout << "ENTER ACCOUNT NUMBER:" << endl;
	cin >> number;
	cout << "ENTER ACCOUNT NAME:" << endl;
	cin >> name;
	cout << "ENTER OPENING BALANCE:" << endl;
	cin >> balance;
	BankAccount(number, name, balance);
}



//Displays menu, prompts user for input and executes those commands once...
//continues loop until user sends cQuitItem
int main(int argc, char* argv[])
{
	Menu m;
	BankAccount b;
	MenuItemCode x;
	bool con = true;
	bool fail; //bool to represent withdrawl failure
	do {
		m.showMenu();
		x = m.promptUser(); 
		switch (x)
		{
		case cNewAcc:
			cout << "NEW ACCOUNT:" << endl;
			newBankAcc();
			break;
		case cLstAcc:
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


