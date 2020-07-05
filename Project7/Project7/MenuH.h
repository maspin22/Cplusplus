#include "MenuItemH.h";
#include <vector>;
using namespace std;

//class Menu with fuctions to display the menu and receive input from the user 
class Menu
{
public:
	Menu(MenuItem menuItems[], int size);
	char promptUser();
	vector<MenuItem> getItems();
private:
	vector<MenuItem> items;
};

//overloads global << for menu, displays menu
inline ostream& operator<<(ostream &os, Menu &men)
{
	os << "----MENU----"<<endl;
	vector<MenuItem> items = men.getItems();

	for (MenuItem i: items) {
		os << i ;
	}
	return os;
}