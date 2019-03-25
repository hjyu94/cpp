// 동적할당된 메모리에 대한 포인터 변수를 멤버로써 가지고 있는 클래스의 경우
// 복사하거나 대입을 할 때 깊은 복사인지 얕은 복사인지에 따라서
// 대입 연산자 오버로딩, 복사 생성자 구현등에 있어 구현이 좀 까다로워진다.

#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source); // source이 비어있으면 중단

		m_length = strlen(source) + 1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	~MyString()
	{
		delete[] m_data;
	}

	MyString(MyString& source)
		// 호출 후 source가 반드시 사라진다는 보장이 있으면
		// 걔의 주소를 쓱 가져와도 되지만
		// 사라진다는 보장이 없으면 새로 메모리를 할당해줘야 한다.
	{
		// copy constructor
		cout << "copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

	}

	MyString& operator = (const MyString& source)
	{
		// shallow copy
		//this->m_data = source.m_data;
		//this->m_length = source.m_length;

		cout << "Assignment operator" << endl;

		if (this == &source) // prevent self-assignment
			return *this;
		/*
			MyString hello("hello");
			hello = hello;
		*/

		delete[] m_data; // 원래 갖고 있던 메모리 반납

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}


	//MyString& operator = (const MyString& source) = delete;
	//// 구현할 시간이 없어 너무 급할땐 임시로 delete 해버리는 방법도 있다.

	const char* getString() 
	{
		return m_data;
	}
};

int main()
{
	MyString hello("Hello");
	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		MyString copy = hello; 
		// copy가 생성되는거면 복사 생성자가 호출이되고
		// 이럴 필요 없이 copy = hello 꼴이면 대입 연산자가 호출된다.

		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}
	// [디폴트 복사 생성자]
	// m_data = copy.m_data;
	// m_length = copy.m_length;
	// 그대로 주소를 복사함 -> 얕은 복사! shallow copy!

	// copy 객체가 사라지면서 소멸자가 호출됨
	// delete[] copy.m_data; 가 호출되버려서
	// 원래 있던 hello도 getString() 해올 수 없다.
	// 동적 메모리 할당을 사용하는 경우에는 copy constructor나
	// assignment operator를 오버로딩 할 때 깊은 복사를 해줘야 한다.
	
	cout << hello.getString() << endl;


	{
		MyString hello("hello");
		MyString copy = hello; // == MyString copy(hello);
		// copy constructor 호출
	}

	{
		MyString copy;
		copy = hello;
		// assignment operator 호출

		// copy가 생성되는거면 복사 생성자가 호출이되고
		// 새롭게 객체가 생성되지 않고, copy = hello 꼴이면 대입 연산자가 호출된다.

		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}
	cout << hello.getString() << endl;

	return 0;
}