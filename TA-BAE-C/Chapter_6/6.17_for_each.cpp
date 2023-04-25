#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	for (auto &number : fibonacci)
		number *= 10;

	// 이 반복문 안에서는 number 를 변경하지 않겠다.
	for (const auto &number : fibonacci)
		cout << number << " ";
	cout << endl;

	// How to find maximum
	int max_number = std::numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);
	cout << max_number << endl;
}