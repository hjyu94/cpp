// 정적 할당 배열은 배열의 사이즈가 컴파일 타임에 결정되어 있어야만 사용 가능

#include <iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;
	// int array[length]; // X // 컴파일 타임에 length 값이 정해지지 않아서 에러

	int *array = new int[length] {1, 2, 3};
	// int *array = new int[] {1, 2, 3}; // X

	// 만약 legnth에 3보다 작은 값은 입력받게 되면 런타임 에러 발생
	// os한테 메모리를 충분히 받지 못했는데 메모리를 더 쓰려고 하니까 문제!

	for (int i = 0; i < length; ++i) cout << array[i] << endl;

	delete[] array; // 배열에 할당한 긴~ 메모리를 반납하는 방법

	/*
		- 배열이 아닌 변수를 반납할 때
		- delete (반납할 변수의 주소값)

		int* iValue = new int{1};
		delete iValue;
	*/

	/*************************************************************/
	
	int fixedArray[5] = { 1,2,3,4,5 }; // O
	int fixedArray[] = { 1,2,3,4,5 }; // O // 컴파일 타임에 5개라고 정해짐
	// 정적 배열에서는 초기화를 해주면 [] 안에 개수 지정해주지 않아도 됨

	int *array1 = new int[5] { 1, 2, 3, 4, 5 }; // O
	int *array1 = new int[]{ 1,2,3,4,5 }; // X
	// 에러: new 식에서는 배열 크기를 지정해야 합니다.
	// 동적 배열에서는 초기화를 해줬으면 [] 안에 개수 꼭 지정해줘야 함

	int *array2 = new int[3]{ 1,2,3,4,5 }; // X // 4, 5 는 넣을 자리가 없음
	int *array3 = new int[8]{ 1,2,3,4,5 }; // O
}