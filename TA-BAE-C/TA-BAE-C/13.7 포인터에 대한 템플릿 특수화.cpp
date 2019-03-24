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

	void print()
	{
		cout << m_value << endl;
	}
};

// 포인터의 경우에만 특별하게 작동했으면 좋을 때
template<class T>
class A<T*>
{
private:
	T* m_value;

public:
	A(/*const */T* input)
		: m_value(input)
	{}

	void print()
	{
		cout << *m_value << endl;
	}
};

void main()
{
	A<int> a_int(123);
	a_int.print(); // 123


	// 포인터에 대한 템플릿 특수화를 써주지 않으면
	// 주소값이 출력 되지만
	//
	// 특수화를 정의해주고 나면
	// 주소값을 참조해서 값을 출력해줄 수 있다.

	int temp = 456;
	A<int*> a_int_ptr(&temp);
	a_int_ptr.print(); 

	double temp_d = 3.14;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();
}

