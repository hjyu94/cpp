#include <iostream>
#include "4.2.5_YourConstants.h"

using namespace std;

extern void doSomething_4_2_5();

int main_4_2_5()
{
	cout << "In main.cpp file: " << YourConstants::pi << ", " << &YourConstants::pi << endl;
	doSomething_4_2_5();

	return 0;
}
