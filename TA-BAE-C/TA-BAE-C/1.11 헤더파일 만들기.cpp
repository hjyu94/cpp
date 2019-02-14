#include <iostream>

using namespace std;

/* extern */ int add(int x, int y);
// 근데 add 같은 함수가 여러개 있다면
// 매 함수를 전방선언 하기는 귀찮음
int main()
{
	cout << add(1, 2) << endl;
}