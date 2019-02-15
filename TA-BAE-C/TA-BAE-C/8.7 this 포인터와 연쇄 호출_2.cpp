#include <iostream>

using namespace std;

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	void add(int value) { m_value += value; }
	void add1(int value) { m_value += value; }
	void add2(int value) { m_value += value; }
	void add3(int value) { m_value += value; }

	void print()
	{
		cout << m_value << endl;
	}
};
	
int main()
{
	Calc cal(10);
	cal.add(10);
	cal.add1(1);
	cal.add2(3);

	cal.print();
}

/**************************************************/

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	Calc& add(int value) { m_value += value; return *this; }
	Calc& add1(int value) { m_value += value; return *this; }
	Calc& add2(int value) { m_value += value; return *this; }
	Calc& add3(int value) { m_value += value; return *this; }

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	Calc cal(10);
	cal.add(1).add(2).add(3).print(); // chaining member 

	Calc(10).add(1).add(2).add(3).print(); // chaining member 
}
