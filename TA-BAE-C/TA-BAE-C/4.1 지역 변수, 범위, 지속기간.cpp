// [네임 스페이스]
// http://soen.kr/lecture/ccpp/cpp3/34-1-2.htm

#include <iostream>

// 네임 스페이스는 반드시 전역 영역에 선언해야 한다
namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

namespace work2
{
	int a = 1;
	void doSomething()
	{
		a += 5;
	}
}


int main()
{
	using namespace std;

	// apple = 999; // X
	int apple = 5;
	apple = 1;
	
	cout << apple << endl; // 1

	// int apple = 888; // X // 재정의 불가능
	{
		cout << apple << endl; // 1
		int apple = 888; // 재정의 가능, 블록 밖으로 넘어가면 사라진다
		cout << apple << endl; // 888
	}
	
	cout << apple << endl; // 1
	cout << endl;

	cout << work1::a << endl; // 1
	work1::doSomething();
	cout << work1::a << endl; // 4


}

// apple = 999; // X


// 참고:

namespace {
	int internal; 
} // C++ style
static int internal1; // C stype

// 외부로 알려지지 않는다.
// 다른 cpp 파일에서 해당 변수들을 사용할 수 없다.