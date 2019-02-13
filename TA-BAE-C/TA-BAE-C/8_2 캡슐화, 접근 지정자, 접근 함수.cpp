#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
// access specifier (public, private-default, protected)

private: // 캡슐화. 클래스 밖에서는 멤버들을 참조할 수 없다. 
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input) {
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	const int& getDay() {
		return m_day;
	}

	void copyFrom(const Date& original) {
		m_month = original.m_month;
		m_day = original.m_month;
		m_year = original.m_month;
	}
};

int main() {
	Date today{ 2,28,2020 }; // uniform initialization
	// 이니셜라이저 값이 너무 많다고 뜨는건 멤버 변수들을 public으로 변경하면 사라진다.

	/*
		today.m_month = 8; // 멤버 변수
		// inaccessable (public: 을 찍어주기 전엔)
	*/

	Date copy;
	copy.copyFrom(today);

}