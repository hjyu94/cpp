#include <iostream>
#include <initializer_list> // for std::initializer_list
using namespace std;

class IntArray
{
private:
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

		//for (unsigned count = 0; count < list.size(); ++count)
		//	m_data[count] = list[count]; // error

		//// 내부적으로 iterator를 사용한다
		//// 이니셜라이저리스트는 []를 제공하지 않는다.
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

	friend ostream& operator << (ostream& out, IntArray arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << endl;
		return out;
	}
};

int main()
{
	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;

	// 소멸자가 두번 호출되면서 에러가 발생!! 왜일까!! 맞춰봐!!

	return 0;
}