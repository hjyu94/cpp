#include <iostream>
using namespace std;

// 포인터에 의한 값 전달
// 주소를 복사해서 새로운 종이에 적는 꼴
void foo(int *ptr)
{
	cout << *ptr << "\t" << ptr << "\t" << /*이 값!*/ &ptr << " :In foo() " << endl;
}

int main()
{
	int value = 5;

	cout << value << "\t" << &value << " :In main() " << endl;
	
	foo(&value);
	// foo(5); // 리터럴은 바로 쓸 수 없음
	/* 
		void foo(int &ptr){...}
		매개변수가 포인터가 아니라 참조변수였다면
		void foo(const int &ptr)와 같이
		const를 추가해주면 리터럴도 넘겨줄 수 있다.
	*/
	cout << endl;

	int *ptr = &value;
	cout << *ptr << "\t" << ptr << "\t" << /*이 값!*/ &ptr << " :In main() " << endl;
	foo(ptr);

	// 메인에서의 &ptr과
	// 함수의 매개변수로 쓰이는 ptr의 &ptr이 다르다
	// 포인터 변수도 하나의 변수로써 주소 값을 전달해주는 경우이기 때문이다.

	return 0;
}