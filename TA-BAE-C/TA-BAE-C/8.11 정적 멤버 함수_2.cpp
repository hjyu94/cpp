#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;
	int m_value;

public:
	static int static_fcn()
	{
		cout << m_value << endl;	// X
		return this->s_value;		// X
	}
	// # static 멤버 함수에서는 this 포인터를 사용할 수 없다. #
	// this를 이용해서 얻어와야 하는 멤버 변수도 사용할 수 없다.

	int non_static_fcn()
	{
		cout << m_value << endl;	// O // 현재 가비지 값 들어있음
		return this->s_value;		// O
	}
};

/*ㄴㄴ:static*/ int Something::s_value = 1;

void main()
{
	Something sth;

	int(Something::*non_static_fptr)()	= &Something::non_static_fcn; // O
	int(*static_fptr)()					= &Something::static_fcn; // O

	/*******************************************************************/

	// [선언하기]
	int(Something::*non_static_fptr)() = sth.non_static_fcn; // X
	// error C3867 : 'Something::non_static_fcn' 
	// : non - standard syntax; use '&' to create a pointer to member

	int(Something::*non_static_fptr)() = &(sth.non_static_fcn); // X
	// Something의 멤버 함수 포인터를 선언하겠다.
	// error C2276 : '&' 
	// : illegal operation on bound member function expression

	int(Something::*non_static_fptr)() = &Something::non_static_fcn; // O
	// 각 인스턴스마다 temp를 각각의 주소에 갖고 있는게 아님
	// 매개변수로 인스턴스의 주소를 넘겨주는 방식을 사용함.
	// temp는 sth이 아니라 Something에 속해있는 함수에요 라는 의미를 써야 함.
	
	// [호출하기]
	cout << (sth.*non_static_fptr)() << endl << endl;
	// sth를 써주지 않으면 작동하지 않는다.
	// non static 멤버 함수는 this 포인터에 종속된 형태로 작동하기 때문에
	// this 포인터를 알려주기 위해 sth. 를 앞에 붙여줘야 한다.

	// non static 멤버 함수는 내부에 this pointer가 생략되어 사용되는 것

	/*******************************************************************/

	// int(Something::*static_fptr)() = &Something::static_fcn; // X
	// error C2440 : 'initializing' 
	// : cannot convert from 'int (__cdecl *)(void)' to 'int (__cdecl Something::* )(void)'

	int(*static_fptr)() = &Something::static_fcn; // O
	cout << static_fptr() << endl; // O
	// static 멤버 함수는 특정 인스턴스와 상관 없이 실행시킬 수 있는 포인터 형태로 나온다

}
