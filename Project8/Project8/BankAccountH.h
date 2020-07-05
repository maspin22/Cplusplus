#pragma once
#pragma once
using namespace std;
#include <string>;
//Specifies class BankAccount 
class BankAccount {
public:
	BankAccount();
	BankAccount(int number, string name, int initialBalance);
	int getBalance();
	string getName();
	int getNumber();

private:
	int mBalance;
	string accName; //one word name 
	int accNumber;
};