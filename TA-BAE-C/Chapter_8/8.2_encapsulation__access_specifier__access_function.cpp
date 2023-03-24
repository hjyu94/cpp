#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date
{
	int m_month;
	int m_day;
	int m_year;
};

void initialize()
{
	Date today{ 8, 4, 2025 };

	Date today2;
	today2.m_month = 8;
	today2.m_day = 4;
	today2.m_year = 2025;
}

//

class Date2
{
//public: // class default access specifier: private
	int m_month;
	int m_day;
	int m_year;
};

void initialize2()
{
	Date2 today{ 8, 4, 2025 };

	Date2 today2;
	today2.m_month = 8;
	today2.m_day = 4;
	today2.m_year = 2025;
}

//

class Date3
{
private: // For encapsulation
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}
};

void initialize3()
{
	Date3 today;
	today.setDate(8, 4, 2025);
}

//

class Date4
{
private: // For encapsulation
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	int getDay() // ���簡 �Ǵϱ� �޸𸮰� ����Ƿ���?
	{
		return m_day;
	}

	int& getDate2() // �׷� ���۷��� ������ ��ȯ�ϸ� ����, �ٵ� �׷��� get ���� ���� �ٲ���� �� �ֱ� ������
	{
		return m_day;
	}

	const int& getDate3() // ���۷��� ������ ����� ��ȯ�ϰ�, �����Ϸ��� �ݵ�� setter �� ���ϵ��� �ڵ� ¥�°� ����.
	{
		return m_day;
	}
};

void initialize4()
{
	Date3 today;
	today.setDate(8, 4, 2025);
}

//


class Date5
{
private: // For encapsulation
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	// �Ķ���ͷ� �Ѿ���� original �� this �� �ٸ� ��ü�̴���
	// ���� Ŭ�����̸� private ������ ������ �� �ִ�.
	void copyFrom(const Date5& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
};

void initialize5()
{
	Date5 today;
	today.setDate(8, 4, 2025);

	Date5 copy;
	copy.copyFrom(today);
}
