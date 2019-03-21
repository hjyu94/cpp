#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
public:
	unsigned m_length = 0;
	int* m_data;

public:
	IntArray(int length = 0)
		: m_length(length)
	{
		cout << "기본 생성자" << endl;
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int>& list)
		: IntArray(list.size())
	{
		cout << "생성자 호출" << endl;
		int count = 0;
		for (auto& e : list)
			m_data[count++] = e;
	}

	IntArray(IntArray& _arr)
	{
		cout << "복사 생성자 호출" << endl;
	}

	~IntArray()
	{
		cout << "소멸자호출" << endl;
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << endl;
		return out;
	}
	/*
	IntArray& operator = (IntArray& _arr)
	{
		cout << "복사 대입 생성자" << endl;
		return *this;
	}

	IntArray& operator = (const std::initializer_list<int>& _arr)
	{
		cout << "복사 대입 생성자" << endl;
		return *this;
	}*/
};

int main()
{
	IntArray int_array{ 1,2,3,4,5 }; // 생성자 호출
	cout << int_array << endl;

	IntArray int_array2; // 기본 생성자
	int_array2 = { 1, 2, 3, 4, 5 }; // 복사 대입 생성자
	cout << int_array2.m_length << endl; // 0 출력됨

	cout << int_array2 << endl;

	return 0;
}