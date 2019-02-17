#include <iostream>

using namespace std;

// [1. return by value]
// 값을 복사해서 리턴함

int getValue1(int x)
{
	int value = x * 2;
	return value;
}

void main1()
{
	int value = getValue1(5);
}

/************************************************************/

// [2. return by pointer]
int* getValue2(int x)
{
	int value = x * 2;
	return &value;
} 

void main2()
{
	int value = *getValue2(5); // 그나마 여기서는 value에 값을 복사해 넣음
	cout << value << endl; // 10
	cout << value << endl; // 10

	int* value2 = getValue2(5); // 이게 더 위험
	cout << *value2 << endl; // 10
	cout << *value2 << endl; // -858993460 // 가비지 출력됨

}
// getValue에서 value는 지역변수로 함수를 벗어나면 사라질 변수
// 사라질 지역변수를 이용해서 값을 출력하는 방법은 위험할 수 있다.

/************************************************************/

// [3. return by reference]
int& getValue3(int x)
{
	int value = x * 2;
	return value;
} // value가 지역변수로 괄호 끝에서 메모리를 반납해버릴 거라 문제 발생

void main()
{
	int& value = getValue3(5);
	cout << value << endl; // 10
	cout << value << endl; // -858993460 // 가비지 출력됨
}

/************************************************************/
