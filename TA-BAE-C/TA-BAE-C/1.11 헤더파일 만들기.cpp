#include <iostream>

using namespace std;

// [1. 다른 cpp 파일에 분리한다.]
// 다른 cpp 파일에 있는 함수를 쓰겠다는 선언
// 링커가 add 함수를 찾아보게끔 만든다.
/* extern */ int add(int x, int y);

int main()
{
	cout << add(1, 2) << endl;
}

// 근데 add 같은 함수가 여러개 있다면
// 매 함수를 전방선언 하기는 귀찮음
