#include <iostream>

using namespace std;

int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
}

/*************************************/

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;

	// inline 함수는 컴파일러가
	// 값을 복사해주는 과정을 거치지 않고
	// 위의 명령을 아래와 똑같이 해석한다.

	// 모든 함수에 inline을 붙인다고 모두 inline으로 바뀌지는 않고
	// 컴파일러가 봤을때 할 수 있으면 inline 함수 역할을 해준다.
	// 복사해주는 과정이 필요없기 때문에 조금 빨라지기는 할 수 있으나
	// inline 방식에 의존해서 최적화하면 안됨.
	// 요즘에는 빨라지는 정도도 아주 미미함. 거의 차이 없음.

	cout << (5 > 6 ? 6 : 5) << endl;
	cout << (3 > 2 ? 2 : 3) << endl;


}