using namespace std;
#include <string>
#include <iostream>

class MenuItem
{
public:
	MenuItem(string title, char  input);
	char getPromptChar();
	string getTitle();
private:
	string title;
	char input;
};

//overloads global << for menuItems, displays menuItems
inline ostream& operator<<(ostream &os, MenuItem &m)
{
	os << m.getPromptChar() << ") " << m.getTitle() << ":"<< endl;
	return os;
}