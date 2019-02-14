#include <iostream>
#include "4.2 헤더파일을 이용한 외부연결3.h"

void doSomething();

using namespace std;

int main()
{
	cout << "In main.cpp: " << Constants::pi << ", 주소: " << &Constants::pi << endl;

	doSomething();
}

// (4.2 MyCosntants.cpp가 없고 4.2 MyConstants.h만 있는 경우에) 
// test.cpp 와 다른 변수의 메모리 공간을 사용하게 된다.
// 상수를 1억개 사용할 때 여러 cpp 파일에서 상수 헤더파일을 인클루드 하면
// 같은 변수더라도 다른 메모리를 사용하는 상수가 1억개나 생김 -> 메모리 낭비 주의해야 함
// 4.2 MyConstants.cpp 를 만들어줘서 이를 해결함.
