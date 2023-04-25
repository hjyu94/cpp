#include <iostream>

using namespace std;

int add(int a, int b); // 전방선언 forward declaration
int multiply(int a, int b);
int subtract(int a, int b);

int main()
{
	cout << add(1, 2) << endl;

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}