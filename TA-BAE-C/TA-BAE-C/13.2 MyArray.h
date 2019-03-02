#pragma once
#include <assert.h> // for assert
#include <iostream>

template<typename T>
// T는 변수명처럼 생각하면 된다
// template<class T>
// 뒤에 세미콜론 없음 주의

class MyArray
{
private:
	int	 m_length;
	T*	 m_data;

public:
	MyArray()
	{
		m_length = 0;
		m_data = new T[m_length];
	}

	MyArray(int length)
	{
		m_length = length;
		m_data = new T[length];
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < m_length);
		//return *(m_data + index);
		return m_data[index];
	}

	int getLength();

	// main.cpp 에서 MyArray.h 만 인클루드 한 상태
	// 정의는 헤더파일에 없고 cpp 파일에 있음
	// main.cpp 에서 MyArr<char> my_arr(10);으로 인스턴시에이션 할 때
	// MyArray.cpp 파일을 컴파일 할 때는 알 수가 없어서?

	// main.cpp 에서 #include "13.2 MyArray.cpp" 하면 해결되기는 하나
	// 프로젝트가 커지면 cpp 파일을 인클루드하면 문제

	void print();
};




// 클래스의 멤버 함수의 선언과 정의를 분리할 때 템플릿을 사용하면 다른 문법이 사용된다.
template<typename T>
void MyArray<T>::print() // O
// void MyArray::print() // X
{
	using namespace std;
	for (int i = 0; i < m_length; ++i) cout << m_data[i] << ' ';
	cout << endl;
}
