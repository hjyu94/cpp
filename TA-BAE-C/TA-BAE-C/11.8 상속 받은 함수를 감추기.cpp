#include <iostream>

using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(const int& value = 0)
		: m_i(value)
	{}

	void print() { cout << "I'm base" << endl; }
};

/**********************************************************************/

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(const double& value)
		: m_d(value)
	{}
};

void main1()
{
	Derived derived(3.14);
	derived.m_i = 10; // protected 라서 외부에서 액세스 불가능
	derived.print(); // public으로 외부에서 사용 가능
}

/**********************************************************************/

class Derived2 : public Base
{
private:
	double m_d;

public:
	Derived2(const double& value)
		: m_d(value)
	{}

	using Base::m_i; // Derived2에서는 m_i를 public처럼 쓸 수 있어짐

private:
	// Base의 print 함수를 사용하지 않게 하는 방법
	/* 1 */
	using Base::print/*()*/; 
	// Derived2에서는 print를 private으로 설정함
	// 괄호는 없어야 함
	
	/* 2 */
	void print() = delete;
};

void main()
{
	Derived2 derived(3.14);
	derived.m_i = 10; // public으로 변해서 외부에서 액세스 가능
	derived.print(); // private으로 변해서 외부에서 액세스 불가능, delete해서 사용 불가능
}