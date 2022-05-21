#include <iostream>

int main_5_7()
{
	using namespace std;

	int count = 0;

	// It is possible.
	for (; count < 10; ++count)
	{
		cout << count << endl;
	}


	// It is also possible. infinite loop
	/*for (;; ++count)
	{
		cout << count << endl;
	}*/


	// multiple declaration
	for (int i = 0, j = 0; i < 10; ++i, --j)
	{
		cout << i << " " << j << endl;
	}

	// overflow problem
	for (unsigned int i = 9; i >= 0; --i)
		cout << i << endl;


	return 0;
}