#include <iostream>
#include <string>
using namespace std;

int computeDamage(int weapon_id)
{
	if (weapon_id == 0) // sword
	{
		return 1;
	}
	if (weapon_id == 1) // hammer
	{
		return 2;
	}
	// ...
}

// Enumerated types is more easily read.
// enum is user-defined data type


/**********************************************/


enum Color
{
	COLOR_BLACK,
	COLOR_RED,
	BLUE,
	COLOR_GREEN, // trailing-comma is possible
};// semi-colon is necessary.
// enum is stored as integer.

enum Feeling
{
	HAPPY,
	JOY,
	TIRED,
	// BLUE,
};
// error C2365: 'BLUE': redefinition; previous definition was 'enumerator'
// Even though two enum in include other, duplicated name is not possible

int main_4_7__1()
{
	using namespace std;

	// initialization
	Color paint = COLOR_BLACK;
	Color house(COLOR_GREEN);
	Color apple{ COLOR_RED };

	return 0;
}



/**********************************************/


enum Alphabet
{
	A = -3,
	B,
	C = 5,
	D = 5,
};

int main_4_7__2()
{
	Alphabet alphabet = A;
	cout << alphabet << " " << A << endl;

	if (C == D)
		cout << "C is equal to D" << endl;

	return 0;
}



/**********************************************/


int main_4_7__3()
{
	{
		int color_id = COLOR_RED;
		cout << color_id << endl; // possible
	}

	// error C2440: 'initializing': cannot convert from 'int' to 'Color'
	{
		// Color my_color = 3; // not possible
	}

	// But, casting is possible
	{
		Color my_color = static_cast<Color>(3);
	}

	// cin is not possible
	{
		// cin >> my_color;
	}
	
	// Detouring way
	{
		Color my_color;
		int in_number;
		cin >> in_number;

		if (in_number == COLOR_BLACK)
			my_color = COLOR_BLACK;

		if (in_number == static_cast<Color>(0))
			my_color = static_cast<Color>(0);
	}

	{
		Color my_color;
		string str_input;
		std::getline(cin, str_input);

		// what if input is "color_black" or input contains typo?
		if (str_input == "COLOR_BLACK")
			my_color = static_cast<Color>(0);
	}

	return 0;
}