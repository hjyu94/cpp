#include <iostream>

int _3_6()
{
	using namespace std;

	// logical NOT
	{
		bool x = true;
		cout << !x << endl;
	}
	
	// logical AND
	{
		bool x = false, y = true;
		cout << (x && y) << endl;
	}

	// logical OR
	{
		bool x = true, y = true;
		cout << (x || y) << endl;
	}

	// Be careful with operator precedence
	{
		// '!x == y' is not the same with '!(x == y)'
		// => (!x) == y
		// => It turns out to be 'false == true' 

		int x = 5, y = 5;
	
		if (!x == y)
			cout << "x does not equal to y" << endl;
		else
			cout << "x equals to y" << endl;
	}

	// short circuit evaluation
	{
		// int x = 1, y = 2;	// case 1
		int x = 2, y = 2;		// case 2

		if (x == 1 && y++ == 2)
		{
			// do something
		}

		cout << y << endl; // 2? 3?
	}

	// De Morgan's Low
	{
		bool x = true, y = false;

		!(x && y);	// 1
		!x && !y;	// 2
		!x || !y;	// 3
		// 1 == 3, 1 != 2
	}

	// XOR
	// if operands are same, then false
	// not same, then true
	{
		bool x = true, y = true ;
		cout << (x != y) << endl;
	}

	return 0;
}