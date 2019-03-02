#pragma once
#include <iostream>
#include <array>
#include <assert.h>

template<typename T, unsigned int T_SIZE>
// T_SIZE가 컴파일타임에 정해져있어야 한다.
class MyArray
{
private:
	// int m_length;
	T	*m_data;
	// T	m_data[T_SIZE]
	// 해도 상관이 없으나 stack에 데이터가 저장된다.

public:
	MyArray()
	{
		m_data = new T[T_SIZE];
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		using namespace std;
		for (int i = 0; i < T_SIZE; ++i) cout << m_data[i] << ' ';
		cout << endl;
	}
};

