#include <iostream>
using namespace std;

void doSomething()
//{
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl;
}
//}

// 함수 전체에 대해서 try를 걸 수도 있다.
// 인덴트 레벨이 하나 줄어듦.

int main1()
{
	try
	{
		doSomething();
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	// doSomething() 안에서 catch에 걸렸으므로
	// main에서는 잡지 않음.
	return 0;
}

// 출력
// Catch in doSomething()

/*******************************************************/

class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0) throw 1;
	}
};

class B : public A
{
public:
	B(int x)
		: A(x)
	{}
};

int main2()
{
	try
	{
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

	return 0;
}

// [출력] Catch in main()

/*******************************************************/

class A2
{
private:
	int m_x;
public:
	A2(int x) : m_x(x)
	{
		if (x <= 0) throw 1;
	}
};

class B2 : public A2
{
public:
	B2(int x) try /**/ : A2(x) {} /**/
	// 주석 사이에 있는게 모두 try
	// 이니셜라이져리스트, 괄호 안 둘다
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		// 여기에 throw; 가 없지만 있는 것처럼 작동함
	}
};

int main()
{
	try
	{
		B2 b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
}
// [출력]
// Catch in B constructor
// Catch in main