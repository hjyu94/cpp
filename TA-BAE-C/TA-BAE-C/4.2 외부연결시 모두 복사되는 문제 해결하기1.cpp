#include <iostream>
#include "4.2 외부연결시 모두 복사되는 문제 해결하기.h"

void doSomething();

using namespace std;

int main()
{
	cout << "In main.cpp: " << Constants::pi << ", 주소: " << &Constants::pi << endl;

	doSomething();
}
