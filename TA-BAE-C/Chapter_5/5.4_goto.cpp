#include <iostream>
#include <cmath>

using namespace std;

int goto_ex_1()
{
	double x;

tryAgain: // label
	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0.0)
		goto tryAgain;

	cout << sqrt(x) << endl;

	return 0;
}

//int goto_ex_2()
//{
//	goto skip;
//	int x = 5;
//skip:
//	x += 3; // error
//	return 0;
//}
