#include "BankH.h"
#include <iostream>
using namespace std;

//takes user input to create a new bank account.. adds it to the vector of accounts
void Bank::newAccount() {
	int number;
	string name;
	int balance;

	cout << "ENTER ACCOUNT NUMBER:" << endl;
	cin >> number;
	cout << "ENTER ACCOUNT NAME:" << endl;
	cin>> name;
	cout << "ENTER OPENING BALANCE:" << endl;
	cin >> balance;
	BankAccount *b = new BankAccount(number, name, balance);
	mAccounts.push_back(b);
}

//prints vector of bank accounts
void Bank::listAccounts() {
	cout << "ACCT# : NAME : BALANCE" << endl;

	for (auto i = mAccounts.begin(); i != mAccounts.end(); ++i){
		int number = (*i)->getNumber();
		string str = (*i)->getName();
		int balance = (*i)->getBalance();
		
		cout << number << " : " << str << " : " << balance << endl;
	}
}