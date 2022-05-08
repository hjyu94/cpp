#include <iostream>
#include <vector>
using namespace std;

// The way to use aliases is not difficult.
int main_4_9__1()
{
	typedef double distance_t;
	/*
		// It is so useful, when you want to change distance_t to float.
		typedef float distance_t;
	*/

	double		my_distance;
	distance_t	home2work;
	distance_t	home2school;

	return 0;
}

int main_4_9__2()
{
	// complicated data type
	// It is annyoing to code with this type.
	vector<pair<string, int>> pairlist;

	typedef vector<pair<string, int>> pairlist_t;
	pairlist_t pairlist1;
	pairlist_t pairlist2;

	return 0;
}

int main_4_9__3()
{
	// It looks like assignment
	// but below code has nothing to do with memory
	// It is just aliases.
	using pairlist_t = vector<pair<string, int>>;

	return 0;
}