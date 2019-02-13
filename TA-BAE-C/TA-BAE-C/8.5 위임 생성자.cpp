// 위임 생성자: 생성자가 생성자를 호출하는 것

#include <iostream>

using namespace std;

class Student
{
public:
	int		m_id;
	string	m_name;

	/*
		Student(const string& name_in)
			: Student(0, name_in) // 위임 생성자
		{}
	*/

	Student(const int& id_in, const string& name_in)
		: m_id{ id_in }, m_name{ name_in }
	{}
};

int main()
{
	Student std1(0, "ABC");
	Student std2("DEF");
}