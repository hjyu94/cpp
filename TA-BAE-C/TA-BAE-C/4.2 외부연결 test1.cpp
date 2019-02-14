
// [외부연결]
// test.cpp 의 doSomething()를 사용하고 싶은 경우
// 1) cpp 파일 직접 인클루드(가급적 사용 X)
// 2) 전방선언

#include <iostream>

using namespace std;

// [전방선언을 이용해 외부연결]

void doSomething();
// extern void doSomething();
// extern 명시 해주지 않아도 됨. 생략되어 있음.

extern int a;
// extern 명시 안 해주면 에러난다

void main()
{
	doSomething();

	cout << a << endl;
}