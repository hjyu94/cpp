#include <iostream>
using namespace std;

int generateId()
{
	static int s_id = 0;
	return ++s_id;
}

int test1()
{
	cout << generateId() << endl; // 0
	cout << generateId() << endl; // 1
	cout << generateId() << endl; // 2

	return 0;
}

//

class Something
{
public:
	// static ��� ������ initialize �� �� ����.
	//static int m_value = 1;
	static int m_value;
};

// define in cpp
// header �� �θ� ������ ������ �߻��Ѵ�.
int Something::m_value = 1;

int test2()
{
	cout << &Something::m_value << " " << Something::m_value << endl;

	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;

	Something::m_value = 1024;

	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;
}

//

class Something2
{
public:
	// const static ������ ����� ���ÿ� �ʱ�ȭ �ؾ� �Ѵ�.
	const static int s_c_value = 1;
};

// class �ۿ��� �ʱ�ȭ �� �� ����.
Something2::s_c_value = 1;


//

class Something3
{
public:
	// ���ø��̳� ������ const �� �����ϴ� ��� ��Ÿ�Ӷ� ���� ������ ���� ������
	// constexpr �� ������ Ÿ�ӿ� ���� �������� �Ѵ�.
	static constexpr int s_c_value = 1;
};