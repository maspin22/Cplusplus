#include "MenuH.h"
#include <iostream>

using namespace std;

Menu::Menu(MenuItem menuItems[], int size) {
	for (int i = 0; i < size; i++) {
		items.push_back(menuItems[i]);
	}
}

vector<MenuItem> Menu::getItems()
{
	return items;
}


//implements menu display
void Menu::showMenu()
{
	cout << "---- MENU ----" << endl;
	for (auto i = items.begin(); i != items.end(); ++i) {
		(i)->display();
	}
}

//implements method to receive user input and return commands
char Menu::promptUser() {
	char x;
	cout << "Enter Choice:" << endl;
	cin >> x;
	for (auto i = items.begin(); i != items.end(); ++i) {
		char c = (i)->getPromptChar();
		
		if (x == c) {
			return x;
		}
	}
	return -1;
}


