#include <iostream>
#include "4.2.4_MyConstants.h"

void doSomething_4_2_4()
{
	using namespace std;
	cout << "In test.cpp: " << MyConstants::pi << ", " << & MyConstants::pi << endl;
}