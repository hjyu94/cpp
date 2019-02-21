// https://dojang.io/mod/page/view.php?id=591

#include <iostream>
using namespace std;

// [함수 포인터 만들기]
// 반환값자료형 (* 함수포인터이름 ) (매개변수1, ...) ;

/***********************************************************/

void hello()
{
	cout << "Hello!" << endl;
}

void bonjour()
{
	cout << "Bonjour le monde!" << endl;
}

void main1()
{
	cout << hello << endl; // 주소가 출력됨
	
	void(*fp)() = hello;
	fp();

	fp = bonjour;
	fp();

}

/***********************************************************/

int add(int a, int b)
{
	return a + b;
}

void main()
{
	int(*fp_2)(int, int);
	fp_2 = add;
	cout << fp_2(10, 20) << endl;
}