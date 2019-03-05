#include <iostream>
#include <array>
using namespace std;

template<typename T>
class A
{
public:
	A(const T& input) {}

	void doSomething() 
	{
		cout << typeid(T).name() << endl;
	}

	void test() {}
};

template<>
class A<char>
{
public:
	A(const char& input) {}
	
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}

	// void test() {} // 없음!
};

int main()
{
	A<int>		a_int(1);
	A<double>	a_double(3.14);
	A<char>		a_char('a'); 

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	a_char.test(); // X

	// 그냥 다른 클래스를 구현하는 것과 같으나(A<char>의 객체들은 test 함수 없음)
	// 템플릿의 인스턴시에이션인것처럼 사용할 수 있다.
}