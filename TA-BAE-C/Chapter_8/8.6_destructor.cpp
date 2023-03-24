#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

int main1()
{
	Simple s1(0);
	Simple s2(1);

	return 0;
}

int main2()
{
	Simple* s1 = new Simple(0);
	Simple s2(1);

	/*
		소멸자는 인스턴스가 메모리에서 해제될 때 내부에서 자동으로 호출된다.
		동적할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 메모리가 해제되지 않기 때문에
		delete 으로 메모리를 해제할 때에만 소멸자가 호출된다.

		소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 권장하지 않습니다.
	*/
	delete s1;

	return 0;
}

//

class IntArray
{
private:
	int* m_arr		= nullptr;
	int m_length	= 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor" << endl;
	}

	unsigned int size()
	{
		return m_length;
	}
};

int main3()
{
	while (true)
	{
		IntArray my_int_arr(10000);
	}

	return 0;

	// 위 코드의 문제는 무한루프를 돌면서 메모리 릭이 남는다는 것이다.
	// 무한루프 괄호 직전에 delete[] my_int_arr.m_arr; 를 호출해야 한다.
	// 그런데 소멸자를 쓰는게 훨씬 더 편함.

}

//


class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor" << endl;
	}

	// 이렇게 소멸자를 만들어 둔 경우는
	// 메모리 릭이 남지 않는다.
	~IntArray()
	{
		if(m_arr != nullptr)
			delete[] m_arr;
	}

	unsigned int size()
	{
		return m_length;
	}
};

int main4()
{
	while (true)
	{
		IntArray my_int_arr(10000);
	}

	return 0;
}