// 부모보단 자식 클래스가 더 많은 정보를 가지게 되는 경우가 대다수.

// 자식 클래스는 좀 더 구체적인 클래스로
// 부모 클래스보다 더 많은 변수나 함수를 가지고 있을 수 있다.
// 함수 오버로딩도 되어 있을 수 있다.

// 보다 작은 부모의 객체에 보다 큰 자식 클래스의 객체를 강제로 대입하는 경우?
// 자식 클래스에만 가진 정보는 모두 사라지게 되는데
// 이러한 것들을 객체 잘림이라고 한다.
// 작은 그릇에 큰 객체를 담으려고 하다보니 생기는 문제!

#include <iostream>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	Base& b = d; 
	// Base 의 레퍼런스의 Derived 객체를 넣어줌
	// 다형성이 발현된다.

	b.print();
	// Base의 참조변수로 선언되었지만
	// Derived 클래스의 print 함수가 호출된다.

	Base b2 = d; 
	// b2에 d를 복사해서 넣고 있다.
	// Derived에만 있었던 정보(m_j)는 어떻게 될까?

	b2.print();
	// 자식 클래스의 함수들을 실행할 때 
	// 필요한 추가적인 변수들도 싹 잘려 나가서
	// Base 클래스에만 있는 정보들만 호출된다.
	// 결국 다형성이 사라진다.

	doSomething(d);
	// 다형성이 발현되어 I'm derived가 호출된다.

	// 만약 
	// void doSomething(Base& b) 가 아니라
	// void doSomething(Base& b) 였다면
	// 다형성이 사라지고 I'm based가 호출된다.
	
	return 0;
}