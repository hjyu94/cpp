#include <iostream>

using namespace std;

class Something
{
private:
	static int s_private_value;

public:

public:
	static int s_public_value; // 클래스 바깥에서 값을 넣어줘야 한다.
	
	int get_nonS_Value() { return s_public_value; }
	int get_S_Value() { return s_private_value; }			// X
	static int get_S_Value_2() { return s_private_value; }	// O
	// static 멤버 변수를 리턴하는 함수는 static 멤버 함수여야 한다.
};

/*static:없어야함*/ int Something::s_public_value = 1;
/*static:없어야함*/ int Something::s_private_value = 10;

void main()
{
	cout << Something::s_public_value << endl;
	Something s1;
	cout << s1.get_nonS_Value() << endl;
	cout << s1.s_public_value << endl;

	// cout << Something::s_private_value << endl; // X // inaccessible

	cout << Something::get_S_Value_2() << endl; // O
	cout << Something::get_S_Value() << endl; // X
	// static 멤버 변수를 리턴하는 함수는 static 멤버 함수여야 한다.
}
