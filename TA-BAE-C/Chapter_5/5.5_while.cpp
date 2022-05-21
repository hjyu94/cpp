#include <iostream>

using namespace std;

int main_5_5()
{
	// Be aware of overflow !!!
	unsigned int count = 10;
	while (count >= 0)
	{
		if (count == 0) cout << "zero";
		else cout << count << endl;

		count--;
	}
	
	return 0;
}