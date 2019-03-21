#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(const int& iInput) : m_cents(iInput) {}
	operator int()
	{
		cout << "cast from cents to int" << endl;
		return m_cents;
	}
};

class Dollar
{
private:
	int m_dollar;

public:
	Dollar(const int& iInput) : m_dollar(iInput) {}
	// 객체 생성 -> 메모리 할당 -> '이니셜라이저' -> 객체 생성

	operator Cents()
	{
		cout << "cast from dollar to cents" << endl;
		Cents cents(m_dollar * 100);
		return cents;
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

void main()
{
	Dollar dol(2);
	Cents cents = dol;
	printInt(cents);
}