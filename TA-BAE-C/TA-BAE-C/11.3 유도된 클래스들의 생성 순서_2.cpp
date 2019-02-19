#include <iostream>

using namespace std;

class GrandMother
{
public:
	GrandMother()
	{
		cout << "GrandMother constructor" << endl;
	}

	~GrandMother()
	{
		cout << "~ GrandMother destructor" << endl;
	}
};

class Mother : public GrandMother
{
public:
	Mother()
	{
		cout << "Mother constructor" << endl;
	}

	~Mother()
	{
		cout << "~ Mother destructor" << endl;
	}
};


class Me : public Mother
{
public:
	Me()
	{
		cout << "Me constructor" << endl;
	}

	~Me()
	{
		cout << "~ Me destructor" << endl;
	}
};


class Daughter : public Me
{
public:
	Daughter()
	{
		cout << "Daughter constructor" << endl;
	}

	~Daughter()
	{
		cout << "~ Daughter destructor" << endl;
	}
};

void main()
{
	Daughter daughter;
}