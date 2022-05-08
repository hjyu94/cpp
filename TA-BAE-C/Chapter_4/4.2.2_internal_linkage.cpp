#include <iostream>

/*
	local variable is used inside {}, 
	so linkage is not necessary to local variables.

	Static local variable is local variable anyway. 
	In other files, static local variable is not seen.

	# Internal linkage
	g_a is seen inside main function, and in this cpp file.
	this is internal linkage.
*/

int g_a_4_2_2 = 1; // Is it seen other cpp files?
static int s_a = 1; // s_a is not avaiable in other cpp files.

int _4_2_2()
{
	// g_a_4_2_2 is seen here.

	return 0;
}

// g_a_4_2_2 is seen here. 