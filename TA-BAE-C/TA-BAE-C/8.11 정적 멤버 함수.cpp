#include <iostream>

using namespace std;

class Something
{
private:
	static int s_private_value;

public:

public:
	static int s_public_value; // 클래스 바깥에서 값을 넣어줘야 한다.
	
	int get_public_s_Value() { return s_public_value; }
	
	int get_private_s_Value() { return s_private_value; }		
	static int get_private_s_Value_2() { return s_private_value; }
	
	void print_s_Value() { s_public_value = 3; cout << ++s_public_value << endl; };	// O
	// non static 멤버 함수로도 static 변수의 출력은 가능하다.

};

/*static:없어야함*/ int Something::s_public_value = 1;
/*static:없어야함*/ int Something::s_private_value = 10;

void main()
{
	Something s1;

	s1.s_public_value;
	// s1.s_private_value;		// X // inaccessible

	s1.get_public_s_Value();	// O
	s1.get_private_s_Value();	// O
	s1.get_private_s_Value_2();	// O
	s1.print_s_Value();			// O

	/************************************************************************************/

	// 클래스 명을 이용하는 경우는
	// 특정 인스턴스에 종속되지 않는 static 멤버 함수만 호출할 수 있다.

	// Something::s_private_value;		// X // inaccessible
	Something::s_public_value;

	Something::get_public_s_Value();	// X
	Something::get_private_s_Value();	// X
	Something::get_private_s_Value_2(); // O 
	Something::print_s_Value();			// O
}
