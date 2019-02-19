#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;
};

class Child : public Mother
{
public:
	Child()
		: m_i(10) // 이니셜라이져에서는 초기화 불가능
	{
		// 생성자 내부에서는 초기화 가능한데
		this->m_i = 10;
		this->Mother::m_i = 10;
	}
};

/******************************************************/

class A
{
public:
	int m_i;

	A()
3		: m_i(1) // 초기화 해줘야 메모리가 잡힘
2	{
4		cout << "Mother construction" << endl;
5	}
};

class B : public A
{
public:
	double m_d;

	B()
6		:m_d(3.14) // , m_i(1) // X
1	{
7		cout << "Child construction" << endl;
8	}
};

void main()
{
	B child;

	// [결과]
	// Mother construction
	// Child construction
}

// 부모에 있는 모든 걸 초기화 한 다음에
// 자식의 것들을 초기화 한다.

// 그래서 자식의 생성자 이니셜라이져리스트에서는
// 부모의 멤버변수를 초기화 할 수 없다.

// 부모 생성자에서 변수가 초기화 된 다음에는 가능하므로
// 이니셜라이져리스트가 아닌 생성자 블록 안에서는 초기화 가능하다

/******************************************************/

class A
{
public:
	int m_i;
	
	A(const int& i_in)
4		: m_i(i_in)
3	{
5		cout << "Mother construction" << endl;
6	}
};

class B : public A
{
public:
	double m_d;

	B()
/*2,7*/		: A()/* 사실 얘가 생략되어 있던 것*/, m_d(3.14) // , A(1024) 
			// 앞에 있으나 뒤에 있으나 상관 없음
1	{
8		cout << "Child construction" << endl;
9	}
};

void main2()
{
	B child;
}

/******************************************************/

/*
	부모의 변수들부터 모두 초기화 한 후에
	자식의 변수들을 초기화한다.
*/

