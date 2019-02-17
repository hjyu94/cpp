// 복사 constructor

#include <iostream>

using namespace std;

class Something
{
public:
	int i_m;

	Something()
	{
		cout << "Constructor ~" << endl;
	}

	void setValue(int x)
	{
		i_m = x;
	}

	int getValue() const
	{
		return i_m;
	}
};

void print(Something st);

void main()
{
	Something something;
	cout << "In main: " << &something << endl;

	print(something);
}
// [결과]
// main 과 print 에서 호출되는 주소값은 다른데
// Constructor는 main에서만 호출된다.

void print(Something st)
{
	cout << "In ftn: " << &st << endl;
	cout << st.i_m << endl;
}
// call by value 값을 @ 복사 @ 해서 사용함
// Something 클래스의 오브젝트인 st가 새로 생기고
// 실인자가 복사되서 st에 들어오는건 맞는데
// 왜 Constructor는 한번만 호출될까?
// ---> 매개변수 st를 생성할때는 복사 Constructor가 호출되기 때문에!

/***********************************************************/

class Something
{
public:
	int i_m;

	// 기본 생성자
	Something()
	{
		cout << "Constructor ~" << endl;
	}

	// 생성자가 아니라 기본 복사 생성자!
	// 만들어주지 않아도 기본으로 있음. 생략돼 있을 뿐.
	Something(const Something& st_in)
	{
		cout << "Copy Constructor !" << endl;
		i_m = st_in.i_m;
	}

	void setValue(int x)
	{
		i_m = x;
	}

	int getValue() const
	{
		return i_m;
	}
};

void print(Something st)
{
	cout << "In ftn: " << &st << endl;
	cout << st.i_m << endl;
}
// void print(Something& st)
// 만약 참조 변수로 넘겨주면 복사를 해주는게 아니기 때문에
// 복사 생성자가 호출되지 않고 main의 something과 같은 주소가 출력된다.

void main()
{
	Something something;
	cout << "In main: " << &something << endl;

	print(something);
}
