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
	* setId() 멤버함수는 인스턴스별로 만들어지는게 아니라 클래스별로 만들어짐.
	* 그러면 각 함수내에서 본인의 인스턴스는 어떻게 찾느냐?
	* this 를 사용하는데 아래와 같은 꼴임.
	* 
	* Simple::setId(&s1, 1);
	* 클래스::멤버함수로 찾아오며 인스턴스가 누군지 넘기고, 그 뒤 해당 함수가 필요로 하는 인자를 넘김.
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

// 위처럼 쓰는게 귀찮다고 생각이 들면 연쇄호출 방식을 사용할 수 있다.
// 자기 자신의 주소를 반환하면 된다.

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
