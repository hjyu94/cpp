#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
	}

	void	setID(const int id) { m_id = id; }
	int		getID() const { return m_id; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2); 
	s2.setID(3);

	// Simple 클래스로 여러개의 객체 s1, s2, s3, ... 을 찍어낼 수 있다.
	// 하나의 클래스에 여러개의 객체를 찍어낼 수 있는데
	
	// Simple::setID 함수는 Simple의 모든 객체들이 공유해서 사용한다.
	// 그렇다면 setID(id) 를 실행할 때 어떤 객체의 m_id에 값을 넣어줄지
	// 어떻게 찾아내는가?

	// 겟, 셋 함수를 각 객체마다 다른 메모리에 저장하고 있을까?
	// s1, s2 따로 따로 자신만의 공간에 겟 셋 함수를 저장하진 않는다

	// s1.setID(2); 는 사실
	// Simple::setID(&s1, 2) 의 기능을 한다 - 문법적으로 이렇게 쓸순 없고 기능상!
	// 보이지 않는 포인터가 내부적으로 들어있는 것

	// 각 인스턴스들이 자신의 포인터를 갖고 있고 이를 this를 통해 볼 수 있다. 
	// this: 해당 객체의 주소값
}

/**************************************************************/

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		cout << this << " constructor" << endl;

		/*this->*/ setID(id); // 내부적으로는 이렇게 생겼던 거
	}

	void	setID(const int id) { /*this->*/ m_id = id; }
	int		getID() const { return /*this->*/ m_id; }
};

// s1.setID(10);
// Simple::setID(&s1, 10);