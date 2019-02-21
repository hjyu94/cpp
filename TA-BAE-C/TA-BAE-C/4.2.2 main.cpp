#include <iostream>
#include "4.2.2 Header.h"

using namespace std;

// [외부 파일에 있는 변수 사용하기]
//	: extern 키워드 생략 불가능
//	: 전역 변수 선언 없이 extern int a; 만 지정하면 컴파일(링크) 에러가 발생한다
//	: 즉, extern int a; 은 전역 변수가 파일 외부에 있다는 것을 표시만 할 뿐 전역 변수 자체를 선언하지는 않습니다.

extern int a; // 다른 소스 파일(외부)에 있는 전역 변수 a을 사용

// [외부 파일에 있는 함수 사용하기]
//	: extern 키워드 생략 가능
/* extern */ void doSomething(); // 다른 소스 파일(외부)에 있는 함수 doSomething를 사용

void main()
{
	cout << a << endl;
	doSomething();
	cout << "Main.cpp: " << pi << ", " << &pi << endl;
}
