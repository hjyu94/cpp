// 기본 클래스를 만들 때 
// 자식 클래스에게 이러이러한 걸 반드시 해야 한다는 제약을 걸고 
// 기본 클래스가 이러이러한 목적으로 만들어졌다는 것을 명시하는 방법

// 순수 가상 함수: 바디가 없어서 자식 클래스에서 반드시 오버라이딩 해줘야 한다

// 추상 클래스: 순수 가상 함수가 하나라도 포함이 된 클래스
// (주로 기본 클래스를 추상 클래스로 만듦)

// 인터페이스 클래스: 순수 가상함수로만 이루어진 클래스

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	/*
		// Animal 클래스의 speak는 일반화된 함수로 
		// 말을 하라고 하면 무슨 말을 해야 할지 모른다.
		virtual void speak() const
		{
			cout << m_name << " ???" << endl;
		}
	*/

	// ??? 를 뭐하러 띄우냐 그냥 바디를 지워랏!
	// 단 이를 상속한 자식 클래스에서는 반드시 오버라이딩해서 정의해줘야 한다.
	// pure virtual function
	virtual void speak() const = 0;
};

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name)
	{}

	// speak 함수 오버라이딩 X
};

int main()
{
	Animal ani("Hi");
	// 추상 클래스는 오브젝트를 만들 수 없다.
	ani.speak(); 
	// 만들 수 없으니 호출할 방법도 없다.

	Cow cow("hello");
	// 자식 클래스에서 가상함수를 오버라이딩 하지 않으면
	// 그 클래스의 인스턴스를 만들 수 없음.
	
	// 설계자 입장에서 speak 함수를 꼭 자식 클래스에서 오버라이딩해서
	// 쓰라고 하고 싶으면 해당 함수를 가상 함수로 만들어 주면
	// 까먹더라도 컴파일러가 너 이거 오버라이딩하지 않았다고 빨간줄로 알려줌
	// 깜박하고 구현을 빼먹는 실수를 줄여줌

	return 0;
}