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
		: m_i(1), m_d(3.14), m_c('a'), m_arr(1, 2, 3, 4, 5) /* �� ��� �ȵǳ� */
	{

	}

	// curly bracket: �ڵ� ����ȯ�� ������ ����.
	// �� �� �����ϹǷ� �������� ���α׷����� ���� ���Ǵ� ��� ����.
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
	int		m_i = -1 /* ����� ������ �� �ٿ��� �ʱ�ȭ �ϴ� ��� �������� �켱������ �� ����. */;
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
	// B ����� A ����
	A a;
}