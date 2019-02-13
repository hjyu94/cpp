#include <iostream>

using namespace std;

// 배열을 인수로 전달하기
void printElement(int(&arr)[4])
{
	
}

int main()
{
	int arr[]{ 1,2,3,4 };

	printElement(arr);

}

//////////////////////////////////////////////////////

#include <vector>

void printElement(
	/*const:습관적으로 사용해주면 좋다*/ vector<int>& arr)
{

}

int main()
{
	vector<int> arr{ 1,2,3,4 };
	printElement(arr);
}