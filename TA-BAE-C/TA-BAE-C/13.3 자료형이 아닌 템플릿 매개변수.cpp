#include "13.3 MyArray.h"

void main()
{
	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
	// 위의 경우는 동적할당됨. 100이라는 숫자가 컴파일타임에 정해지지 않아도 됨

	MyArray<double, 100> my_array; // std::array<double, 100>
	// 위의 경우는 100이 compile 타임에 결정이 되어야 한다.

	// 아래 경우는 안 됨. 
	// int i = 100;
	// MyArray<double, i> my_array; // std::array<double, 100>
	// (const int 면 가능해지긴 함)

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();
}