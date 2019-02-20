// 위에서 virtual로 만들면 그 밑에 있는 함수도 모두 virtual 로 자동변경된다.
// 생략해도 그만이지만 소스를 읽는 사람들을 위해서 virtual을 명시해주면 좋다.

// 오버라이딩 할 때 리턴 타입이 다르면 어떻게 되는가
// D::print의 함수의 리턴타입을 바꾸면 C가 아니라 A까지 올라가서 어쩌하다고 에러 표시해줌

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
};

void main()
{
	cout << "2 version" << endl;
	A a; B b; C c; D d;

	A& ref1_1 = a;
	ref11.print(); // A
	A& ref1_2 = b;
	ref2.print(); // A
	A& ref1_3 = c;
	ref3.print(); // A
	A& ref1_4 = d;
	ref4.print(); // A
	cout << endl;

	// B& ref1 = a; // X
	// ref1.print(); // X
	B& ref2_1 = b;
	ref2_1.print(); // B
	ref1 = c;
	ref1.print(); // B
	ref1 = d;
	ref1.print(); // B
}