#pragma once
#include <vector>;
#include "BankAccountH.h"

//class Bank with fuctions to create and new account and display existing accounts 
class Bank
{
public:
	void newAccount();
	void listAccounts();
private:
	std::vector<BankAccount*> mAccounts;
};