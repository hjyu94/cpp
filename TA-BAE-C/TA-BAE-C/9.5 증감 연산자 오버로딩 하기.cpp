#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit) : m_digit(digit) {}

	// prefix
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	// post: parameter에 dummy로 아무거나 들어가야 함
	Digit operator ++ (int)
	{
		Digit temp(m_digit); // 현재값을 저장한 temp 객체
		++(*this); // using prefix operator 내 값은 나중에 더해져 있어야함
		return temp;
	}

	friend ostream& operator << (ostream& out, const Digit& digit)
	{
		out << digit.m_digit;
		return out;
	}
};

void main()
{
	// 기본 자료형
	int a = 10;
	cout << ++a << endl;	// 11
	cout << a << endl;		// 11
	cout << a++ << endl;	// 11
	cout << a << endl;		// 12

	// 사용자 정의 자료형
	Digit d(5);
	cout << ++d << endl;	// 6
	cout << d << endl;		// 6
	cout << d++ << endl;	// 6
	cout << d << endl;		// 7
}