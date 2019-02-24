// [early vinding, static binding]
// 모든 identifier(변수명이나 함수명)이 깔끔하게
// 빌드 타임에 결정되어 있을 때 

// [late binding, dynamic binding]
// func_ptr : 컴파일타임에 어떤 함수가 들어올지 결정되지 않음
// func_ptr이 어떤 함수의 주소가 될지 런타임에 결정이 된다.
// 값을 구해낼 때도 func_ptr을 통해 동적으로 할당이 된 함수의 포인터를
// 찾아가서 그 주소를 찾아가서 그 주소에 있는 해당 함수를 
// 호출시켜달라고 하는 간접적인 방법을 사용한다.

// 속도?
// static binding이 더 빠르다
// 주소를 타고 한번 더 갈 필요가 없어서

// 유연성?
// dynamic binding이 더 유연하다

#include <iostream>
using namespace std;

int add(int x, int y);
int subtract(int x, int y);

void main()
{
	int x, int y;
	cin >> x >> y;

	int op;
	cout << "0: add, 1:subtract" << endl;
	cin >> op;

	// static binding, early binding
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	}
	cout << result << endl;

	// dynamic binding, late binding
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	}
	cout << func_ptr(x, y) << endl;
}

int add(int x, int y)
{
	return x + y;
}
int subtract(int x, int y)
{
	return x - y;
}