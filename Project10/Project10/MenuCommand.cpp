//
// MenuCommand.cpp -- Implementation of our "Command" Menu Item
//
// Assignment #9
//

#include <iostream>

#include "MenuCommandH.h"

// The constructor passes commandChar and title to the MenuItem constructor through delegation
// Then stores the function pointer argument in the functionPtr member variable
MenuCommand::MenuCommand(char commandChar, std::string title, std::function<bool()> f) : MenuItem(commandChar, title)
{
	functionPtr = f;
}

//
// This is called whenever our MenuCommand is "selected" by the user
bool MenuCommand::select()
{
	// Check to see if a valid function pointer exists
	if (functionPtr == NULL) {
		// No, no functionality defined.   Just echo the title and state that it isn't implemented yet
		std::cout << "Menu Command: '" << mTitle << "' is not implemented yet!!!" << std::endl;
	}
	else {
		// We have a function pointer, call it!
		return functionPtr();
	}

	return true;
}

//
// display is used to print out a menu choice line for this MenuCommand
//
void MenuCommand::display()
{
	std::cout << mCommandCharacter << "> " << mTitle << std::endl;
}
