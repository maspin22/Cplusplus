// CS2024 -- Assignment 5
//
// Michael Aspinwall
// 10-2-2019

#include <iostream>
#include "BankAccountH.h"
#include "MenuH.h"
#include "BankH.h"
using namespace std;


//Displays menu, prompts user for input and executes those commands once...
//continues loop until user sends cQuitItem
int main(int argc, char* argv[])
{
	Menu m;
	MenuItemCode x;
	Bank b;
	bool con = true;
	do {
		m.showMenu();
		x = m.promptUser();
		switch (x)
		{
		case cNewAcc:
			cout << "NEW ACCOUNT:" << endl;
			b.newAccount();
			break;
		case cLstAcc:
			b.listAccounts();
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


