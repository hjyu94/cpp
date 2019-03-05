#include <iostream>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report"<< endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array Exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	int& operator [] (const int& index)
	{
		// 멤버함수에서도 throw를 할 수 있다.
		//if (index < 0 || index >= 5) throw - 1;
		//if (index < 0 || index >= 5) throw Exception();
		if (index < 0 || index >= 5) throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;
	
	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		cout << "doSomething() ";
		e.report();
		// ArrayException의 객체도 받아주긴 하지만
		// 부모의 report 함수가 호출된다.

		// re-throw 개념 // main에서의 catch에서 또 받아줌
		throw e; // 객체잘림 // Exception에서 받아줌
		throw;   // ArrayException에서 받아주게 됨
	}
	catch (ArrayException& e)
	{
		cout << "doSomething() ";
		e.report();
		// 위에서 먼저 catch되어 실행되지 않음.
		// 둘의 순서를 바꾸면 ArrayException의 report 함수가 호출된다.
	}
} 

void main()
{
	try
	{
		doSomething();
	}

	catch (Exception& e)
	{
		cout << "main() ";
		e.report();
	}

	catch (ArrayException& e)
	{
		cout << "main() ";
		e.report();
	}
}