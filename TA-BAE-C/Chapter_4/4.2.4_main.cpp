#include <iostream>
#include "4.2.4_MyConstants.h"

using namespace std;

extern void doSomething_4_2_4();
// extern keyword is not necessary.

int _4_2_4()
{
	// In main.cpp file and test.cpp file,
	// pi variable are not the same.
	// they have other memory.
	cout << "In main.cpp file: " << MyConstants::pi << ", " << &MyConstants::pi << endl;
	doSomething_4_2_4();

	return 0;
}
