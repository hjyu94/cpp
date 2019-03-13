#include <iostream>

#include "4.2.3 Header.h"
// == extern const double pi;

int a = 3;

void doSomething()
{
	using namespace std;
	cout << "Another.cpp: " << pi << ", " << &pi << endl;
}