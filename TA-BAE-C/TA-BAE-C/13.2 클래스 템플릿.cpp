#include "13.2 MyArray.h"


void main()
{
	// MyArray my_array(10); // X
	// error C2955 : 'MyArray' : 클래스 템플릿을(를) 사용하려면 템플릿 인수 목록이 필요합니다.
	MyArray<int> my_array(10); // O

	for (int i = 0; i < my_array.getLength(); ++i)
	{
		my_array[i] = i * 10;
	}

	my_array.print();
}