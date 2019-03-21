#pragma once

#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
private:
	int m_iLength;
	T*	m_data;

public:
	MyArray(int _iLength)
		: m_iLength(_iLength)
	{
		m_data = new T[_iLength];
	}

	~MyArray()
	{
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}
	}

	int getLength() const;

	void print();

	T& operator [] (int index)
	{
		return m_data[index];
	}
};

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_iLength; ++i)
		cout << m_data[i] << ' ';
	cout << endl;
}