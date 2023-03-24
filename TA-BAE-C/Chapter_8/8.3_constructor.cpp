#include <iostream>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction() // no return type
	{
		m_numerator = 0;
		m_denominator = 1;

		cout << "Fraction() constructor" << endl;
	}

	// 만약 생성자가 아무것도 없으면
	// 컴파일러가 생성자를 임의로 만들어서 넣어준다.
	// Fraction() {}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print1()
{
	// 메모리에 인스턴스가 자리를 잡으면 바로 생성자가 실행됨.
	// 생성자에 파라미터가 하나도 없을 경우는 frac() 대신 frag 으로 써야 한다.
	Fraction frac; 

	frac.print();

	return 0;
}

//

class Fraction2
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction2(const int& num_in, const int& den_in = 1 /* default parameter */)
	{
		m_numerator = num_in;
		m_denominator = den_in;

		cout << "Fraction() constructor" << endl;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print2()
{
	Fraction2 one_thirds(1);
	one_thirds.print();

	return 0;
}

//

class Fraction3
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction3()
	{
		m_numerator = 1;
		m_denominator = 3;
	}

	Fraction3(const int& num_in = 1, const int& den_in = 3)
	{
		m_numerator = num_in;
		m_denominator = den_in;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print3()
{
	// 디폴트 생성자를 쓰고 싶을 때는 frac() 가 아니라 frac 로 부르는데
	// 현재 클래스의 생성자에 디폴트 생성자라고 생각할 수 있는 함수가 2개 이상이라 에러 발생
	// 컴파일는 생성자 중 모든 파라미터에 대해 디폴트 파라미터를 쓰고 있는 생성자는 디폴트 생성자로 생각.
	Fraction3 frac;

	return 0;
}

//


class Fraction4
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction4(const int& num_in = 1, const int& den_in = 3)
	{
		m_numerator = num_in;
		m_denominator = den_in;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print4()
{
	// assign operator overloading 이 없으면 디폴트로 복사됨.
	Fraction4 copy = Fraction4{ 1, 3 };

	// uniform initialization
	// public field 만 사용 가능.
	// 얘도 생성자 호출 해준다.
	// 단 타입변환을 해주지 않아서 f1{ 1.0, 3 }; 이런식으로 사용 불가능
	Fraction4 f1{ 1, 3 };

	// 위랑 비슷하긴 하지만 타입변환을 해준다. 대신 warning 정도만 출력한다.
	// f2(1.0, 3); 은 가능.
	Fraction4 f2(1, 3);
	return 0;
}

//

class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor" << endl;
	}
};

int test()
{
	// class Second constructor()
	// class First constructor()
	// 멤버필드로 들어가 있는 sec 의 생성자부터 호출된다.
	First fir;

	return 0;
}