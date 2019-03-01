// 위에서 virtual로 만들면 그 밑에 있는 함수도 모두 virtual 로 자동변경된다.
// 생략해도 그만이지만 소스를 읽는 사람들을 위해서 virtual을 명시해주면 좋다.

// 오버라이딩 할 때 리턴 타입이 다르면 어떻게 되는가
// D::print의 함수를
// int print() { cout << "D" << endl; } 와 같이
// 리턴타입을 바꾸면 C가 아니라 A까지 올라가서 어쩌하다고 에러 표시해줌
// D 클래스는 C를 직접적으로 상속받았지만 쭈욱 타고 올라가서 최상단의 부모까지 컴파일러가 추적해주는 것

#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
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
	A a; B b; C c; D d;
	A& ref = a;
	ref.print(); // A
	ref = b;
	ref.print(); // A
	ref = c;
	ref.print(); // A
	ref = d;
	ref.print(); // A
	cout << endl;

	// B& ref1 = a; // X
	// ref1.print(); // X
	B& ref1 = b;
	ref1.print(); // B
	ref1 = c;
	ref1.print(); // B
	ref1 = d;
	ref1.print(); // B
}