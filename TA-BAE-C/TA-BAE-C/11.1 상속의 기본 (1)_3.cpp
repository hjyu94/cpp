// 그런데 난 생성자를 써보고 싶다! 고 할 때 생길 수 있는 문제

#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	// Mother() {} // 기본 생성자

	Mother(const int& i_in)
		: m_i(i_in)
	{
		
	}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}
};

class Daughter : public Mother
{
private:
	double m_d;

public:
	Daughter(const int& i_in, const double& d_in)
	// Mother 클래스의 기본 생성자가 없어서 에러가 생김
	// Daughter 생성자 내부적으로 Mother 클래스의 기본 생성자를 호출하기 때문

	// 해결책1) Mother 클래스의 기본생성자 만들어주기
	// 해결책2) Daughter 생성자 호출할 때 Mother의 생성자 호출해주기
	{ // X
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};

int main()
{
	Mother mom(1024);
	Daughter me(10, 3.14);
}

/***************************************************************/

class Daughter : public Mother
{
private:
	double m_d;

public:
	Daughter(const int& i_in, const double& d_in)
		: Mother(i_in), m_d(d_in)
	// 해결책2) Daughter 생성자 호출할 때 Mother의 기본 생성자 호출해주기
	{}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};