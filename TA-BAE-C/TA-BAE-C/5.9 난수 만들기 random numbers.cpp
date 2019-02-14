#include <iostream>
// #include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()
using namespace std;

int main()
{
	srand(5323); // 고정된 씨드값을 사용. 실행시마다 같은 값들이 계속 나오게 됨
	srand(static_cast<unsigned int>(time(0)));
	// 현재 cpu clock을 씨드로 사용하므로 실행할 때마다 다른 값들이 나옴

	// 단 디버깅 때는 고정된 씨드값을 사용하는 것이 에러를 고쳐내기 편하다.

	for (int count = 1; count <= 100; ++count)
	{
		cout << rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}
}