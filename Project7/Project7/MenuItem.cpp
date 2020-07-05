#include "MenuItemH.h"
#include <iostream>
using namespace std;


MenuItem::MenuItem(string s, char c) {
	title = s;
	input = c;
}

//implements method to reterive input
char MenuItem::getPromptChar() {
	return input;
}

//implements method to reterive title
string MenuItem::getTitle() {
	return title;
}