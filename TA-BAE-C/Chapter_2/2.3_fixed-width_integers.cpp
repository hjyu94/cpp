// multi-platform 프로그래밍 시 많이 사용됨.

#include <iostream>
// #include <cstdint> // <iostream> 에 포함되어 있음.

int main()
{
	using namespace std;

	std::int16_t i(5); // 16 bit // typedef short int16_t
	std::int8_t myint = 65; // typedef signed char int8_t

	cout << myint << endl; // A 가 나옴. 

	std::int_fast8_t fi(5); // 가장 빠른 데이터 타입
	std::int_least64_t fl(5); // 적어도 8바이트

	return 0;
}