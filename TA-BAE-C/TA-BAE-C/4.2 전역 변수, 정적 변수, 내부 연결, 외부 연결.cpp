/* 
	https://www.letmecompile.com/c-auto-static-extern-%ED%82%A4%EC%9B%8C%EB%93%9C-%EC%9D%98%EB%AF%B8/ 
	
	https://dojang.io/mod/page/view.php?id=683
	https://dojang.io/mod/page/view.php?id=684
	https://dojang.io/mod/page/view.php?id=802

*/

// 해당 변수가 해당 cpp 파일 내에서는 아무데서나 사용 가능: 내부 연결
// 다른 cpp 파일에서도 사용 가능: 외부 연결

/********************************************************/

#include <iostream>

using namespace std;

int value = 124;

int main()
{
	cout << value << ::value << endl; // 124 124

	int value = 1; // main 밖의 변수와 이름이 같음
	// 네임 쉐이딩 등의 기법이 사용됨

	cout << value << ::value << endl; // 1 124
}

// 지역변수:
// - 선언한 순간 이후부터 사용 가능. 
// - 영역 범위를 벗어난 순간 메모리가 os로 반납되고 
// - 더이상 사용하거나 접근할 수 없다. 
// - 스코프, 듀레이션 모두 영역 범위 안으로 제한된다.

/********************************************************/

#include <iostream>

void doSomething()
{
	int a = 1;
	// 매번 새로운 메모리가 a에 할당된다
	++a;
	cout << a << endl;
}

int main()
{
	doSomething(); // 2
	doSomething(); // 2
}

/********************************************************/

#include <iostream>

void doSomething()
{
	static int a = 1;
	// 메모리가 os로부터 받은 메모리가 static이라는 것
	// 메모리가 정적으로 선언된다.
	
	// 같은 메모리를 쓰고 초기화를 단 한번만 한다.	
	// 다시 doSomething() 이 호출될때는 해당 코드 실행하지 않음
	// 새로운 a의 장소를 찾지 않는다
	
	// static 변수는 선언과 동시에 초기화되어야 한다.
	// static int a; a = 1; // X
	// 초기화를 생략하면 0으로 자동 초기화

	/*
		- static은 사용되는 위치에 따라 의미가 달라지니 주의해서 사용할것.
		- 내부정적변수 : 
			- 함수 내부의 변수에 static이 사용된경우, 해당 변수는 함수 내부에서만 사용이 가능.
			- 하지만, 프로그램이 실행되는 동안 계속 값이 유지됨
		- 외부정적변수 : 
			- 함수 외부의 전역범위의 변수에 static이 사용된경우, 
			- 해당 파일 내부에서는 전역변수처럼 사용되지만, 아닌 다른 소스파일에서는 참조할 수 없음
			(예 : 보통 하나의 example.c 파일 내부에서만 사용하기위한 전역변수로 사용됨.
			다른 파일이 example.h를 include하더라도 해당 static으로 선언된 전역변수는 보이지 않아 접근 불가)
	*/

	++a;
	
	cout << a << endl;
}

int main()
{
	doSomething(); // 2
	doSomething(); // 3
	doSomething(); // 4
}

/********************************************************/

#include <iostream>

int a = 1;

void doSomething()
{
	++a;
	cout << a << endl;
}

int main()
{
	doSomething(); // 2
	doSomething(); // 3
	doSomething(); // 4
}

/********************************************************/

// static vs global
// static: 다른 cpp 파일에서 접근할 수 없음(scope)

// local var.은 링키지가 없음.
// 해당 블록만 벗어나면 어짜피 사라질 변수
// 다른 cpp 파일에 연결되지 않는다

// 개별 cpp 안에서만 전역으로 작동하는 전역변수 -> (내부 연결)

/********************************************************/

#include <iostream>

static int g_a = 1; 
// 다른 cpp 파일에서 접근 불가능

// 전역변수 앞에 static을 붙이면 
// 해당 전역변수가 다른 cpp파일에서 사용되는 것을 막는다

int main()
{
	int a = 10;

	return 0;
}

/********************************************************/

// [외부연결]
// test.cpp 의 doSomething()를 사용하고 싶은 경우
// 1) cpp 파일 직접 인클루드(가급적 사용 X)
// 2) 전방선언

#include <iostream>
// #include "4.2 외부연결 test.cpp"
#include "4.2 My Constants.h"

// forward declaration
/* extern (생략되어 있음) */ void doSomething();
// 어딘가 doSomething()의 정의가 존재하니까
// 링킹할때 갖다 붙이세요
// 실행 시에는 링킹할때 붙인 기능을 수행하세요

extern int a;
// 만약 여기서 extern int a = 567; 라고 하면
// 초기화를 여러번 해줘서 에러
// (test.cpp에서 이미 초기화했음)

int main()
{
	cout << "In main.cpp: " << Constants::pi << ", 주소: " << &Constants::pi << endl;
	
	doSomething(); 
	// extern으로 표시해서 다른 파일에 있다고 알려줬음
	// Constants::pi 의 값과 주소를 출력하는 함수

	// (4.2 MyCosntants.cpp가 없고 4.2 MyConstants.h만 있는 경우에) 
	// test.cpp 와 다른 변수의 메모리 공간을 사용하게 된다.
	// 상수를 1억개 사용할 때 여러 cpp 파일에서 상수 헤더파일을 인클루드 하면
	// 같은 변수더라도 다른 메모리를 사용하는 상수가 1억개나 생김 -> 메모리 낭비 주의해야 함
	// 4.2 MyConstants.cpp 를 만들어줘서 이를 해결함.

	cout << a << endl; // 123
	// test.cpp 파일에서 extern int a = 123; 했음
}

/********************************************************/

int g_x; // external linkage
static int g_x; // 다른 곳에서 사용 불가 internal linkage. 선언과 동시에 초기화 시켜야 함
const int g_x; // const는 값을 이후에 안 바꾸겠다는 뜻인데 선언과 동시에 초기화 시켜야 함

extern int g_z;
extern const int g_z; // 다른 곳 어딘가에서 이 상수값을 초기화 시켜줬어야 함, 다른 cpp 파일에서도 사용 가능

int g_y(1);
static int g_y(1); // 다른 .cpp 에서 사용 불가 internal linkage
const int g_y(1);
extern int g_y(1); // 초기화 시켜줬으므로 다른 곳에서는 초기화하면 안됨
