#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;


class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data;

public:
	IntArray(int length)
		: m_length(length)
	{
		cout << "기본 생성자" << endl;
		m_data = new int[length];
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << endl;
		return out;
	}
};

int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 10, 20, 30 };
	// auto 타입: (std::initializer_list<int>)
	// 함수 3개: begin(), end(), size()

	cout << "begin(): " << *il.begin() << endl;
	cout << "end(): " << il.end() << endl;
	cout << "size(): " << il.size() << endl;
	cout << endl;

	// 이니셜라이저 리스트를 파라미터로 갖는 생성자가 없으면 에러가 난다.
	IntArray int_array{ 1,2,3,4,5 }; // error
	cout << int_array << endl;
	
	return 0;
}
