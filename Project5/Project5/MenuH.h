#pragma once

//enumerates menu codes, assumes value +1 that of the code before
enum MenuItemCode {
	cUnknownItem = 0,
	cNewAcc,
	cLstAcc,
	cQuitItem
};

//class Menu with fuctions to display the menu and receive input from the user 
class Menu
{
public:
	void showMenu();
	MenuItemCode promptUser();
};