// 프로그래머의 편의를 돕기 위해 생성자를 변환을 시켜주는 converting constructor
// 변환생성자를 사용하지 못하게 막아버리는 explicit 키워드
// 특정한 생성자를 사용하지 못하게 지워버리는 delete 키워드

// 동적할당에서의 delete와는 다른 의미입니다!

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
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1)
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

void main()
{
	Fraction frac(7);

	doSomething(frac);
	doSomething(Fraction(7));
	doSomething(7); 
	// 파라매터가 객체 하나뿐이라면 생성자처럼 자동으로 바꿔준다.
	// converting constructor
	// 이때 생성자에 explicit 키워드를 사용하면 
	// 생성자를 converting constructor로 사용 불가능.

	Fraction('a'); 
	// 자동 conversion 되거나 casting 되는 
	// 걱정되는 경우가 있어 강제로 막아버린다.
}