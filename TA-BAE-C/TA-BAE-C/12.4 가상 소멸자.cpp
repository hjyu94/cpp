#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	
	/* 1 */
	// virtual ~Base() 
	// 이 경우 자식 클래스의 소멸자를 override 라고 적어줄 수 있다.
	/* 2 */
	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		cout << "Derived()" << endl;
		m_array = new int[length];
	}
	
	/* 1 */
	// virtual ~Derived () override
	/* 2 */
	~Derived ()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
		m_array = nullptr;
	}
};

void main()
{
	{
		// Derived derived(5);

		// Base()		// 부모 클래스 생성자
		// Derived()	// 자식 클래스 생성자
		// ~Derived()	// 자식 클래스 소멸자
		// ~Base()		// 부모 클래스 소멸자
	}

	{
		Derived* derived = new Derived(5);
		// Base()
		// Derived()

		Base* base = derived;
		
		delete base;
		// ~Base()
		// ~Derived() 가 호출되지 않는다는 문제 !!

		// 자식 클래스는 뭘로 만들었는지 모르는 경우가 많다
		// 새 고양이 쥐 토끼 다람쥐 까치...
		// 이런 경우 다형성을 이용해서 부모 클래스의 포인터로
		// 객체를 가리키는 경우가 많다.
		// 그러나 이럴 경우 자식 클래스의 소멸자가 호출되지 않는데 ...

		// 이 경우 소멸자를 virtual로 만들어주면 된다.
		// virtual ~Base(){ ... } 인 경우
		// ~Derived()
		// ~Base()
		// 순으로 호출된다.
	}
}