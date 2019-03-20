#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;

public:	
	Something()
		: s_value(1024) // X
	{
		s_value = 1024; // O
	}
};

int Something::s_value = 1;


// static 멤버 변수를 생성자의 이니셜라이져에서 초기화 할 수 없다.
//
//					static변수		non-static변수	static함수	non-static함수
// non static ftn:		O				O				O			O
// static ftn:			O				X				O			X

/**************************************************************/

class Sth
{
private:
	int m_value;
public:
	void non_print()
	{
		cout << m_value << endl;
	}
	static void print(Sth sth)
	{
		sth.non_print(); // 얘는 가능한데
		non_print(); // 애는 불가능
	}
};

Sth::print(); //-> m_value를 접근할 때 어떤 객체의 변수를 접근해야 하는가...
// 따라서 static 함수에서 non-static변수를 접근할 수 없다.

/**************************************************************/

class Another
{
public:
	class _init
	{
	public:
		_init() { s_value = 999; }
	};

private:
	static int s_value;
	static _init s_initializer;

public:
	/*Another()
		: s_value(1024) // X
	{}*/
};
int Another::s_value = 1;
Another::_init Another::s_initializer; // ??????
// int a; 꼴?

// 얘가 만들어지면서 inner 클래스의 생성자가 초기화되고
// inner 클래스의 생성자에서 s_value 가 초기화 된다.

// inner class에서 간접적으로 사용

void main()
{

}