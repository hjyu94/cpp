#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }

	friend Cents operator +(const Cents& c1, const Cents& c2);
};

ostream& operator << (ostream& out, Cents& cent)
{
	out << cent.getCents();
	return out;
}

Cents operator + (const Cents& c1, const Cents& c2)
{
	return Cents(c1.m_cents + c2.m_cents);
}

void main()
{
	cout << Cents(7)+Cents(6) << endl;
}