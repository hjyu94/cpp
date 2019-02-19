#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents()).getCents();
}

void main()
{
	// 익명 객체의 사용
	cout << add(Cents(8), Cents(6)).getCents() << endl;

	// 이게 과연 캐스팅인가? 생각해보자!
	cout << int(6) + int(8) << endl;
}