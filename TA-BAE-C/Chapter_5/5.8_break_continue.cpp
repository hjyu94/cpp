#include <iostream>

using namespace std;

void ex_1()
{
	int count(0);

	// infinite loop
	do
	{
		if (count == 5)
			continue;

		cout << count << endl;

		count++;
	} while (count < 10);
}

void ex_2()
{
	int count(0);

	// solved infinite loop
	do
	{
		if (count == 5)
			continue;

		cout << count << endl;
	} while (++count < 10);
}
