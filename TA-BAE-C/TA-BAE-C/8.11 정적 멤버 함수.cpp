#include <iostream>

using namespace std;

class Something
{
private:
	static int s_private_value;

public:

public:
	static int s_public_value; 
	// static 변수는 클래스 바깥에서 값을 넣어줘야 한다.
	
	int get_public_s_Value() { return s_public_value; }
	
	int get_private_s_Value() { return s_private_value; }

	static int get_private_s_Value_2() { return s_private_value; }
	// 호출할때, 얘는 클래스로만 부를 수 있다
	// static 멤버 함수에서 this 포인터는 사용할 수 없다.

	void print_s_Value() { s_public_value = 3; cout << ++s_public_value << endl; };	// O
	// non static 멤버 함수로도 static 변수의 출력은 가능하다.

};

/*static:없어야함*/ int Something::s_public_value = 1;
/*static:없어야함*/ int Something::s_private_value = 10;

void main()
{
	cout << Something::s_public_value << endl;
	//cout << Something::s_private_value << endl; // X // inaccessible
	
	Something s1;
	cout << s1.s_public_value << endl;

	cout << s1.get_public_s_Value() << endl;	// O
	cout << s1.get_private_s_Value() << endl;	// O
	cout << s1.get_private_s_Value_2() << endl;	// O
	s1.print_s_Value();							// O

	cout << Something::get_public_s_Value() << endl;	// X
	cout << Something::get_private_s_Value() << endl;	// X
	cout << Something::get_private_s_Value_2() << endl; // O
	cout << Something::print_s_Value() << endl;			// X
	
	// 클래스 명만을 이용해서 호출하고 싶은 멤버 함수는
	// 그 멤버 함수가 static 함수여야만 한다.
}
