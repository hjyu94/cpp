// memory: data / code / heap / stack

// data: 전역 변수, static 변수
// heap: 동적 할당된 변수
// stack: 지역 변수

#include <iostream>

using namespace std;

class Something
{
public:
	int m_value = 1;

	// static int s_value = 1; // X
	static int s_value;		// O 
	// 중복 선언(초기화) 문제
	// static 같은 변수들은 여러번 선언하면 에러가 난다.

	// 따라서 헤더파일로 따로 만드는 경우는
	// 헤더파일에 선언만 하고 cpp 파일에서 값을 따로 빼주는게 좋다.
	
	static const int s_c_value = 1;
	// 반대로 static const 변수는 클래스 내부에서 초기화를 해줘야 함
	// const 변수는 선언과 동시에 초기화를 해주어야 함.

	static constexpr int s_c_expr_value = 1;
	// constexpr인 경우 컴파일타임에 값이 확실히 지정되어야 함
};

/*static:없어야함*/ int Something::s_value = 1;

// const int Something::s_c_value = 999; // X
// const 변수는 선언과 동시에 초기화를 해주어야 함.
// const 변수는 나중에 값 바꿀 수 없음.

void main1()
{
	Something st1, st2;
	st1.m_value = 2;
	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;
	// 다른 주소가 출력된다.
}

void main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;
	// 정적 멤버 변수는 인스턴스가 없을 때도 주소를 출력해 볼 수 있다.
	// 단 값을 주지 않고(int Something::s_value = 1;)
	// 출력하면 링킹 에러가 발생한다.

	Something st1, st2;
	st1.s_value = 999; // O // static 변수 값 변경 가능
	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
}
