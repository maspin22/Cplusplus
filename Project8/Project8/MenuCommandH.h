//
// MenuCommand.h
//
// A MenuCommand is an instance of an object that represents one
// command in our menu system
//
// Assignment 8
//

#ifndef _MENU_COMMAND_H_
#define _MENU_COMMAND_H_

#include <iostream>
#include <functional>
#include "MenuItemH.h"

class MenuCommand : public MenuItem
{
public:
	// A MenuCommand takes a command character and title
	MenuCommand(char commandChar, std::string title, std::function<bool()> f);

	// Declare the methods we must implement if we derive from MenuItem
	bool select();
	void display();
private:
	std::function<bool()> go;
};


#endif

