//
// CS2024 -- Assignment 2
//
// Michael Aspinwall
// 9-10-2019

#include <iostream>

using namespace std;

class Rectangle {
public:
	Rectangle() {
		mWidth = 0;
		mHeight = 0;
	};
	void setDimensions(int width, int height) 
	{
		mWidth = width;
		mHeight = height;
	};
	int area() {
		return mWidth * mHeight;
	};
	int circumference() {
		return (2 * mWidth) + (2 * mHeight);
	};
	void print() {
		cout << "Rectangle(" << mWidth<< "," << mHeight << ")" << endl;
	};

private:
	int mWidth;
	int mHeight;
};

int main(int argc, char* argv[])
{
	Rectangle rect;
	int width;
	int height;

	rect.print();

	cout << "Rectangle width:" << endl;
	cin >> width;

	cout << "Rectangle height:" << endl;
	cin >> height;

	rect.setDimensions(width, height);
	rect.print();

	cout << "Rectangle area: "<< rect.area() << endl;
	cout << "Rectangle peremiter: "<< rect.circumference() << endl;
}

