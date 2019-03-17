// move semantics를 항상 사용할 수는 없다
// move semantics를 사용할지 말지, 혹은 사용할 수 있을지, 사용하면 안될지를
// 오른쪽 값 참조를 통해 알아보자.
#include <iostream>
using namespace std;

int getResult()
{
	return 0;
}

// move semantics를 사용 불가능
// 파라매터로 넘겨보낸 변수를 이 함수 호출 후 사용하려면
// 소유권이 뺏겨진 상태라서 에러가 발생한다.
void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

// 어짜피 다른데서 사용할 일이 없기 때문에
// 막 가져다가 써도 된다.
// move semantics를 사용 가능
void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int main()
{
	int x = 5;
	// r-value는 곧 사라짐
	// l-value에 r-value를 넣어서 계속 사용하겠다는 의미
	int y = getResult();
	// 함수의 리턴값을 r-value로 사용하고 있다.
	const int cx = 6;
	// const: 나중에 값을 바꿀 수 없다.

	// [L-value references]
	int& lr1 = x;	// Modifiable l-values
	int& lr2 = cx;	// Non-modifiable l-values
	int& lr3 = 5;	// R-values
	// 참조변수는 자기가 참조하는 변수가 메모리를 갖고 있어야 한다
	// 따라서 메모리가 없는 값을 넣을 수 없다

	const int& lr4 = x;	// Modifiable l-values
	const int& lr5 = cx; // Non-modifiable l-values
	const int& lr6 = 5; // R-values

	// [R-value references]
	// &&: R-value만 받을 수 있다.
	int&& rr1 = x;	// Modifiable l-values
	int&& rr2 = cx;	// Non-modifiable l-values
	int&& rr3 = 5;	// R-values
	int&& rr3_2 = getResult();
	// 5, getResult()는 코드 라인 이후에 사라질 운명. 
	// 임시로만 존재하는 얘를 보관하게 해준다는 의미

	const int&& rr4 = x;	// Modifiable l-values
	const int&& rr5 = cx;	// Non-modifiable l-values
	const int&& rr6 = 5;	// R-values

	// r-ref는 곧 사라질 얘들만 담을 수 있는 것. r-value는 move로 다른데로 옮겨버려도 아무도 찾지 않는다는 의미
	// 그에 반해 l-ref인 x에 들어있는 내용물을 다른데로 옮겨버리면 x를 통해 다시 그 내용물을 접근할 수 없어서 충돌이 생긴다.

	// [L/R-value reference parameters]
	doSomething(x); // L-value ref (메모리를 가진 얘)
	doSomething(cx); // void doSomething(const int& ref)로 정의를 바꾸면 얘도 가능.
	doSomething(5); // R-value ref (메모리를 갖지 못하는 얘)
	doSomething(getResult()); // R-value ref

}