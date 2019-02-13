#include <iostream>
#include "4.2 My Constants.h"

extern int a = 123; // 초기화를 시켜줘야 메모리가 할당된다.

void doSomething()
{
	using namespace std;

	cout << "Hello" << endl;

	cout << "In test.cpp: " << Constants::pi << ", 주소: " << &Constants::pi << endl;

}