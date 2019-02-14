#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
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
		: m_i(i_in), m_d(d_in) // X 
	// 이니셜라이저 사용 불가능, Mother 멤버 변수를 public으로 해도 불가능
	{}

	int getValue() const
	{
		return m_d;
	}
};

int main()
{
	Daughter me(10, 3.14);
}

