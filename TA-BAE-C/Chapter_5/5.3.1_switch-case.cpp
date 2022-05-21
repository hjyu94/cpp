#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
};

//void printColorName(Colors color)
//{
//	if (color == Colors::BLACK)
//		cout << "Black" << endl;
//	else if (color == Colors::WHITE)
//		cout << "WHITE" << endl;
//	// ...
//}

void printColorName(Colors color)
{
	switch (color)
	{
	case Colors::BLACK:
		cout << "Black" << endl;
		break;
	}

	//switch (static_cast<int>(color))
	//{
	//case 0:
	//	// ...
	//	break;
	//}
}

int main_5_3_1()
{
	int x;
	cin >> x;

	// Test 0, 1, 2
	// Watchout missing break;
	switch (x)
	{
	case 0:
		cout << "Zero";
		// break;
	case 1:
		cout << "One";
		// break;
	case 2:
		cout << "Two";
		// break;
	}
	cout << endl;


	// With enum
	printColorName(Colors::BLACK);


	// Is it possible?
	switch (x)
	{
		int a; // declaration is ok
		// int b = 5; // but initialization is not possible
	case 0:
		break;
	case 1:
		break;
	default:
		cout << "Undefined input " << x << endl;
		// break; // optional
	}


	return 0;
}