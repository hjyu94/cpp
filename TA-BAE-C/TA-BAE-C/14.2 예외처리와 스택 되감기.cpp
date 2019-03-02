// 스택의 가장 아래쪽에서 예외를 던지게 되면
// 스택을 되감아 가면서 예외를 처리하게 된다.

#include <iostream>
using namespace std;

// void last throw(int): exception specifier
// void last throw(...): exception specifier

// void last throw(): exception specifier
// --> 얘는 하나도 안 던질 것이다!! 라는 걸 명시해준 것
// --> 이렇게 적어놓고 예외를 안 던지면 에러 발생

// throw(int): int를 던져줄 수도 있다.
void last() throw(int)
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;
	throw - 1;

	cout << "End last" << endl; // 출력 X
}

void third()
{
	cout << "third" << endl;
	last();
	// 받지 못함
	cout << "End third" << endl; // 출력 X
}

void second()
{
	cout << "second" << endl;
	try { third(); }
	//catch (int) { cerr << "second caught int exception" << endl; }
	catch (double) { cerr << "second caught double exception" << endl; }
	cout << "End second" << endl;
	// 잡으면 End second까지 잘 출력됨
}

void first()
{
	cout << "first" << endl;
	try { second(); }
	catch (int) { cerr << "first caught int exception" << endl; }
	cout << "End first" << endl;
}

void main()
{
	cout << "Start" << endl;
	try { first(); }
	catch (int) { cerr << "main caught int exception" << endl; }

	catch (...) // catch-all handlers
	{
		cerr << "man caught ellipses exception" << endl;
	}
	// 어떤 타입이던지 다 잡아줌.

	cout << "End main" << endl;
}