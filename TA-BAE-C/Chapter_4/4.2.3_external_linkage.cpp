#include <iostream>

/*
	// It is not used often.
	#include "4.2.3_doSomething.cpp" 
*/

/* 
	# Forward declaration
	
	While this file is compiled, 
	compiler looks for doSomethings' body part
	and links this forward declaration and its body.
	
	After that at a execution stage, linkaged body is executed.
*/
/* extern */ void doSomething_4_2_3(); // extern keyword is hided.


/*
	fatal error LNK1120: 1 unresolved externals
	
	At linkage stage, error occurs.
	Linker can't find aaaa in any files.

	At compile stage, aaaa is declared in forward declaration
	so compiler thought it would be okay but linker can't find it anywhere.
	Memory named aaaa is nowhere.
*/
// extern int aaaa;


// bbbb is okay, 
// because bbbb is declared and initialized in another file.
extern int bbbb; 


/*
	LNK2005: "int cccc" already defined in 4.2.3_doSomething.obj
	fatal error LNK1169: one or more multiply defined symbols found
*/
// extern int cccc = 3;


int _4_2_3()
{
	using namespace std;

	doSomething_4_2_3();

	// cout << aaaa << endl;
	cout << bbbb << endl;

	return 0;
}