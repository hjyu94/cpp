#include <iostream>
#include "4.2.3 Header.h"

using namespace std;

extern int a; // 다른 소스 파일(외부)에 있는 전역 변수 num1을 사용
/* extern */ void doSomething(); // 다른 소스 파일(외부)에 있는 함수 doSomething를 사용

void main()
{
	cout << a << endl;
	doSomething();
	cout << "Main.cpp: " << pi << ", " << &pi << endl;
}
