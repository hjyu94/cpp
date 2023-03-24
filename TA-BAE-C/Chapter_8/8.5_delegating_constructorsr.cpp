#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int		m_id;
	string	m_name;

public:
	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
	{}
	
	// id_in �� ���� name_in �ϳ��� �޴� �����ڸ� ������� �� ��
	// �Ʒ�ó�� ����� ���� ���� ����.
	// ���� ����� �ϴ� �ڵ�� �� ������ ���ƾ� �Ѵ�.
	/*Student(const string& name_in)
		: m_id(0), m_name(name_in)
	{}*/

	// �̰� �ξ� ����.
	Student(const string& name_in)
		: Student(0, name_in)
	{}

};

//


class Student2
{
private:
	int		m_id;
	string	m_name;

public:
	Student2(const int& id_in, const string& name_in)
	{
		init(id_in, name_in);
	}
	
	Student2(const string& name_in)
	{
		init(0, name_in);
	}

	// �ʱ�ȭ �ڵ带 ���� �������� (���� �ʱ�ȭ �ڵ�)
	// �����ڿ��� �ҷ��ͼ� ����ϴ� ��ĵ� �ִ�.
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}
};