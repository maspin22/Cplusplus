//
// MenuCommand.h -- Implementation of a "Command" MenuItem
//
// A MenuCommand is a single entry which will have some functionality
// tied to it through the use of a function pointer
//
// Assignment 9
//

#ifndef _MENU_COMMAND_H_
#define _MENU_COMMAND_H_

#include <iostream>
#include <functional>
#include "MenuItemH.h"

class MenuCommand : public MenuItem
{
public:
	// The constructor takes the standard commandChar and title, but also
	// takes a function pointer of the function to execute when the command is selected
	MenuCommand(char commandChar, std::string title, std::function<bool()> f);

	// Declaration of the two member function we must override
	bool select();
	void display();

private:
	// The sole member variable is the function pointer of the function to call
	// when this item is selected
	std::function<bool()> functionPtr;
};


#endif
