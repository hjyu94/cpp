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

	// [SOLUTION]
	// friend ostream& operator << (ostream& out, IntArray arr)
	// 파라매터로 레퍼런스가 아니라 객체가 들어가면 복사 생성자가 호출된다.
	// 얕은 복사가 일어나 원본과 같은 메모리 주소를 갖게 된다.
	// 이후 함수가 끝날 때 함수 스택에 있는 객체의 소멸자가 호출되므로
	// heap 메모리에서 지워진다. 따라서 원본도 지워져 버리게 된다.

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
	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;
	// 위까지는 잘 출력된다

	IntArray int_array2;
	int_array2 = { 1, 2, 3, 4, 5 };
	cout << int_array2 << endl;
	// 여기에서 에러가 난다! 왜일까!!!

	return 0;
}