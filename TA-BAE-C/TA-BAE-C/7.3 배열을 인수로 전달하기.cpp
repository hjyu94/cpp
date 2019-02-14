#include <iostream>

using namespace std;

// 배열을 인수로 전달하기
//void printElement(int(&arr)[4])
//{
//
//}

void printElement(int(&arr)[99])
{

}
// 반드시 배열의 크기도 인자와 동일하게 지정해야 한다.

int main()
{
	int arr[]{ 1,2,3,4 };

	printElement(arr);

}

//////////////////////////////////////////////////////

#include <vector>

void printElement(
	/* const:습관적으로 사용해주면 좋다 */ 
	vector<int>& arr)
{

}

int main()
{
	vector<int> arr{ 1,2,3,4 };
	printElement(arr);
}