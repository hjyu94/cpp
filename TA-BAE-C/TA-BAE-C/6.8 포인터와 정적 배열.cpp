#include <iostream>

using namespace std;

void main1()
{
	int array[5] = { 1,2,3,4,5 };
	cout << *array << endl; // 1만 출력됨

	char name[] = "JackJack";
	cout << *name << endl; // JackJack? J? // J !
	cout << name << endl; // JackJack ! // '\0'까지 출력

	// cout에서 문자열의 주소가 들어오면 주소가 아니라 문자열이 출력된다!!
}

/*******************************************************************/

// void printArray(int* array)와 같다
void printArray(int array[]) /* 내부적으로 포인터*/
{
	cout << sizeof(array) << endl;		// 8 (x64에서 포인터 변수는 무조건 8byte)
}

int main()
{
	int array[5] = { 1,2,3,4,5 };
	int *ptr = array;

	cout << array << endl;		// 주소가 출력됨
	cout << &array[0] << endl;	// 주소가 출력됨 (같은 값)

	cout << sizeof(array) << endl;		// 20 (int 5개) 
	printArray(array);					// 8 (x64에서 포인터 변수는 무조건 8byte)
	cout << sizeof(&array[0]) << endl;	// 8 (x64에서 포인터 변수는 무조건 8byte)
	cout << sizeof(ptr) << endl;		// 8 (x64에서 포인터 변수는 무조건 8byte)
										// 배열 원소의 데이터 타입이랑 상관 없음
}