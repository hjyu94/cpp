#include <iostream>

int _3_2()
{
	using namespace std;

	int x = 1;
	int y = 1 - -x; // no whitespace for unary operator for reading easily 
	
	int a = 7;
	int b = 4;

	// If both operands are integer, 
	// then result is integer
	cout << a / b << endl; 

	// If one of two operands is float, 
	// then result is also float.
	cout << a / float(b) << endl;
	cout << float(a) / b << endl;

	// -2.5? then floor, 
	// so result is -2
	cout << -5 / 2 << endl;
	
	// If one of two operands is minus,
	// then result is also minus.
	cout << -5 % 2 << endl;
	
	int z = x;
	z += y; // z = z + y;

	return 0;
}