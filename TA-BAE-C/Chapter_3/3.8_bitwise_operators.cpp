#include <iostream>
#include <bitset>

int _3_8()
{
	// For saving memory, bitwise operator would be useful.

	using namespace std;

	// << left shift
	// >> right shift
	// ~, &, |, ^

	// shift
	{
		unsigned int a = 3;

		cout << bitset<8>(a) << " " << a << endl;
		cout << bitset<8>(a << 1) << " " << (a << 1) << endl;
		cout << bitset<8>(a << 2) << " " << (a << 2) << endl;
		cout << bitset<8>(a << 3) << " " << (a << 3) << endl;
		cout << bitset<8>(a << 4) << " " << (a << 4) << endl;

		// shift is much faster than * operator.
	}

	// bitwise NOT
	{
		unsigned int a = 1024;

		cout << bitset<16>(a) << " " << a << endl;
		cout << bitset<16>(~a) << " " << ~a << endl;
	}

	// bitwise AND, OR, XOR
	{
		unsigned int a = 0b1100;
		unsigned int b = 0b0110;
		
		cout << bitset<4>(a & b) << endl; // bitwise AND
		cout << bitset<4>(a | b) << endl; // bitwise OR
		cout << bitset<4>(a ^ b) << endl; // bitwise XOR
	}

	return 0;
}