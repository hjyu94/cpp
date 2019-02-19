#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "Constructor" << endl; }
	~A() { cout << "Destructor" << endl; }

	void print() { cout << "Hello" << endl; }
};

void main()
{
	A a;
	a.print();
	cout << endl;

	A().print(); // 익명객체 사용
	// 1) A()가 r-value 처럼 작동한다
	// 2) 재사용이 불가능하다. (print를 여러번 부를 수 없다)
	// 3) 사용 후 바로 소멸자가 호출된다.
	cout << endl;

	A().print();
	cout << endl;

}