//
// Menu.cpp
//
// Assignment #8
//

#include <iostream>
#include "MenuH.h"

//
// The Menu constructor will pass commandChar and title down to the 
// MenuItem constructor but then will utilize items and size to initialize
// the private vector that keeps track of all menu items for this Menu
//
Menu::Menu(MenuItem* items[], int size, char commandChar, std::string title) :MenuItem(commandChar, title)
{
	// Iterate through C-style array and store each pointer in our vector
	for (int i = 0; i < size; i++)
	{
		mItems.push_back(items[i]);
	}
}

//
// private method that will be used to display the menu once
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
// private method used to prompt the user for a character and 
// then look through the vector for the matching MenuItem instance.
// If found, the select() method of that MenuItem is called
//
bool Menu::promptUser()
{
	char command;

	// Prompt the user for a choice
	std::cout << "Enter choice> ";
	std::cin >> command;

	// We have a choice, look through the vector for a matching MenuItem
	for (MenuItem* item : mItems)
	{
		if (command == item->getCommandChar())
		{
			// We found a matching item!   Call that item's select() method
				// and return whatever that item's select() method returns
			return item->select();
		}
	}

	// If we get down here, there was an unknown entry
	std::cout << "Unknown Menu Selection" << std::endl;

	// If an unknown item was found, we return true so that we keep presenting the
	// current menu
	return true;
}


//
// For a Menu object, select() causes the menu to be displayed, the user to be
// be prompted and the select() method of whatever item was chosen to be called
// until we get a "false" back when calling a selected item's select() method
//
bool Menu::select()
{
	// show all menu choices

	for (;;) {
		// Displaly the menu once
		displayMenu();

		// prompt the user and call the selected item's select() method
		bool keepGoing = promptUser();

		// Break out of loop if we aren't going to keep going
		if (!keepGoing)
			break;
	}

	// When we are done with this menu we will tell the "next menu up"
	// to keep going!
	return true;
}


//
// display() is used to display a single entry in a menu with it's command character
//
void Menu::display()
{
	// output our menu's command character and title followed by a ">" to let the user
	// know that it is a submenu
	std::cout << mCommandCharacter << "> " << mTitle << ">" << std::endl;
}
