#include <iostream>
using namespace std;

/*************************************************************/

// [1. 일반 함수를 이용한 오버로딩]
// 함수 명 자리에 operator + 를 써준다.
// return-type operator + ( parameter ... )

class Cents
{
private:
	int m_cents;

public:
	Cents() {}
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }
};

Cents operator + (const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents + c2.getCents());
}

/*************************************************************/

// [2. friend 함수를 이용한 오버로딩]
// private 멤버 변수를 바로 사용할 수 있어진다.

class Cents1
{
private:
	int m_cents;

public:
	Cents1() {}
	Cents1(int Cents1) { m_cents = Cents1; }
	int getCents1() const { return m_cents; }
	int& getCents1() { return m_cents; }

	friend Cents1 operator + (const Cents1& c1, const Cents1& c2);
};

Cents1 operator + (const Cents1& c1, const Cents1& c2)
{
	return Cents1(c1.m_cents + c2.m_cents);
}

/*************************************************************/

// [3. 멤버 함수로 연산자 오버로딩]
// 멤버 함수로 집어넣으면 friend 키워드 없이도 private 멤버 변수 자유롭게 사용 가능
// 멤버 함수가 되면 첫번째 파라매터로 this가 자동으로 들어가기 때문에
// 파라매터를 하나 지워줘야 한다.

// 멤버로만 해야하는 오버로딩 해야하는 연산자
// =, [], (), -> 

class Cents2
{
private:
	int m_cents;

public:
	Cents2() {}
	Cents2(int Cents2) { m_cents = Cents2; }
	int getCents2() const { return m_cents; }
	int& getCents2() { return m_cents; }

	Cents2 operator + (const Cents2& c1)
	{
		return Cents2(this->m_cents + c1.m_cents);
	}

};

/*************************************************************/

void main()
{
	Cents cents1(8);
	Cents cents2(6);

	cout << (cents1 + cents2).getCents << endl;
}