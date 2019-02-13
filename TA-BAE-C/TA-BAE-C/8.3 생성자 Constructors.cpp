#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	// 초기화해주지 않으면 가비지 값이 들어있다.

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main()
{
	Fraction frac; // 기본생성자만 있을때 이런식으로 객체 생성 가능
	Fraction frac(); // OK

	frac.m_numerator = 0;
	frac.m_denominator = 1;
	// Fraction frac{ 0,1 }; 랑 같다
	
	// 단 각 멤버 변수가 public이어야 초기화 가능
}

/*************************************************************/

class Fraction1
{
	int m_numerator; /* = 0;*/
	int m_denominator; /*= 1;*/
	// 기본값을 지정할 수도 있다.
};

/*************************************************************/

class Fraction2
{
private:
	int m_numerator;
	int m_denominator;
	// 초기화해주지 않으면 가비지 값이 들어있다.

public:
	Fraction2(int x) // 기본 생성자는 사라지게 됨
	// 생성자를 만들어주지 않을때는 기본 생성자가 생략되어 있지만
	// 생성자를 임의로 만들어주면 기본 생성자는 없어진다.
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

void main2()
{
	Fraction2 frac; // Fraction2이 기본생성자만을 갖고 있을때만 가능
	Fraction2 frac(1);
}