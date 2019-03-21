#include <iostream>
using namespace std;

class IntList
{
private:
	int m_list[10];

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}
};

void main_1()
{
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	
	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;
}

/************************************************/
// 첨자 연산자를 이용해서 간단하게 해결!

#include <cassert>

class MyList
{
private:
	int m_list[10] = { 0,1,2,3,4,5,6,7,8,9 };

public:
	// 레퍼런스 타입으로 반환해야 l-value로써 역할을 할 수 있다
	// 메모리를 가지고 있기 때문에 list[3] = 10; 이 가능해지다.
	int& operator [] (int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	const int& operator [] (int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
};

void main()
{
	// 오브젝트(객체)가 const인 경우?
	//	: const로 지정한 멤버 함수만 호출할 수 있다.

	const MyList cnst_list;
	MyList my_list;

	cnst_list[3] = 10;
	my_list[3] = 10;

	cout << cnst_list[3] << endl;
	cout << my_list[3] << endl;

	/******************************************/

	MyList* ptr_list = new MyList;

	ptr_list[3] = 10; // Not OK
	(*ptr_list)[3] = 10; // OK
}