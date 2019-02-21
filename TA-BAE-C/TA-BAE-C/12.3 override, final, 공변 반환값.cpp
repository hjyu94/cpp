#include <iostream>
using namespace std;

class A
{
public:
	virtual void print(int x) const { cout << "A" << endl; }
};

class B : public A
{
public:
	// 내가 원래 하려던 건 오버라이딩인데
	// 파라매터의 데이터 타입이 달라지면 컴파일러는 오버로딩 했다고 번역함

	void print(short x) { cout << "B" << endl; }
	/*
		A& ref = b;
		ref.print(1);
	*/
	// 이 함수를 출력하면 B가 아니라 A가 출력됨

	// 함수는 파라미터가 다르면 오버라이딩을 할 수 없다.
	// 함수 입장에서는 오버라이딩이 아니라 오버로딩 했나 보다 싶음
	
	virtual void print(short x) const override { cout << "B" << endl; }
	// 예비조치 방법? -> override 키워드!
	// 오버라이딩이라고 적어놓으면 이 함수는 무조건 오버라이딩 할 함수!
	// 혹시 모를 컴파일 에러를 찾아준다
	// 실수로 int를 short라고 적은 거라고 생각해서 빨간줄로 에러를 표시해줌
};

class C : public B
{
public:
	virtual void print() final { cout << "C" << endl; }
	// 해당 함수는 오버라이딩 할 수 없다고 막고 싶은 경우
};

class D : public C
{
public:
	virtual void print() { cout << "D" << endl; }
	// 부모 클래스인 C에서 해당 함수를 final로 적어주어서
	// 자식 클래스인 D에서 오버라이딩 할 수 없다.
};

void main()
{
	B b;
	A& ref = b;
	ref.print(1);
}