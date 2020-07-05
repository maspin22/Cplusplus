#include "MenuItemH.h"
#include <iostream>
using namespace std;


MenuItem::MenuItem(string s, char c) {
	title = s;
	input = c;
}

char MenuItem::getPromptChar(){
	return input;
}

void MenuItem::display() {
	cout << input << ") " << title << ':' << endl;
}

string MenuItem::getTitle() {
	return title;
}