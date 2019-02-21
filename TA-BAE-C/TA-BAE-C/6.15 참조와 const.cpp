#include <iostream>

using namespace std;

void doSomething(const int& x);
void doOther(int& x);

int main()
{
	{
		// #1 레퍼런스 변수만 const인 경우
		// 다른 값을 가리킬 수 없다
		int			x = 5, y = 1;
		const int&	ref_x = x;
		x = y;		// O
		ref_x = y;	// X
	}

	{
		// #2 원래 변수만 const인 경우
		// const가 아닌 레퍼런스 변수로 가리킬 수 없다.
		const int x = 5; // O
		int& ref_x = x;  // X
	}

	{
		// 아래 둘의 차이점은?
		// 함수의 매개변수로 쓰일 때 참조변수는 복사가 될 필요가 없다.
		const int  ref_x = 3 + 4;
		const int& ref_x = 3 + 4;

		// 레퍼런스는 메모리 주소가 있어야만 할당 가능하다.
		// 그러나 레퍼런스 변수가 const이면 리터럴 상수도 대입 가능하다.
		int&		ref_x = 3;		// X
		const int&	ref_x = 3 + 4;	// O

		cout << ref_x << ", " << &ref_x << endl;
	}

	/********************************************************/

	int a = 1;
	doSomething(a);
	doSomething(1);
	doSomething(a+1);
	
	doOther(a); 
	doOther(1); // X // lvalue만 인자로 사용 가능
	doOther(a+1); // X
}


void doSomething(const int& x)
{
	cout << x << endl;
}

void doOther(int& x)
{
	cout << x << endl;
}
