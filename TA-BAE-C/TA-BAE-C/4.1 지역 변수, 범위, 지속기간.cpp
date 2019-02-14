#include <iostream>

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

}

// apple = 999; // X