//
// MenuItem.h -- Abstract Base Class for our Menu System
//
// Assignment 9
//
#pragma once

#ifndef _MENUITEM_H_
#define _MENUITEM_H_

#include <iostream>

class MenuItem {
public:
	MenuItem(char, std::string);

	// The  pure virtual functions below define our "interface" for being a "MenuItem"
	virtual bool select() = 0;
	virtual void display() = 0;

	// We should only need a public getter for command char
	// We could add one for title if ever needed
	char getCommandChar() { return mCommandCharacter; }

protected:
	// These are inherited by all derived classes
	// Every MenuItem will have a command character and a title
	char mCommandCharacter;
	std::string mTitle;
};

#endif
