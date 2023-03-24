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
		�Ҹ��ڴ� �ν��Ͻ��� �޸𸮿��� ������ �� ���ο��� �ڵ����� ȣ��ȴ�.
		�����Ҵ����� ������� ��쿡�� ������ ����� �ڵ����� �޸𸮰� �������� �ʱ� ������
		delete ���� �޸𸮸� ������ ������ �Ҹ��ڰ� ȣ��ȴ�.

		�Ҹ��ڸ� ���α׷��Ӱ� ���� ȣ���ϴ� ���� ��κ��� ��� �������� �ʽ��ϴ�.
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

	// �� �ڵ��� ������ ���ѷ����� ���鼭 �޸� ���� ���´ٴ� ���̴�.
	// ���ѷ��� ��ȣ ������ delete[] my_int_arr.m_arr; �� ȣ���ؾ� �Ѵ�.
	// �׷��� �Ҹ��ڸ� ���°� �ξ� �� ����.

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

	// �̷��� �Ҹ��ڸ� ����� �� ����
	// �޸� ���� ���� �ʴ´�.
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