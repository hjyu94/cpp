#include <iostream>
using namespace std;

class Something1
{
private:
	int		m_i;
	double	m_d;
	char	m_c;
	int		m_arr[5];

public:
	Something1()
		: m_i(1), m_d(3.14), m_c('a'), m_arr(1, 2, 3, 4, 5) /* 엥 얘는 안되네 */
	{

	}

	// curly bracket: 자동 형변환을 해주지 않음.
	// 좀 더 엄격하므로 안정적인 프로그래밍을 위해 사용되는 경우 있음.
	Something1()
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{1, 2, 3, 4, 5}
	{

	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
	}
};

void test1()
{
	
}

//

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		: m_b(m_b_in)
	{}
};

class A
{
private:
	int		m_i = -1 /* 여기와 생성자 둘 다에서 초기화 하는 경우 생성자의 우선순위가 더 높다. */;
	double	m_d;
	char	m_c;
	int		m_arr[5];
	B		m_b;

public:
	A()
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1, 2, 3, 4, 5 }, m_b (m_i - 1)
	{

	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
	}
};

void test2()
{
	// B 만들고 A 생성
	A a;
}