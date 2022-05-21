#include <iostream>

using namespace std;

int main_5_6()
{
	// If declaration is in do, there will be an error in while statement
	int selection;

	do
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;
		cin >> selection;
	} while (selection <= 0 || selection >= 5); // necessary semicolon
	
	cout << "You selected " << selection << endl;

	return 0;
}