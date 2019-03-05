// 메모리 관리가 안되어 메모리 누수가 발생할 수도 있다
#include <iostream>
using namespace std;

void doSomething()
{
	try
	{
		int* i = new int[10000];

		// do something with i
		throw "error";

		delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	// catch 안에서 i 를 delete 해 줄 수가 없다는 문제
	// 해결법? unique_ptr<int> up_i(i); 를 사용한다.
	// 변수가 사라질 때(중괄호 끝, 예외처리 될 때) 메모리를 자동으로 해제한다.
}

/****************************************************************/

class A
{
public:
	~A() { throw "error"; }
	// 소멸자에서는 예외를 던질 수 없다.
};

void doSomething2()
{
	try { A a; }
	catch (...) { cout << "Catch" << endl; }
}

/****************************************************************/

