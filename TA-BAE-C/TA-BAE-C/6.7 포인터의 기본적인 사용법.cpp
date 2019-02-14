#include <iostream>

using namespace std;

struct Something // 16 bytes
{
	int a, b, c, d;
};

int main()
{
	int		x = 1;
	double	d = 3.14;
	Something sth1;

	int		*ptr_x;
	double	*ptr_d;
	Something *ptr_sth;

	
	cout << sizeof(x) << endl; // 4
	cout << sizeof(d) << endl; // 8
	cout << sizeof(sth1) << endl; // 16

	cout << sizeof(&x) << ", " << sizeof(ptr_x) << endl; // 8, 8 (x64, 32bit)
	cout << sizeof(&d) << ", " << sizeof(ptr_d) << endl; // 8, 8
	cout << sizeof(&sth1) << ", " << sizeof(ptr_sth) << endl; // 8, 8
}