#include <iostream>

using namespace std;

// 다른 클래스에서 내 클래스에 있는 private 변수를 사용하고 싶은 경우?
class A
{
private:
	int m_value = 1;
};

class B
{
	void doSomething(A& a)
	{
		cout << a.m_value << endl; // X
	}
};

/************************************************************/
// 해결책

class B1; // 전방 선언

class A1
{
private:
	int m_value = 1;

	friend class B1;
	// B는 내 친구니 private 변수를 넘겨주어도 괜찮다는 표현
};

class B1
{
	void doSomething(A1& a)
	{
		cout << a.m_value << endl; // O
	}
};

/************************************************************/

void main()
{

}