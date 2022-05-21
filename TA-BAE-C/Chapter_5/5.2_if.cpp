#include <iostream>

using namespace std;

int main_5_2()
{
	int x;
	cin >> x;

	// If the code inside if is over 2 lines, 
	// then execute only first line.

	if (x > 10)
		cout << x << " is greater than 10" << endl;
	else
		cout << x << " not is greater than 10" << endl;
		cout << "second line" << endl;
		

	// About scope
	
	if (1)
		int x = 5;
	else
		int x = 6;
	cout << x << endl;


	// About confusing indent without exact {}, case = 15
	
	if (x >= 10)
		if (x >= 20)
			cout << "x is between 10 and 20" << endl;
	else
		cout << "..." << endl;


	// Ternary operator
	
	if (true)
		"True";
	else
		"False";

	(true) ? "True" : "False";


	// Be careful of semicolon (;)
	
	if (x > 10); // <-- if is useless, this is null statement
	{
		x = 1;
	}

	if (x > 10)
		;


	// x = 0 vs x == 0

	if (x = 0)
		cout << x << endl;


	return 0;
}