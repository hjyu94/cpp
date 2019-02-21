// 부모 클래스에서 정의한 기능을 수행 하고
// 덧붙여서 뭔가를 더 수행하는 함수를 만들고 싶은데
// 함수 명은 똑같이 짓고 싶을 때 --> 오버라이딩

#include <iostream>
using namespace std;

class Base
{
private:
	int m_i;

public:
	Base(const int& value = 0)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}

	// 입출력 연산자 오버로딩
	friend ostream& operator << (ostream& out, Base base)
	{
		out << base.m_i; // friend 함수는 private 멤버도 접근 가능
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(const double& value)
		: m_d(value)
	{}

	void print()
	{
		// print(); // 자연스럽게 부모 클래스의 함수를 호출해주지 않을까? // ㄴㄴ 무한루프 빠짐
		Base::print(); // 부모 클래스의 함수 호출하는 방법
		cout << "I'm derived" << endl;
	}

	// 입출력 연산자 오버로딩
	friend ostream& operator << (ostream& out, Derived derived)
	{
		// Base:: ??? --> static cast! 업 캐스팅 해줘서 출력하자
		out << static_cast<Base>(derived) << endl;
		out << derived.m_d;
		return out;
	}
};


void main()
{
	Base base(5);
	Derived derived(3.14);
	
	base.print();
	cout << endl;

	derived.print();
	cout << endl;

	cout << base << endl;
	cout << derived << endl;
}