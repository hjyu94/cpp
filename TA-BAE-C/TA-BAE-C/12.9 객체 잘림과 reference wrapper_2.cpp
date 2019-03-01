// 부모보단 자식 클래스가 더 많은 정보를 가지게 되는 경우가 대다수.

// 자식 클래스는 좀 더 구체적인 클래스로
// 부모 클래스보다 더 많은 변수나 함수를 가지고 있을 수 있다.
// 함수 오버로딩도 되어 있을 수 있다.

// 보다 작은 부모의 객체에 보다 큰 자식 클래스의 객체를 강제로 대입하는 경우?
// 자식 클래스에만 가진 정보는 모두 사라지게 되는데
// 이러한 것들을 객체 잘림이라고 한다.
// 작은 그릇에 큰 객체를 담으려고 하다보니 생기는 문제!

#include <iostream>
#include <vector>
#include <functional> // for reference wrapper
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
	Base b;
	Derived d;

	std::vector<Base> my_vec;
	my_vec.push_back(b);
	my_vec.push_back(d);
	// derived를 넣었지만 push_back 함수 내에서 객체 잘림이 발생해서
	// 다형성이 발현되지 않는다.

	for (auto & e : my_vec)
		e.print();
	// I'm Base
	// I'm Base

	/**********************************************************/
	
	// std::vector<Base&> my_vec;
	// 이렇게 만들면 객체가 잘려나가지 않고
	// 다형성이 생길까 싶지만
	// 벡터에 레퍼런스들을 모아놓을 수 없음.

	/**********************************************************/

	// [포인터 벡터를 이용한 해결]
	std::vector<Base*> my_vec2;
	my_vec2.push_back(&b);
	my_vec2.push_back(&d);

	for (auto & e : my_vec2)
		e->print();
	// I'm Base
	// I'm Derived

	/**********************************************************/

	// [reference wrapper을 이용한 해결]
	std::vector<std::reference_wrapper<Base>> my_vec3;
	// my_vec3은 Base의 레퍼런스를 저장하는 벡터가 된다.
	
	Base		base;
	Derived		derived;
	
	Base&		b_ref = base;
	Derived&	d_ref = derived;

	my_vec3.push_back(b_ref);
	my_vec3.push_back(d_ref);

	for (auto & e : my_vec3)
		e.get().print();
	// get 위에 마우스를 올려놓고 보면
	// 반환 값이 Base의 참조 변수임을 알 수 있다.

	// I'm Base
	// I'm Derived

	return 0;
}