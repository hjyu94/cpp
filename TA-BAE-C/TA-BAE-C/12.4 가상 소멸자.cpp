#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		cout << "Derived()" << endl;
		m_array = new int[length];
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

void main()
{
	{
		// Derived derived(5);

		// Base()
		// Derived()
		// ~Derived()
		// ~Base()
	}

	{
		Derived* derived = new Derived(5);
		// Base()
		// Derived()

		Base* base = derived;

		delete base;
		// ~Base()
	}
}