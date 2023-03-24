#include <iostream>
using namespace std;

int generateId()
{
	static int s_id = 0;
	return ++s_id;
}

int test1()
{
	cout << generateId() << endl; // 0
	cout << generateId() << endl; // 1
	cout << generateId() << endl; // 2

	return 0;
}

//

class Something
{
public:
	// static 멤버 변수는 initialize 할 수 없다.
	//static int m_value = 1;
	static int m_value;
};

// define in cpp
// header 에 두면 컴파일 에러가 발생한다.
int Something::m_value = 1;

int test2()
{
	cout << &Something::m_value << " " << Something::m_value << endl;

	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;

	Something::m_value = 1024;

	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;
}

//

class Something2
{
public:
	// const static 변수는 선언과 동시에 초기화 해야 한다.
	const static int s_c_value = 1;
};

// class 밖에서 초기화 할 수 없다.
Something2::s_c_value = 1;


//

class Something3
{
public:
	// 템플릿이나 변수로 const 를 선언하는 경우 런타임때 값이 정해질 수도 있지만
	// constexpr 은 컴파일 타임에 값이 정해져야 한다.
	static constexpr int s_c_value = 1;
};