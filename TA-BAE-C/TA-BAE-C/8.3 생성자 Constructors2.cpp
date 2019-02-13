#include <iostream>

using namespace std;

class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
public:
	Second sec;

	First()
	{
		cout << "class First constructor()" << endl;
	}
};

int main()
{
	// 멤버 변수의 생성자가 먼저 호출된다.

	First fir;
	// Second 생성자 호출
	// First 생성자 호출
}