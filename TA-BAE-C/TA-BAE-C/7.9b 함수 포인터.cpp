#include <iostream>
using namespace std;

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div2(int a, int b);

/*
	[함수 포인터 배열]
	반환값자료형 (*함수포인터이름[크기])(매개변수자료형1, 매개변수자료형2);
*/

void main()
{
	int fcnNumber;
	int num1=100, num2=5;
	int(*fp[4])(int, int) = { add, sub, mul, div2 };

	while (true)
	{
		cout << "1.더하기 2.빼기 3.곱하기 4.나누기" << endl;
		cin >> fcnNumber;
		cout << fp[--fcnNumber](num1, num2) << endl;
	}
}

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div2(int a, int b)
{
	return a / b;
}