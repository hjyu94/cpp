#include <iostream>
#include <typeinfo>

enum Color
{
	COLOR_BLACK = -3,
	COLOR_RED = 10,
	COLOR_GREEN = 10,
	BLUE,
};

enum Feeling
{
	HAPPY,
	BLUE,
	SAD,
};


int main()
{
	using namespace std;

	Color paint = COLOR_BLACK;
	int ipaint = COLOR_BLACK;

	Color house(COLOR_RED);
	Color house2{ COLOR_RED };

	house = ipaint; // X
	house = (Color)ipaint; // O

	if (COLOR_RED == COLOR_GREEN)
	{
		cout << "It's the same color" << endl;
	}
}