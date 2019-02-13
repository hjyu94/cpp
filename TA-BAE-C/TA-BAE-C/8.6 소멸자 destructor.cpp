#include <iostream>

using namespace std;

class Simple
{
public:
	int m_id;

	Simple(int x)
	{
		m_id = x;
		cout << "Constructor " << m_id << endl;
	}

	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

void main1()
{
	Simple s1(0);
	Simple s2(1);

	// 0 생성
	// 1 생성
	// 1 소멸
	// 0 소멸
}
// 자기 영역을 벗어날 때 소멸된다. 

/***************************************************/

void main2()
{
	Simple* s1 = new Simple(0); // 메모리 동적할당
	Simple s2(1);

	delete s1;

	// 0 생성
	// 1 생성
	// 0 소멸
	// 1 소멸
}

/***************************************************/

// 소멸자를 언제 쓰느냐?

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in) // #1
	{
		m_length = length_in;
		m_arr = new int[m_length];
	}

	// 메모리 누수 발생을 대비해서 소멸자에 기능 구현
	~IntArray()
	{
		if (m_arr != nullptr) delete[] m_arr;
	}

	int getLength() const { return m_length; } // #2
};

void main()
{
	while (true)
	{
		IntArray my_int_arr(10000); // 메모리 누수 발생
									// delete[] my_int_arr.m_arr; // private이라 액세스 불가
									// --> 이럴 경우를 대비해서 클래스의 소멸자에 기능 구현
	}
}

/***************************************************/

/*
#1 매개변수가 const인 경우
: 해당 함수 내에서 값이 바뀌지 않는 경우

#2 클래스의 멤버 함수가 const인 경우
: 해당 함수가 속한 객체의 멤버를 변경하지 않는 경우

*/