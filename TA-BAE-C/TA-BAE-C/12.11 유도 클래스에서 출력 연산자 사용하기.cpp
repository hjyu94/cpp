// 유도 클래스에서 출력 연산자를 오버라이딩해서 쓰려면?

#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	// friend ftn 은 멤버 함수 아님
	// 자식 클래스에서 애를 직접 오버라이딩 할 수 없음.

	// 그래서 파라매터로 오브젝트를 넘겨주고 개를 이용해 멤버 함수 호출
	// 두번째 인자로 Derived 객체가 들어오면 다형성이 발현된다.
	friend std::ostream& operator << (std::ostream &out, const Base &b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	// print 함수 오버라이딩
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	cout << b << endl;

	Derived d;
	cout << d << endl;

	Base& b_ref = d;
	cout << b_ref << endl;

	return 0;
}