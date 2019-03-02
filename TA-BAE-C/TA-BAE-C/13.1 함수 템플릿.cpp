#include <iostream>
using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

void main()
{
	cout << getMax(1, 2) << endl;
	cout << getMax(1.14, 2.28) << endl;
	cout << getMax(1.0f, 2.28f) << endl;
	cout << getMax('a', 'c') << endl;

	cout << getMax(1, 'a') << endl;
}