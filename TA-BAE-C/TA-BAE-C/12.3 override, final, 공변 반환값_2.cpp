#include <iostream>

using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl;
		return this; 
	}
	// 반환하는 데이터 타입이 다르면 오버라이딩이 안 되는데
	// A와 B는 자식 부모 관계라서 오버라이딩이라고 번역한다.
};

void main()
{
	A a; B b;
	A& ref = b;

	b.getThis()->print();	
	// B::getThis()
	// B

	ref.getThis()->print(); 
	// B::getThis()
	// A
	// 내부적으로 A 임을 한번 더 거쳐서 출력함

	cout << typeid(b.getThis()).name() << endl;
	// class B * __ptr64
	cout << typeid(ref.getThis()).name() << endl;
	// class A * __ptr64
}