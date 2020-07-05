//
// main.cpp
//
// Assignment #10
//

#include <iostream>

#include "MenuItemH.h"
#include "MenuH.h"
#include "MenuCommandH.h"
#include "BankH.h"
#include "BankAccountH.h"
using namespace std;
// These are modified functions from A4

// prompt the user for an amount to withdrawal and
// then call BankAccount::withdrawal()
void withdrawal(shared_ptr<BankAccount> acct)
{
	int amount;
	std::cout << std::endl;
	std::cout << "Withdrawal" << std::endl;
	std::cout << "HOW MUCH DO YOU WANT TO WITHDRAWAL> ";
	std::cin >> amount;

	if (acct->withdrawal(amount)) {
		std::cout << "Withdrawal successful" << std::endl;
	}
	else {
		std::cout << "Withdrawal failed" << std::endl;
	}
}

//  prompt the user for an amount to deposit and then
// call BankAccount::deposit()
void deposit(shared_ptr<BankAccount> acct)
{
	int amount;
	std::cout << std::endl;
	std::cout << "Deposit" << std::endl;
	std::cout << "HOW MUCH DO YOU WANT TO DEPOSIT> ";
	std::cin >> amount;

	acct->deposit(amount);
}


// These functions are from A5
bool doListAccounts(Bank& b)
{
	b.listAccounts();
	return true;
}

bool doNewAccount(Bank& b)
{
	b.newAccount();
	return true;
}

bool doSelectAccount(Bank& b)
{
	b.selectAccount();
	return true;
}

// New convenience global function to test account
bool isAccountValid(shared_ptr<BankAccount> accountPtr)
{
	if (accountPtr)
		return true;

	std::cout << "Error -- no valid account selected" << std::endl;
	return false;
}


int main(int argc, char* argv[])
{
	// Declare a Bank instance
	Bank myBank;

	// Lambdas for sub menu functionality
	auto balanceInquiryLambda = [&myBank]()->bool
	{ shared_ptr<BankAccount> ba = myBank.getCurrentAccount().lock();
	if (isAccountValid(ba)) {
		std::cout << "Balance is " << ba->getBalance() << std::endl;
	}

	return true;
	};

	auto depositLambda = [&myBank]()->bool
	{
		shared_ptr<BankAccount> ba = myBank.getCurrentAccount().lock();
		if (isAccountValid(ba)) {
			deposit(ba);
			// Make sure this transaction is saved
			myBank.saveCurrentAccount();
		}
		return true;
	};

	auto withdrawalLambda = [&myBank]()->bool
	{
		shared_ptr<BankAccount> ba = myBank.getCurrentAccount().lock();
		if (isAccountValid(ba)) {
			withdrawal(ba);
			// Make sure this transaction is saved
			myBank.saveCurrentAccount();
		}
		return true;
	};

	// Build our Menu structure
	MenuItem* accountMenuItems[] = {
	  new MenuCommand('1',"Balance Inquiry",balanceInquiryLambda),
	  new MenuCommand('2',"Deposit",depositLambda),
	  new MenuCommand('3',"Withdrawal",withdrawalLambda),
	  new MenuCommand('b',"Back",[]()->bool { return false; }) };

	// Build the accounts menu
	Menu accountMenu(accountMenuItems, 4, '5', "Account");

	// store lambdas in auto variables just for convenience
	auto listAccountsLambda = [&myBank]()->bool { doListAccounts(myBank); return true;  };
	auto newAccountLambda = [&myBank]()->bool { doNewAccount(myBank); return true;  };
	auto selectAccountLambda = [&myBank]()->bool { doSelectAccount(myBank); return true;  };

	MenuItem* mainMenuItems[] = {
	  new MenuCommand('1',"List Accounts",listAccountsLambda),
	  new MenuCommand('2',"New Account",newAccountLambda),
	  new MenuCommand('3',"Select Account",selectAccountLambda),
	  new MenuCommand('4',"Show Active Account",[&myBank]()->bool {
		// Retrieve current account and then either note that no account is
		// selected OR print out the account number of the selected account
		shared_ptr<BankAccount> account = myBank.getCurrentAccount().lock();
		if (!account) {
		  std::cout << "No account selected" << std::endl;
		}
else {
std::cout << "Selected Account Number: " << account->getAccountNumber() << std::endl;
}
return true;
  }),
&accountMenu,
new MenuCommand('b',"Quit",[]()->bool { return false; }) };

	// Build the main menu
	Menu mainMenu(mainMenuItems, 6, '0', "Main");

	// Kick the whole thing off by calling select() on the main menu
	mainMenu.select();
	std::cout << "Done" << std::endl;

}
