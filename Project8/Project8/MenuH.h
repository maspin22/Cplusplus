#pragma once
//
// Menu.h
//
// An instance of Menu is a MenuItem that can appear as a single entry
// in another menu (submenu) or as the top level menu.
// 
// Assignment #8
//

#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <vector>
#include "MenuItemH.h"

class Menu : public MenuItem
{
public:
	// The Menu constructor takes two additional parameters that are specific
	// to Menus.   One is the C-style array of MenuItem pointers and the second
	// is the size of that array
	Menu(MenuItem* items[], int size, char commandChar, std::string title);
	bool select();
	void display();

private:
	// We keep and utilize displayMenu() and promptUser() from earlier assignments
	// as private member functions that select() will use
	void displayMenu();
	bool promptUser();

	// Here's our internal vector of MenuItem * that represent all of the items
	// this menu will display
	std::vector<MenuItem*> mItems;
};

#endif
