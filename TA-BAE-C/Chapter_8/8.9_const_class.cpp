#include <iostream>

using namespace std;

int test1()
{
	const int i = 0;
	i = 1; // ����� ������ ������ ������ �� ����.

	return 0;
}

//

class Something
{
public:
	int m_value = 0;

	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }

	// const function ���� ��� �ʵ� �� ���� �Ұ���
	void setValue(int value) const {
		m_value = value;
	}
	int getValue2() const { return m_value; }

	// ����� ���α׷����� �Ϸ��� ��� �Լ����� �⺻������ const�� �����ϴ°��� ����.
};

void test2()
{
	const Something something;
	something.setValue(3);
	// object �� ����� �����ߴµ�
	// setValue �� ��� �ν��Ͻ��� ����ʵ带 �ٲٷ��� ��.
	// ������ ���� �߻�.

	cout << something.getValue() << endl;
	// ���� �������� �ʴ� getter ������ ������ ���� �߻�.
	// �����Ϸ� ���忡���� �Լ� ������ getter ���� setter ������ �߿��Ѱ� �ƴ϶�
	// ȣ���Ϸ��� ��� �Լ��� const ���� �ƴ����� �߿��ϱ� ����

	cout << something.getValue2() << endl;
	// const �� ������ getValue2() �� ȣ�� ����.
	// �Լ��� const �� ����Ǵ� ��� �ش� �Լ� body ���� ��� �ʵ带 �ٲ��� ����.
}

//

void print(Something st)
{
	cout << &st << endl;
	cout << st.m_value << endl;
}

void test2()
{
	Something something;
	cout << &something << endl;
	print(something);

	/*
	* output
	* ------------------
	* Constructor
	* 0001
	* 0002
	*/
	/*
	* print �Լ������� st �� �����ؼ� ����ϰ� �ִµ� constructor �� �ѹ��� �Ҹ���.
	�Դٰ� ���� �ٸ� �ּҰ� ������.
	�� ������ ���簡 �� ���� ���� �����ڶ�°��� �Ҹ��� �����̴�.

	Something(const Somoething& st_in)
	{
		m_value = st_in.m_value;
	}

	�⺻ ���� �����ڴ� ���� ���� �����.
	*/
	
}

// ���� print() �� const reference ������ ����ϰ� �Ǹ�?
void print2(const Something& st)
{
	cout << &st << endl;
}

// �Ʒ��� ���� ���
// something �� ���ο� �ν��Ͻ��� ����� ���� �����ڷ� ���� �Ҵ��ϴ°��� �ƴ϶�
// something ��ü�� �ѱ�� �Ǿ ���� �ּҰ� ������ �ȴ�.
// ���� ����ȭ
void test3()
{
	Something something;
	print2(something);
}

//

#include <string>

class Something2
{
public:
	string m_value = "default";

	// const ���� �ƴ����� �����ε��� ����

	const string& getValue() const { 
		cout << "const version" << endl;
		return m_value; 
	}
	
	string& getValue() { 
		cout << "non const version" << endl;
		return m_value; 
	}
};

int test4()
{
	Something2 something;
	something.getValue() = 10; // reference

	const Something2 something2;
	something2.getValue() = 1024; // const reference
}