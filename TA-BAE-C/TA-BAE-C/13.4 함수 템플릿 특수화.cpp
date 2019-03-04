// 여러가지 기능에 대해서 템플릿 프로그래밍을 하다 보면
// 특정 자료에 대해서는 다른 기능을 구현하고 싶을 때가 있다
// 이럴때 템플릿 특수화를 사용한다.

#include <iostream>
#include "13.4 Storage.h"
using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// char 타입에 대해서는 다른 방식으로 처리하고 싶을 때
template<>
char getMax(char x, char y)
{
	cout << "Warning: comparing chars" << endl;
	return (x > y) ? x : y;
}

int main1()
{
	cout << getMax(1, 2) << endl; // 파라매터가 int라서 자동적으로 인스턴시에이션 함
	cout << getMax<int>(1, 2) << endl;

	cout << getMax<double>(1.0, 2.0) << endl; // double
	cout << getMax<double>(1, 2) << endl; // 얘도 double
	
	cout << getMax('a', 'b') << endl;

	return 0;
}

/***********************************************************************/

int main()
{
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print()
}