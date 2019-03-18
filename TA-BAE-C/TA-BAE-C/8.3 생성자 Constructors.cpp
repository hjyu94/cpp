#include <iostream>

using namespace std;

class Fraction
{
private:
public:
	int m_numerator;
	int m_denominator;
	// 초기화해주지 않고 출력할 시 런타임 에러 발생한다.

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main()
{
	Fraction frac; // 기본생성자만 있을때 괄호 없이 객체 생성 가능
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
	// 초기화해주지 않고 출력해보면 런타임 에러 발생

public:
	// Fraction2() {} // 기본 생성자

	Fraction2(int x) 
	// 생성자가 호출될 때 값을 초기화 해주는 방법이 있다.

	// 기본 생성자는 사라지게 됨
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
	Fraction2 frac; // 기본 생성자가 있을 때 이와 같이 오브젝트 생성 가능.
	Fraction2 frac(1);
}