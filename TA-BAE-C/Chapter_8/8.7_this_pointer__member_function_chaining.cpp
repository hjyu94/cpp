#include <iostream>
using namespace std;

class Simple
{
private:
	int		m_id;

public:
	Simple(int id)
	{
		this->setId(id); // member selection operator ->
		this->m_id;

		cout << this << endl;
	}

	void setId(const int& id) { m_id = id; }
	const int& getId() { return m_id; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setId(2);
	s2.setId(3);

	cout << &s1 << ", " << &s2 << endl;

	return 0;

	/**
	* setId() ����Լ��� �ν��Ͻ����� ��������°� �ƴ϶� Ŭ�������� �������.
	* �׷��� �� �Լ������� ������ �ν��Ͻ��� ��� ã����?
	* this �� ����ϴµ� �Ʒ��� ���� ����.
	* 
	* Simple::setId(&s1, 1);
	* Ŭ����::����Լ��� ã�ƿ��� �ν��Ͻ��� ������ �ѱ��, �� �� �ش� �Լ��� �ʿ�� �ϴ� ���ڸ� �ѱ�.
	* == s1.setId(1);
	*/
}

//

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	void add(int value) { m_value += value; }
	void sub(int value) { m_value -= value; }
	void mul(int value) { m_value *= value; }
};

int test()
{
	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mul(2);
}

// ��ó�� ���°� �����ٰ� ������ ��� ����ȣ�� ����� ����� �� �ִ�.
// �ڱ� �ڽ��� �ּҸ� ��ȯ�ϸ� �ȴ�.

class Calc2
{
private:
	int m_value;

public:
	Calc2(int init_value)
		: m_value(init_value)
	{}

	Calc2& add(int value) { m_value += value; return *this;  }
	Calc2& sub(int value) { m_value -= value; return *this; }
	Calc2& mul(int value) { m_value *= value; return *this; }
};

int test2()
{
	Calc2 cal(10);
	cal.add(10).sub(1).mul(2);

	Calc2(10).add(10).sub(1).mul(2);
}
