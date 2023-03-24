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

	int getDay() // 복사가 되니까 메모리가 낭비되려나?
	{
		return m_day;
	}

	int& getDate2() // 그럼 레퍼런스 변수로 반환하면 되지, 근데 그러면 get 이후 값을 바꿔버릴 수 있기 때문에
	{
		return m_day;
	}

	const int& getDate3() // 레퍼런스 변수는 상수로 반환하고, 수정하려면 반드시 setter 를 통하도록 코드 짜는게 좋다.
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

	// 파라미터로 넘어오는 original 은 this 와 다른 객체이더라도
	// 같은 클래스이면 private 변수를 접근할 수 있다.
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
