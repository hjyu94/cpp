#include <iostream>

using namespace std;

void main1()
{
	int iValue = 7;
	int *ptr_i = &iValue;

	double dValue = 7.0;
	double *ptr_d = &dValue;

	for (int i = 0; i < 3; ++i)
		cout << uintptr_t(ptr_i + i) << endl; // 4씩 증가함
	cout << endl;
	
	for (int i = 0; i < 3; ++i)
		cout << uintptr_t(ptr_d + i) << endl; // 8씩 증가함
	cout << endl;

	// 포인터에 데이터 타입을 적어주는 이유
	// 1) 디 레퍼런싱 할 때 반환되는 데이터 타입을 알기 위해서
	// 2) 포인터 연산시 몇 씩 연산되는지 알기 위해서
}

void main()
{
	int array[]{1, 2, 3, 4, 5};
	int *ptr = array;

	for (int i = 0; i < 5; ++i) 
		cout << *(ptr+i) << " " << (uintptr_t)(ptr+i) << endl;
}
// array[i] = *(array+i)

