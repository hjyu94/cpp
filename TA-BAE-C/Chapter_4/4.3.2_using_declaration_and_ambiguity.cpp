#include <iostream>

namespace a
{
	int my_var(10);
}

namespace b
{
	int my_var(20);
}

int _4_3_2__1()
{
	using namespace std;
	using namespace a;
	using namespace b;

	// "my_var" is ambiguous
	// cout << my_var << endl;

	// [solution 1] ::
	cout << a::my_var << endl;
	cout << b::my_var << endl;
	return 0;
}

int _4_3_2__2()
{
	using namespace std;

	// [solution 2] scope with {}
	{
		using namespace a;
		cout << my_var << endl;
	}
	{
		using namespace b;
		cout << my_var << endl;
	}

	return 0;
}

// Using namespace globally is dangerous.
