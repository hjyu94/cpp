#include <iostream>

// 선언은 여기저기 할 수 있는데 정의는 한 곳에서 하면 다른곳에서 할 수 없다.
// 메모리를 차지하는 작업은 한번만 실행할 수 있다는 의미.

namespace work1::work11 // C++11
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

namespace work2
{
	int a = 3;
	void doSomething()
	{
		a += 33;
	}
}

int _4_1()
{
	using namespace std;

	int apple = 5;
	cout << apple << endl;
	
	{
		apple = 1;
		cout << apple << endl;
	}
	cout << apple << endl;

	{
		int apple = 3;
		cout << apple << endl;
	}
	cout << apple << endl;

	cout << "==================" << endl;

	// scope resolution operator "::"

	work1::work11::a;
	work1::work11::doSomething();

	work2::a;
	work2::doSomething();

	return 0;
}