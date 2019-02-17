#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;

public:	
	Something()
		//: s_value(1024)
	{}
};

int Something::s_value = 1;
// static 멤버 변수를 생성자에서 초기화 할 수 없다.

// static 멤버 변수를 사용하는 함수는 static 멤버 함수여야 한다.
// 생성자가 static이어야 static 멤버 변수에 값을 넣어줄 수 있는데
// 생성자는 static으로 만들 수 없다.

/**************************************************************/

class Another
{
public:
	class _init
	{
	public:
		_init() { s_value = 999; }
	};

private:
	static int s_value;
	static _init s_initializer;

public:
	/*Another()
		: s_value(1024) // X
	{}*/
};
int Another::s_value = 1;
Another::_init Another::s_initializer;

// 얘가 만들어지면서 inner 클래스의 생성자가 초기화되고
// inner 클래스의 생성자에서 s_value 가 초기화 된다.

// inner class에서 간접적으로 사용

void main()
{

}