//
// Menu.cpp -- Implementation of our Menu MenuItem
//
// Assignment #9
//

#include <iostream>
#include "MenuH.h"

// Constructor processes the input array and size but passes the commandChar and title
// to MenuItem constructor via delegation
Menu::Menu(MenuItem* items[], int size, char commandChar, std::string title) :MenuItem(commandChar, title)
{
	for (int i = 0; i < size; i++)
	{
		mItems.push_back(items[i]);
	}
}

//
// displayMenu is now private;  displays all choices in this menu
//
void Menu::displayMenu()
{
	std::cout << "==== " << mTitle << " MENU ====" << std::endl;
	for (MenuItem* item : mItems)
	{
		item->display();
	}
}

//
// promptUser will ask the user for a choice and, when received, will
// figure out which MenuItem it belongs to and will call select() on that
// MenuItem
//
bool Menu::promptUser()
{
	char command;

	std::cout << "Enter choice> ";
	std::cin >> command;

	// Loop through all menu items in this menu and find the commandChar
	// that matches what the user typed in
	for (MenuItem* item : mItems)
	{
		if (command == item->getCommandChar())
		{
			// We found the item the user selected, call select() on it
			return item->select();
		}
	}

	// If we get down here, there was an unknown entry
	std::cout << "Unknown Menu Selection" << std::endl;
	return true;
}


bool Menu::select()
{
	// show all menu choices

	for (;;) {
		displayMenu();
		bool keepGoing = promptUser();

		// Break out of loop if we aren't going to keep going
		if (!keepGoing)
			break;
	}

	// When we are done with this menu, tell the "next menu up" to keep going!
	return true;
}


//
// Display a single menu item for this Menu.   This is used when presenting this
// menu as a submenu in another menu
//
void Menu::display()
{
	std::cout << mCommandCharacter << "> " << mTitle << ">" << std::endl;
}
