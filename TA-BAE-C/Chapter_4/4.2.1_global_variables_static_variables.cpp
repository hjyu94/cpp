#include <iostream>

/*
	It's not recommended to use global variable often.
	Global variables is hard to debug
	 
	After compile, cpp file compiled to obj files.
	During linking, obj files are linked together.
	After linkage, we can get exe file.

	Linkage many files is not good.
*/

using namespace std;

int value = 123; // global variable

void doSomething()
{
	int a = 1; // local variable
	++a;
	cout << a << endl;
}

void doSomething2()
{
	static int a = 1; // static variable
	++a;
	cout << a << endl;
}

/*
	Static variable means that the memory is static.
	
	When we use local variables, after }, the memory the variable occupy gets free.
	Allocate memory and free memory, again and again...

	But about static variables,
	Assigning memory is done only once.
	initialization is done only once, too.

	Even though we go through 'static int a = 1' many times,
	but actually, assignment is called only once.
	What is more important is that it is necessary 
	declaration and initializattion to the static variable at the same time.
	'static int a;' is not possible.
*/
int g_a = 1; // global variable also works like static variable
void doSomething3()
{
	// static int a = 1;
	++g_a;
	cout << g_a << endl;
}

int _4_2_1()
{
	cout << value << endl;

	int value = 1; // hiding, shadowing

	cout << ::value << endl;	// way to use global variable
	cout << value << endl;		// way to use local varaible
	cout << "=============" << endl;

	/*********************************************************/

	doSomething(); // [console] a = 2
	doSomething(); // [console] a = 2
	doSomething(); // [console] a = 2
	doSomething(); // [console] a = 2
	cout << "=============" << endl;
	 
	/*********************************************************/

	doSomething2(); // [console] a = 2
	doSomething2(); // [console] a = 3
	doSomething2(); // [console] a = 4
	doSomething2(); // [console] a = 5
	cout << "=============" << endl;

	/*********************************************************/

	doSomething3(); // [console] a = 2
	doSomething3(); // [console] a = 3
	doSomething3(); // [console] a = 4
	doSomething3(); // [console] a = 5
	cout << "=============" << endl;

	return 0;
}