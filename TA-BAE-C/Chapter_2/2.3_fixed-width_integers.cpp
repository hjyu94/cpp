// multi-platform ���α׷��� �� ���� ����.

#include <iostream>
// #include <cstdint> // <iostream> �� ���ԵǾ� ����.

int main()
{
	using namespace std;

	std::int16_t i(5); // 16 bit // typedef short int16_t
	std::int8_t myint = 65; // typedef signed char int8_t

	cout << myint << endl; // A �� ����. 

	std::int_fast8_t fi(5); // ���� ���� ������ Ÿ��
	std::int_least64_t fl(5); // ��� 8����Ʈ

	return 0;
}