#include <iostream>

using namespace std;

class A
{
private:
	int m_value = 1;
};

class B
{
private:
	int m_value = 2;
};

void doSomething(A& a, B& b)
{
	cout << a.m_value << ", " << b.m_value << endl;
}
// private 변수를 사용해야 하는 함수가 있을 때?
// ---> friend 키워드를 이용해서 해결

/************************************************************/

// [해결책]
// private 변수가 있는 클래스 내에서 
// doSomething 함수를 friend라고 적어주면
// 해당 클래스의 private 변수도 사용 가능하다.

// [전방선언]
// 밑에 어딘가 B의 정의가 있으니
// B에 관한 모르는 내용이 있으면 더 밑에를 읽어보라
class B2;

class A2
{
private:
	int m_value = 1;

	friend void doSomething(A2& a, B2& b); 
	// 전방선언이 없으면 여기서 B2가 뭔지 모름
};

class B2
{
private:
	int m_value = 2;

	friend void doSomething(A2& a, B2& b);
};

void doSomething(A2& a, B2& b)
{
	cout << a.m_value << ", " << b.m_value << endl;
}

void main()
{

}