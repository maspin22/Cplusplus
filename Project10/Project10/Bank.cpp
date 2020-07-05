//
// Bank.cpp
//
// Bank implementation for A10
//

#include "BankH.h"
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
//
// Simple constructor
//
Bank::Bank()
{
	// Make sure our mCurrentAccount member variable starts off as NULL
	// (Could also have used C++11 nullptr)
	weak_ptr<BankAccount> mCurrentAccount = shared_ptr<BankAccount> (nullptr);

	// Open our file

	// The following gets around what I think is a shortcoming of the file modes in C++
	// First, we open in append mode (ios::app).   This will cause the file to be created if it
	// doesn't exist already.  
	bankFile.open("data.dat", std::ios::app);
	if (!bankFile) {
		// Uh oh.   We should really do someting better here, but just return for now.
		std::cout << "An error occured trying to open the file" << std::endl;
		return;
	}
	else {
		// Success!  Close the file because we need it open in read/write mode the rest of the way
		bankFile.close();
	}

	// Now that the file should exist (even if empty), open in read/write mode
	bankFile.open("data.dat", std::ios::in | std::ios::out);
	if (!bankFile) {
		// Uh oh, not sure how this could happen, but we'll return
		std::cout << "An error occurred trying to open bank file" << std::endl;
		return;
	}

	// Make sure we are back at the beginning of the file
	bankFile.seekp(0);

	// Read in all accounts
	int recordNumber = 0;

	while (!bankFile.eof()) {
		// Arbitrarily long C-style string buffer
		char buffer[80];

		// Read the data, one field at a time
		bankFile.getline(buffer, 79);
		std::cout << "Read in account#: " << buffer << std::endl;
		if (!strlen(buffer)) {
			// extra newline or something.  We might see this at the end of every file as we
			// might read in an empty string once before the EOF bit is set and eof() returns true
			std::cout << "skipping invalid record..." << std::endl;
			continue;
		}

		// Convert account # to integer
		int accountNumber = atoi(buffer);
		bankFile.getline(buffer, 79);
		std::cout << "Read in name: " << buffer << std::endl;

		// Convert account name to C++ string
		std::string accountName = buffer;
		bankFile.getline(buffer, 79);
		std::cout << "Read in balance: " << buffer << std::endl;

		// Convert balance to integer
		int balance = atoi(buffer);

		// Create a new bank account instance (dynamically) and pass all the data just read in
		shared_ptr<BankAccount> loadedAccount(new BankAccount(accountNumber, accountName, balance));
		std::map<int, shared_ptr<BankAccount> >::value_type nextRecord(accountNumber, loadedAccount);
		mAccounts.insert(nextRecord);

		// Specify the offset in the data file for this record.  It's equal to whatever
		// our recordNumber counter is at
		std::map<int, int>::value_type nextOffset(accountNumber, recordNumber);
		mAccountOffsets.insert(nextOffset);

		// Increment record number and get ready for the next iteration
		recordNumber++;
	}

	// We're at eof, so we need to clear the eof state
	bankFile.clear();
}



//
// Prompt the user for an account number and, if found, make it the selected account
//
void Bank::selectAccount()
{
	int accountNumber = 0;

	std::cout << "Enter an account number to select: ";
	std::cin >> accountNumber;

	// Check to make sure that the account number is valid
	if (mAccounts[accountNumber] != NULL) {
		mCurrentAccount = mAccounts[accountNumber];
	}
	else {
		std::cout << "Account " << accountNumber << " does not exist." << std::endl;
	}
}


//
// Prompt the user for account number, customer name and initial balance,
// then dynamically allocate a new BankAccount instance and store in the vector
//
void Bank::newAccount()
{
	std::string name;
	int accountNumber;
	int openingBalance;

	// Prompt the user
	std::cout << "NEW ACCOUNT:  " << std::endl;
	std::cout << "ENTER ACCOUNT NUMBER:  ";
	std::cin >> accountNumber;
	std::cout << "ENTER ACCOUNT NAME:    ";
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << "ENTER OPENING BALANCE: ";
	std::cin >> openingBalance;

	// Dynamically allocate new BankAccount
	shared_ptr<BankAccount> ba ( new BankAccount(accountNumber, name, openingBalance));

	// Make sure allocation succeeded
	if (ba != NULL) {
		// Store in map
		// Start by calculating the offset for this record in our data file.   Whatever the size
		// of our map is (number of entries), that value will be the next offset
		int nextOffset = mAccounts.size();

		// Insert BankAccount record
		std::map<int, shared_ptr<BankAccount> >::value_type recordToInsert(accountNumber, ba);
		mAccounts.insert(recordToInsert);

		// Insert offset record
		std::map<int, int>::value_type offsetRecord(accountNumber, nextOffset);
		mAccountOffsets.insert(offsetRecord);

		// save in file
		saveAccount(ba);
	}
	else {
		std::cout << "Could not store bank account #" << accountNumber << std::endl;
	}
}


//
// List out account information for every account in the vector
//
void Bank::listAccounts()
{
	std::cout << std::endl;
	std::cout << "ACCT# : NAME : BALANCE" << std::endl;

	for (std::pair<int, shared_ptr<BankAccount> > element : mAccounts)
		// Iterate through vector and print out info for each BankAccount
	{
		std::cout << element.second->getAccountNumber() << " : " << element.second->getName() << " : " << element.second->getBalance() << std::endl;
	}
	std::cout << std::endl;
}

// saveCurrentAccount is just a convenience function that calls saveAccount with
// the currently selected account
void Bank::saveCurrentAccount()
{
	saveAccount(mCurrentAccount.lock());
}

// saveAccount saves the account data in our file!
void Bank::saveAccount(shared_ptr<BankAccount> ba)
{
	// First, retrieve the offset for this account
	std::map<int, int>::iterator p = mAccountOffsets.find(ba->getAccountNumber());

	std::cout << "Saving account# " << ba->getAccountNumber() << std::endl;

	if (p != mAccountOffsets.end())
		std::cout << "Offset is " << p->second << std::endl;
	else {
		// If the offset wasn't found, just return
		std::cout << "offset not found" << std::endl;
		return;
	}

	// Calculate byte offset and advance to that part of the file
	// Record size is 25
	int startOfRecordOffset = 25 * p->second;
	std::cout << "calling seekp with value: " << startOfRecordOffset << std::endl;
	bankFile.seekp(startOfRecordOffset);

	// Now write the data using manipulators to help us format it!
	bankFile << "\n" << std::left << std::setw(5) << ba->getAccountNumber() << std::endl;
	bankFile << std::left << std::setfill('\0') << std::setw(10) << ba->getName() << std::endl;
	bankFile << std::left << std::setw(7) << ba->getBalance() << std::endl;
}


