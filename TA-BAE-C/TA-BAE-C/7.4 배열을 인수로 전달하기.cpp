#include <iostream>

using namespace std;

void foo(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;

	arr[0] = 1.0;
}
// 주소를 찾아가서 바꾸기 때문에
// 값이 바뀐다
