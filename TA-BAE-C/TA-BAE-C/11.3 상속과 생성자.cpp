#include <iostream>

using namespace std;

class Base
{
public:
	int i_value;

	Base(const int& i_in)
	{
		i_value = i_in;
	}
};

class Derived : public Base
{
public:
	double d_value;

	Derived(const double& d_in)
	{
		d_value = d_in;
	}

	// 에러나는 이유?
	// 상속받는 경우 Derived 생성자의 
	// "이니셜라이져리스트"에 "부모의 기본 생성자"가 생략되어 있다.

	/*
		Derived(const double& d_in)
			: Base() -> 요로코롬!
		{
			d_value = d_in;
		}
	*/

	// 현재 부모인 Base 클래스의 기본 생성자가 없으므로 에러
};

/********************************************************/
// 해결책1) Base에 기본 생성자 만들어주기
// 해결책2) 이니셜라이져리스트에 새로 만든 Base의 생성자 호출

class Base
{
public:
	int i_value;

	Base(const int& i_in /*= 0*/) 
		// = 0 을 붙여주면 기본 생성자도 같이 만드는 효과! 
		// (인자가 없을 때 디폴트 값 0 을 넣어주기 때문에)
		// 따라서 Derived 에 기본생성자가 사라지더라도 문제가 생기지 않는다.
	{
		i_value = i_in;
	}
};

class Derived : public Base
{
public:
	int d_value;

	Derived(const double& d_in)
	{
		d_value = d_in;
	}
};