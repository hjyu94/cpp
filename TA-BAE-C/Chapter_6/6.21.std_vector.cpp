#include <iostream>
#include <vector>

using namespace std;

int _6_21_main()
{
	// array 는 사이즈를 미리 정해줘야 하는 반면
	// vecotr 는 동적 메모리 할당을 사용하기 때문에 사이즈를 적어주지 않아도 된다.
	// std::array<int, 5> array;
	std::vector<int> array; 

	// init
	std::vector<int> array2 = { 1, 2, 3, 4, 5 };
	std::vector<int> array3 = { 1, 2, 3, };
	std::vector<int> array4{ 1, 2, 3, }; // uniform initialization
	
	// size 를 그 때 그 때 변경할 수 있다.
	vector<int> arr = { 1, 2, 3, 4, 5 };
	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;
	
	// API
	cout << arr[1] << endl;
	cout << arr.at(1) << endl;
	cout << arr.size() << endl;

	// 이런식으로 만들어준 배열은 반드시 delete 해줘야 메모리 릭이 남지 않는다.
	int* my_arr = new int[5];
	delete[] my_arr;

	// vector 는 블록 밖으로 나가면 자동으로 사라진다.
	// 따로 delete 해주지 않아도 된다.

	// 사이즈를 늘리는 것도 arary 보다 편하다
	arr.resize(10);
	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	return 0;
}