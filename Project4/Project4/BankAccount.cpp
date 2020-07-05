#include "BankAccountH.h"
#include <iostream>
using namespace std;

//implements defalut constructor 
BankAccount::BankAccount(void) {
	mBalance = 0;
}

//implements constructor that accepts intial balance amount
BankAccount::BankAccount(int number, string name, int initial) {
	mBalance = initial;

}

//returns current balance
int BankAccount::getBalance() {
	return mBalance;
}

int BankAccount::getBalance() {
	return mBalance;
}


