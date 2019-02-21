#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	
	friend ostream& operator << (ostream& out, Cents cents)
	{
		out << cents.m_cents;
		return out;
	}

	// 단항 연산자 오버로딩하기
	// [ - 연산자 오버로딩 ]
	friend Cents operator - (Cents& cents);
	
	Cents operator -()
	{
		return Cents(-m_cents);
	}

	// [ ! 연산자 오버로딩 ]
	friend bool operator ! (Cents cents);

	bool operator ! ()
	{
		if (m_cents == 0) return true;
		else return false;
	}
};

Cents operator - (Cents& cents)
{
	return Cents(-cents.m_cents);
}

bool operator ! (Cents cents)
{
	if (cents.m_cents == 0) return true;
	else return false;
}

void main()
{
	Cents cents1(8);
	Cents cents2(6);
	
	cout << cents1 << endl;
	cout << -(cents1) << endl;
	cout << !cents1 << endl;
}
