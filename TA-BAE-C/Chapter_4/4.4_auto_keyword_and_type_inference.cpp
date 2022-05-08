#include <iostream>

int main_4_4__1()
{
	using namespace std;

	{
		// 123 is integer, and data type declaration is integar
		int a = 123;
	}
	{
		// so you can write this way.
		// this is type inference
		// If you don't initialize, you cannot use auto keyword.
		auto a = 123;
	}

	{
		auto a = 123;
		auto d = 123.0;
		auto c = 1 + 2.0;
	}

	return 0;
}


// function's return typs could also be auto
auto add_1(int x, int y)
{
	return x + y;
}

int main_4_4__2()
{
	auto result = add_1(1, 2);
	return 0;
}


/*
	// But, parameter's type cannot be auto.
	// In this case you can use template instead.
	auto add(auto x, auto y)
	{
		return x + (double)y;
	}
*/

/*
	// Trailing: explicit return data type
	// It is useful for readibility.
	auto add(int x, int y) -> int;
	auto add(int x, int y) -> double;

	// indent is annoying.
	int		add(int x, int y);
	double	add(int x, int y);
*/