//
// Menu.h -- Implementation of our Menu MenuItem
//
// Assignment #9
//
#pragma once
#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <vector>
#include "MenuItemH.h"

class Menu : public MenuItem
{

public:
	// Constructor takes four arguments:  C-style array of MenuItems that make up this menu,
	// the size of that array as well as a commandChar and title used to select this menu
	// when it is a sub-menu
	Menu(MenuItem* items[], int size, char commandChar, std::string title);

	// Declaration of member functions we must override
	bool select();
	void display();

private:
	// displayMenu and promptUser are helper functions used when implementing select() and display()
	void displayMenu();
	bool promptUser();

	// Our vector of MenuItem *
	std::vector<MenuItem*> mItems;
};


#endif
