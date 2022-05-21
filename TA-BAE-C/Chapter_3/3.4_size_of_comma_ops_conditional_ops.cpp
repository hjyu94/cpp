#include <iostream>

int getPrice(bool onSale);

int _3_4()
{
	using namespace std;

	/************** [1] sizeof ***************/
	float a;

	// sizeof(data type), sizeof(var)
	// unit: byte
	sizeof(float);
	sizeof(a);

	// sizeof is an operator, not a function.
	// so below expression is also okay.
	cout << sizeof a << endl;

	/************ [2] comma operator ************/
	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	// === (++x; ++y; int z = y;)
	// comma operator is useful in for loop

	cout << x << " " << y << " " << z << endl;
	
	// Here, ',' is not comma operator, 
	// it is just a separator.
	int a1 = 1, b1 = 10;
	
	int z1;
	z1 = a1, b1;
	// Is ',' a comma operator?
	// a; b; z = b; ???
	//
	// Nope!
	// Assign operator's precedence is higher than comma operator's.
	// === (z = a), b;

	int i = 1, j = 10;
	int k;

	k = (++i, i + j);
	cout << k << endl;


	/************ [3] conditonal operator ************/
	// another name is 'arithmetric if'
	
	bool onSale = true;
	int price;
	
	if (onSale)
		price = 10;
	else
		price = 100;
	
	cout << price << endl;

	// In this case, we cannot declare price as const.
	
	const int price2 = (onSale == true) ? 10 : 100;
	
	// We can declare price2 as const with conditional operator.

	const int price3 = getPrice(onSale);
	
	// It is another solution to make a function.

	// But it is recommneded not to use conditional operator in complicated code.
	// Instead use if expression.

	int x1 = 5;

	// cout << (x1 % 2 == 0) ? "even" : "odd" << endl; 
	// compile error because of operator precedence
	
	cout << ((x1 % 2 == 0) ? "even" : "odd") << endl;
	// It has no error.

	return 0;
}

int getPrice(bool onSale)
{
	if (onSale)
		return 10; 
	else
		return 100;
}
