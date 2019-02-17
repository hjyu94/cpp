#include <iostream>

using namespace std;

int main()
{
	int i_v1 = 1, i_v2 = 2, i_v3 = 3;

	{
		// [0. 참조 변수만 const인 경우]
		int i_Val = 10;
		const int& i_Ref = i_Val;
		i_Val = 888;
		i_Ref = 999; // X
	}

	{
		// [1. const int를 참조하는 변수]
		// 참조 변수도 const여야 한다.
		const int i_Val = 4;
		const int& i_Ref = i_Val; // O
		i_Ref = i_v1;

		int& i_Ref = i_Val; // X
	}

	{
		// [2. const인 참조 변수는 r-value로 초기화 가능]
		const int& const_ref = 5; // O
	}

}

/*****************************************************************/

void Something(int x)
{
	x++;
}

void Something_ref(int& x)
{
	x++;
}

void Something_const_ref(const int& x)
{
	x++; // 매개변수가 const 이므로 값 변경 불가능
	cout << x << endl;
}

void main2()
{
	int i_Val = 10;
	Something(i_Val);			// O
	Something_ref(i_Val);		// O
	Something_const_ref(i_Val);	// O

	Something(10);				// O
	Something_ref(10);			// X
	Something_const_ref(10);	// O
}