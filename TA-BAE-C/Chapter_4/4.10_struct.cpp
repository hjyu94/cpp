#include <iostream>
#include <string>
using namespace std;

struct Person
{
	double	height;
	float	weight;
	int		age;
	string	name;

	void m_printPerson()
	{
		cout << height << ", " << weight << ", " << age << ", " << name << endl;
	}
};

// Member selection operator (.)
// this function can be included inside Person struct
void printPerson(Person p)
{
	cout << p.height << ", " << p.weight << ", " << p.age << ", " << p.name << endl;
}

int main_4_10__1()
{
	Person me;
	/*
		me.age = 20;
		me....
	*/
	
	Person mom{ 2.0, 100.0, 20, "Jack Jack" };
	printPerson(mom);
	mom.m_printPerson();

	return 0;
}


/********************************************************************************/


// struct has a struct as member field.

struct Family
{
	Person me, mom, dad;
};



/********************************************************************************/


Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack Jack" };
	return me;
}

int main_4_10__2()
{
	Person me_from_func = getMe();
	me_from_func.m_printPerson();

	return 0;
}


/********************************************************************************/


// initialization with default value is possible.
struct Person2
{
	double	height = 3.0;
	float	weight = 200.0;
	int		age = 100;
	string	name = "default name";
};

int main_4_10__3()
{
	Person2 me;
	cout << me.name << endl;

	Person2 mom{ 2.0, 100.0, 20, "Jack Jack" };
	cout << mom.name << endl;

	return 0;
}

/********************************************************************************/

struct Employee // 2 + (2) + 4 + 8 = 16 // padding
{
	short	id;		// 2 bytes
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};

int main_4_10__4()
{
	Employee emp1;
	cout << sizeof(Employee) << endl; 
	// 14? Nope 16! data structure alignment

	return 0;
}