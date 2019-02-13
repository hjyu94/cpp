#include <iostream>

using namespace std;

int main()
{
	int value = 5;
	int* ptr = &value;
	*ptr = 6;

	/******************************************************/
	
	//#1 포인터에 담으려는 변수가 const인 경우

	const int	c_value = 10;
	// int*		c_ptr = &c_value; // X
	const int*	c_ptr = &c_value; // O
	// *c_ptr = 20; // X

	// const 변수의 주소를 담는 포인터 변수는
	// 그 포인터 변수도 const 여야 하며
	// 그 경우 디 레퍼런싱을 이용해서 값을 제어할 수 없다.
	// 단 주소를 읽어올 수는 있다.

	/******************************************************/

	//#2 포인터 변수만 const인 경우
	
	int			value2 = 15;
	const int*	c_ptr2 = &value2;
	
	*c_ptr2 = 30; // X

	// 해당 포인터를 이용해서 값을 바꾸지 않겠다는 의지 표현
	// 따라서 값 변경 불가능

	/******************************************************/
	
	//#3 포인터 변수가 const라면?

	int val1 = 5, val2 = 10;
	const int* c_ptr = &val1;
	c_ptr = &val2;	// O
	*c_ptr = 30;	// X

	// 주소가 가리키고 있는 값을 바꾸지 않겠다는 뜻이지
	// ptr의 값을 바꾸지 않겠다는 뜻이 아님

	/******************************************************/
	
	//#4 포인터 자체를 const로 만들고 싶으면?

	int iValue = 5, iValue2 = 0;
	int* const ptrValue = &iValue; 
	*ptrValue = 10;				// O
	cout << *ptrValue << endl;	// O
	ptrValue = &iValue2;		// X

	// 포인터가 가리키는 값을 바꿀수도 출력할수도 있지만
	// 포인터의 값을 바꿀 순 없다. (다른 주소를 담을 수 없다)

	int *const ptr; // 포인터 자체가 상수이므로 초기화가 꼭 필요함

	/******************************************************/
	
	//#5 ???

	const int* const cc_ptr = &value;
	*cc_ptr = 10; // X
	cc_ptr = 10; // X
	
	// 포인터가 가리키는 값도 바꿀 수 없고
	// 포인터의 값도 바꿀 수 없다.
}

// 총 3가지 있는 것!
int value = 5;
const int* ptr1 = &value;
int* const ptr2 = &value;
const int* const ptr3 = &value;