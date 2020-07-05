#pragma once
#include "MenuItemH.h"
#include <vector>;

//class Menu with fuctions to display the menu and receive input from the user 
class Menu
{
public:
	Menu(MenuItem menuItems[], int size);
	void showMenu();
	char promptUser();
	vector<MenuItem> getItems();
private:
	vector<MenuItem> items;
};

inline ostream& operator<<(ostream& os, Menu& men)
{
	os << "----MENU----" << endl;
	vector<MenuItem> items = men.getItems();

	for (MenuItem i : items) {
		os << i;
	}
	os << std::endl;
	return os;
}