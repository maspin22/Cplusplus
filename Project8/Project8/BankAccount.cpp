#include "BankAccountH.h"
#include <iostream>
using namespace std;

//implements defalut constructor 
BankAccount::BankAccount(void) {
	mBalance = 0;
	accName = "";
	accNumber = 0;
}

//implements constructor that accepts account number, account name and intial balance amount
BankAccount::BankAccount(int number, string name, int initial) {
	accNumber = number;
	accName = name;
	mBalance = initial;
}

//returns current balance
int BankAccount::getBalance() {
	return mBalance;
}

//returns account name 
string BankAccount::getName() {
	return accName;
}

//returns account number
int BankAccount::getNumber() {
	return accNumber;
}


