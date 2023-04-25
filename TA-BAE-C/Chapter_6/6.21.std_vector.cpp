#include <iostream>
#include <vector>

using namespace std;

int _6_21_main()
{
	// array �� ����� �̸� ������� �ϴ� �ݸ�
	// vecotr �� ���� �޸� �Ҵ��� ����ϱ� ������ ����� �������� �ʾƵ� �ȴ�.
	// std::array<int, 5> array;
	std::vector<int> array; 

	// init
	std::vector<int> array2 = { 1, 2, 3, 4, 5 };
	std::vector<int> array3 = { 1, 2, 3, };
	std::vector<int> array4{ 1, 2, 3, }; // uniform initialization
	
	// size �� �� �� �� �� ������ �� �ִ�.
	vector<int> arr = { 1, 2, 3, 4, 5 };
	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;
	
	// API
	cout << arr[1] << endl;
	cout << arr.at(1) << endl;
	cout << arr.size() << endl;

	// �̷������� ������� �迭�� �ݵ�� delete ����� �޸� ���� ���� �ʴ´�.
	int* my_arr = new int[5];
	delete[] my_arr;

	// vector �� ��� ������ ������ �ڵ����� �������.
	// ���� delete ������ �ʾƵ� �ȴ�.

	// ����� �ø��� �͵� arary ���� ���ϴ�
	arr.resize(10);
	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	return 0;
}