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
	
	// id_in 값 없이 name_in 하나만 받는 생성자를 만들려고 할 때
	// 아래처럼 만들면 아주 좋지 않음.
	// 같은 기능을 하는 코드는 한 곳으로 몰아야 한다.
	/*Student(const string& name_in)
		: m_id(0), m_name(name_in)
	{}*/

	// 이게 훨씬 낫다.
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

	// 초기화 코드를 따로 만들어놓고 (만능 초기화 코드)
	// 생성자에서 불러와서 사용하는 방식도 있다.
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}
};