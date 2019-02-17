
// 함수도 포인터이다. 주소를 갖고 있다.
// 함수도 메모리에 들어온다.

// 함수를 호출하면, 
// 해당 함수가 어느 메모리에 있는지 알아내고
// 그 메모리에 있는 프로그램을 호출한다.

#include <iostream>

using namespace std;

int func(int x) { return 5; }
int goo() { return 10; }

void main1()
{
	cout << func << endl;

	/*
		(함수 리턴 타입) (* (변수 이름)) (함수 파라매터 타입); // 선언
		(함수 리턴 타입) (* (변수 이름)) (함수 파라매터 타입) = (함수명) // 초기화까지
	*/

	int (* fcnptr) (int) = func;

	cout << fcnptr(5) << endl;

	// int(*ptr_ftn) () = goo;

	// fcnptr = goo; // x
	// 다른 함수를 가리키게 할 수 있다.
	// 단 매개변수들이 맞아 떨어져야 한다.

	// cout << fcnptr() << endl; // x
}

/*************************************************************************/
#include <array>

void printNumbers(const array<int, 10>& arr, bool print_even)
{
	for (auto element : arr)
	{
		if (print_even && element % 2 == 0) cout << element;
		if (!print_even && element & 2 == 1) cout << element;
	}
	cout << endl;
}

void main2()
{
	std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_array, true); // 짝수만 출력
	printNumbers(my_array, false); // 홀수만 출력
}

/*************************************************************************/

#include <array>

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printNumbers(
	array<int, 10>& my_arr
	, bool(*check_ftn)(const int&) = isEven // 파라매터 기본값
)
{
	for (auto element : my_arr)
	{
		if (check_ftn(element)) cout << element << ",";
	}
	cout << endl;
}

void main3()
{
	array<int, 10> my_arr = { 0,1,2,3,4,5,6,7,8,9 };
	printNumbers(my_arr, isEven);
	printNumbers(my_arr, isOdd);
}

/*************************************************************************/
#include <array>

typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printNumbers(array<int, 10>& my_arr, check_fcn_t check_fcn)
{
	for (auto element : my_arr)
	{
		if (check_fcn(element)) cout << element << ",";
	}
	cout << endl;
}

void main4()
{
	array<int, 10> my_arr = { 0,1,2,3,4,5,6,7,8,9 };
	
	printNumbers(my_arr, isEven);
	printNumbers(my_arr, isOdd);
}

/*************************************************************************/

#include <array>
#include <functional>

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printArr(
	array<int, 10> my_arr
	, function<bool(const int&)> check_fcn
)
{
	for (auto element : my_arr)
		if (check_fcn(element)) cout << element << ",";
	cout << endl;
}

void main5()
{
	array<int, 10> my_arr{ 0,1,2,3,4,5,6,7,8,9 };
	
	std::function<bool(const int&)> fcnptr = isEven;
	printArr(my_arr, fcnptr);
	
	fcnptr = isOdd;
	printArr(my_arr, fcnptr);
}

/*************************************************************************/
array<int, 10> my_arr{ 0,1,2,3,4,5,6,7,8,9 };

// 함수 포인터 선언, 초기화
int func(double x, int y);
int(*ptr_fcn)(double, int) = func;

// 파라매터로 함수 포인터가 들어가는 경우
void printNumbers(array<int, 10>& arr, bool(*check_ftn)(const int&))
{
	for (auto element : arr)
		if (check_ftn(element));
}

// 너무 길어요!
typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

void printNumbers(array<int, 10>& arr, check_fcn_t check_fcn)
{
	for (auto element : arr)
		(check_fcn(element));
}

// #include <functional>
void printNumbers(
	array<int, 10>& arr
	, function<bool(const int&)> check_fcn
)
{
	for (auto element : arr)
		(check_fcn(element));
}

std::function<bool(const int&)> check_fcn_ptr = isEven;
printNumbers(my_arr, check_fcn_ptr)
