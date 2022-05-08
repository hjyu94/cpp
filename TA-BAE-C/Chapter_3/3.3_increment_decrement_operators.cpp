#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int _3_3()
{
	using namespace std;

	int x = 6, y = 6;
	
	cout << x << " " << y << endl;
	cout << ++x << " " << --y << endl;
	cout << x << " " << y << endl;
	cout << x++ << " " << y-- << endl;
	cout << x << " " << y << endl;
	cout << "=============" << endl;

	int i = 1;
	int j = add(i, ++i); // Do not use
	cout << j << endl; // 3? 4?

	int x1 = 1;
	x1 = x1++; // Do not use, Use ++x1 instead.

	return 0;
}