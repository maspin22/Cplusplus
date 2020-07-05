#pragma once

//Specifies class BankAccount 
class BankAccount {
public:
	BankAccount();
	BankAccount(int number, string name, int initialBalance);
	int getBalance();
private:
	int mBalance;
	string name;
	int accNumber;
};