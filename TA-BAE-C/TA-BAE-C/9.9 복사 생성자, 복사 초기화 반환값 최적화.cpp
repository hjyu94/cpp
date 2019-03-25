
#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	// 초기화해주지 않고 출력할 시 런타임 에러 발생한다.

public:
	Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{
		cout << "constructor called" << endl;
		assert(den != 0);
	}

	void print()
	{
		cout << m_numerator << "/" << m_denominator << endl;
	}

	Fraction(const Fraction& fraction)
		: m_numerator(fraction.m_numerator)
		, m_denominator(fraction.m_denominator)
	{
		cout << "copy constructor called" << endl;
	}

	friend ostream& operator << (ostream& out, const Fraction& f)
	{
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

void main()
{
	Fraction frac(3, 5);

	Fraction fr_copy(frac); // copy constructor 호출
	Fraction fr_copy2 = frac; // 이때도 copy constructor 호출
	// == Fraction fr_copy2(frac);

	Fraction fr_copy3(Fraction(3, 5)); 
	// 새로 객체를 만들고 걔를 인자로 넣어주면 복사 생성자가 호출되지 않음
	// Fraction fr_copy(3,5); 로 자동으로 컴파일러가 바꿔줌.
	
	cout << frac << " " << fr_copy << endl;
	cout << endl;

	/******************************************************/

	Fraction result = doSomething();
	cout << &result << endl;

	// [디버그 모드]
	// constructor called
	// 0x100 - doSomething stack
	// copy constructor called 
	// 0x200 - main stack

	// [릴리즈 모드]
	// constructor called
	// 0x100 - main stack
	// 0x100 - main stack

	// return value optimization -> 컴파일러가 최적화를 도와주는 것!
}