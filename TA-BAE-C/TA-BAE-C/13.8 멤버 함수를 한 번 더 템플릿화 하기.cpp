#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{}


	// TT: doSomething 이라는 함수 내에서만 적용되는 템플릿
	template<typename TT>
	void doSomething1()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	template<typename TT>
	void doSomething2(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	template<typename TT>
	void doSomething3(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();
	a_int.doSomething1<float>();		// int float
	a_int.doSomething2<float>(123.4);	// int double
	// warning C4305 : 'argument' : truncation from 'double' to 'const float'
	a_int.doSomething2(123.4);			// int double
	a_int.doSomething2('a'); // 자동으로 char 타입에 대해 instantiation 된다

	A<char> a_char('A');
	a_char.print();	// A
	a_char.doSomething3(1); // char int 65
	a_char.doSomething3(int()); // char int 65

	return 0;
}

