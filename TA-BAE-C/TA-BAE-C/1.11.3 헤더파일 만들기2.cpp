#include <iostream>

// [제일 좋은 방식]
// 헤더 파일에는 선언만 해주고
// cpp 파일에 정의를 분리한다.
#include "1.11.3 헤더파일 만들기.h"

using namespace std;

int main()
{
	cout << add(1, 2) << endl;
}

