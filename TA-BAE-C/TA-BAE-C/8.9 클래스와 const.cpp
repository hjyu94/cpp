
// 매개변수가 const인 경우?
//	: 함수 내에서 해당 변수의 값을 바꾸지 않겠다.

// 함수가 const인 경우?
//	: 클래스에서 멤버 함수를 const로 만들 수 있는데
//	: 해당 클래스의 멤버 변수 값을 바꾸지 않겠다는 표시이다.

// 오브젝트(객체)가 const인 경우?
//	: const로 지정한 멤버 함수만 호출할 수 있다.

/********************************************************/

#include <iostream>

using namespace std;

class Something
{
private:
	int i_m;

public:
	void setValue(int x)
	{
		i_m = x;
	}

	int getValue()
	{
		return i_m;
	}
};

void main()
{
	const Something something;
	something.setValue(5);					// X
	cout << something.getValue() << endl;	// X
}

/********************************************************/

class Something1
{
private:
	int i_m;

public:
	void setValue(int x) // const
	// setValue가 const가 아니면
	// something.setValue(5); 가 안되고

	// 그렇다고 해서 const로 만들면
	// i_m 값을 변경할 수 없다.
	{
		i_m = x;
	}

	int getValue() const
	{
		return i_m;
	}
};

void main1()
{
	const Something1 something;
	something.setValue(5);
	cout << something.getValue() << endl;
}

