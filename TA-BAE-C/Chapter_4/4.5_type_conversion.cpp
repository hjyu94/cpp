#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

int main_4_5__1()
{
	cout << typeid(4.0).name() << endl;

	int a = 123;
	cout << typeid(a).name() << endl;

	return 0;
}

int main_4_5__2()
{
	int a = 123.0; // int? double?
	cout << typeid(a).name() << endl;

	return 0;
}

// Implicit Type Conversion (coersion)
int main_4_5__3()
{
	// [1] numeric promotion (get memory size bigger)
	{
		float f = 1.0f;
		double d = f;
	}
	
	// [2] numeric conversion
	{
		int i = 30000;
		char c = i;

		// 127? Nope!
		// It is even not edge number
		cout << static_cast<int>(c) << endl;

		/*********************************/

		// precision is dumb
		
		// (1) double and float
		double d = 0.123456789;
		float f = d;

		cout << std::setprecision(12) << f << endl;

		// (2) float and int
		float f1 = 3.14; // It is floor
		int i1 = f1;
		
		cout << std::setprecision(12) << i1 << endl;

		// (3) unsigned
		// precedence: int < unsigned int
		// 5u - 10 is not integar. It is still unsigned int
		cout << 5u - 10 << endl;
		cout << typeid(5u - 10).name() << endl;

		/* 
			int < unsigned int < long < unsigned long
			< long long < unsigned long long
			< float < double < long double 
		*/
	}

	return 0;
}

// Explicit Type Conversion (casting)
int main_4_5__4()
{
	int c_style = (int)4.0;
	int cpp_style = int(4.0);

	int nowadays = static_cast<int>(4.0);

	return 0;
}