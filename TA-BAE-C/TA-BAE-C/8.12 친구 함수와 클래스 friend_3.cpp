#include <iostream>

using namespace std;

class B; // 전방 선언

class A
{
private:
	int m_value = 1;

	// friend class B1;
	// B는 내 친구니 private 변수를 넘겨주어도 괜찮다는 표현
	// 나의 모든 private을 다 보여주기는 껄끄럽다면

	// B::doSomething 에게만 보여줄 수도 있다.
	friend void B::doSomething(A& a);
	// 여기서 문제 생김!
	// class B가 있다는 건 알겠는데
	// B에 doSomething이 있다는 걸 알 길이 없음
};

class B
{
	void doSomething(A& a)
	{
		cout << a.m_value << endl; // X
	}
};

/************************************************************/
// 그래서 class A, B 순서를 바꿔봄

class A1; // 전방 선언

class B1
{
	void doSomething(A1& a)
	{
		cout << a.m_value << endl;
		// 이러면 또 다른 문제 발생
		// 클래스 A 안에 m_value가 있다는 걸 모르는 상황
	}
};

class A1
{
private:
	int m_value = 1;

	friend void B1::doSomething(A1& a);
};

/************************************************************/
// [해결책]
// 문제의 해당 함수를 선언과 정의를 분리한다

class A2; // 전방 선언

class B2
{
	void doSomething(A2& a);
	//{
	//	cout << a.m_value << endl;
	//}
	// 선언과 정의 분리하기
};

class A2
{
private:
	int m_value = 1;

	friend void B2::doSomething(A2& a);
};

// A2 클래스 내부에 m_value가 있다는걸 알게 되면
// 그때 doSomething 함수의 정의를 써준다.

void B2::doSomething(A2& a)
{
	cout << a.m_value << endl;
}

/************************************************************/

void main()
{ 

}