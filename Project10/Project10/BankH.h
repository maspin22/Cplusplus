//
// Bank.h
//
// The Bank class for A5 -- updated for A10
//

#include <iostream>
#include <fstream>
#include <map>

#include "BankAccountH.h"
using namespace std;
class Bank
{
public:
	Bank();
	void newAccount();
	void listAccounts();
	void selectAccount();
	weak_ptr<BankAccount> getCurrentAccount(){	return mCurrentAccount; }
	void saveCurrentAccount();  // public function to save the currently selected bank account
private:
	std::map<int, shared_ptr<BankAccount> > mAccounts;  // Our new STL map of BankAccount pointers
	std::map<int, int> mAccountOffsets;      // Keep track of offsets of account numbers
	weak_ptr<BankAccount> mCurrentAccount;           // This is how we keep track of which account is selected
	std::fstream bankFile;   // Our fstream file variable which will be set to the open file
	void saveAccount(shared_ptr<BankAccount> ba);  // private function to save a bank account
};
