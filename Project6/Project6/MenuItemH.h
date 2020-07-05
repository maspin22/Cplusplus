#pragma once
using namespace std;
#include <string>;

class MenuItem
{
public:
	MenuItem(string title, char  input);
	void display();
	char getPromptChar();
	string getTitle();
private:
	string title;
	char input;
};

inline ostream& operator<<(ostream& os, MenuItem& m)
{
	os << m.getPromptChar() << ") " << m.getTitle() << ":" << endl;
	return os;
}