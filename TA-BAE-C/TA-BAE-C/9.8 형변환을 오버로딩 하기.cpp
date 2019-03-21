#include <iostream>
using namespace std;

class Cents1
{
private:
	int m_cents;

public:
	Cents1(int _cents)
	{
		m_cents = _cents;
	}
};

void printInt1(const int& value)
{
	cout << value << endl;
}

void main_1()
{
	Cents1 cents(7);

	// printInt1(cents); // X
}

/*****************************************************/

class Cents
{
private:
	int m_cents;

public:
	Cents(int _cents)
	{
		m_cents = _cents;
	}

	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	printInt(cents);

	return 0;
}
