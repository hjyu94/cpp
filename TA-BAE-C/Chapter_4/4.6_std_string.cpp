#include <iostream>
#include <string>

using namespace std;

int main_4_6__1()
{
	// "Hello, World" length is const char[13]
	// End character (null) is included.
	cout << "Hello, World" << endl;
	
	const string my_hello = "Hello, World";
	cout << my_hello << endl;

	return 0;
}

int main_4_6__2()
{
	const char my_strs[] = "Hello, World";
	const string my_hello_1 = "Hello, World";
	const string my_hello_2("Hello, World");
	const string my_hello_3{ "Hello, World" };
	
	// string is user defined data type,
	// not primitive data type

	return 0;
}

int main_4_6__3()
{
	string my_ID = "123";
	// string my_ID = 123; // It is not possible
	
	return 0;
}

// When string is entered as input,
// if whitespace is included in input,
// cin is annyoing.
int main_4_6__4()
{
	cout << "Your name?: ";
	string name;
	cin >> name;

	cout << "Your age?: ";
	string age;
	cin >> age;

	cout << name << " " << age << endl;
	
	return 0;
}

// So use std::getline
int main_4_6__5()
{
	cout << "Your name?: ";
	string name;
	std::getline(std::cin, name);

	cout << "Your age?: ";
	string age;
	std::getline(std::cin, age);

	cout << name << " " << age << endl;

	return 0;
}

// Integer input could be a problem.
// (case) 1 -> enter -> Jack Jack -> enter
// one of solutions is to flush buffer.
int main_4_6__6()
{
	cout << "Your age?: ";
	int age;
	cin >> age;

	cout << "Your name?: ";
	string name;
	std::getline(std::cin, name);

	cout << name << " " << age << endl;

	return 0;
}

#include <limits>
int main_4_6__7()
{
	cout << "Your age?: ";
	int age;
	cin >> age;

	// std::cin.ignore(32767, '\n');
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Your name?: ";
	string name;
	std::getline(std::cin, name);

	cout << name << " " << age << endl;

	return 0;
}

int main_4_6__8()
{
	string a("Hello, ");
	string b("World. ");
	string hw = a + b; // append

	hw += "I'm good";

	cout << hw << endl;

	return 0;
}

int main_4_6__9()
{
	string a("Hello, World");	// const char[13]
	cout << a.length() << endl; // 12

	return 0;
}