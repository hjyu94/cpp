#include <iostream>

using namespace std;

int test1()
{
	const int i = 0;
	i = 1; // 상수로 선언한 변수를 수정할 수 없다.

	return 0;
}

//

class Something
{
public:
	int m_value = 0;

	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }

	// const function 에서 멤버 필드 값 수정 불가능
	void setValue(int value) const {
		m_value = value;
	}
	int getValue2() const { return m_value; }

	// 방어적 프로그래밍을 하려면 멤버 함수들을 기본적으로 const로 선언하는것이 좋다.
};

void test2()
{
	const Something something;
	something.setValue(3);
	// object 는 상수로 선언했는데
	// setValue 는 상수 인스턴스의 멤버필드를 바꾸려고 함.
	// 컴파일 에러 발생.

	cout << something.getValue() << endl;
	// 값을 수정하지 않는 getter 에서도 컴파일 에러 발생.
	// 컴파일러 입장에서는 함수 내용이 getter 인지 setter 인지가 중요한게 아니라
	// 호출하려는 멤버 함수가 const 인지 아닌지가 중요하기 때문

	cout << something.getValue2() << endl;
	// const 로 선언한 getValue2() 는 호출 가능.
	// 함수가 const 로 선언되는 경우 해당 함수 body 에서 멤버 필드를 바꾸지 못함.
}

//

void print(Something st)
{
	cout << &st << endl;
	cout << st.m_value << endl;
}

void test2()
{
	Something something;
	cout << &something << endl;
	print(something);

	/*
	* output
	* ------------------
	* Constructor
	* 0001
	* 0002
	*/
	/*
	* print 함수에서는 st 를 복사해서 사용하고 있는데 constructor 는 한번만 불린다.
	게다가 서로 다른 주소가 찍힌다.
	그 이유는 복사가 될 때는 복사 생성자라는것이 불리기 때문이다.

	Something(const Somoething& st_in)
	{
		m_value = st_in.m_value;
	}

	기본 복사 생성자는 위와 같이 생겼다.
	*/
	
}

// 만약 print() 에 const reference 변수를 사용하게 되면?
void print2(const Something& st)
{
	cout << &st << endl;
}

// 아래와 같은 경우
// something 이 새로운 인스턴스를 만들고 복사 생성자로 값을 할당하는것이 아니라
// something 자체를 넘기게 되어서 같은 주소가 찍히게 된다.
// 성능 최적화
void test3()
{
	Something something;
	print2(something);
}

//

#include <string>

class Something2
{
public:
	string m_value = "default";

	// const 인지 아닌지로 오버로딩이 가능

	const string& getValue() const { 
		cout << "const version" << endl;
		return m_value; 
	}
	
	string& getValue() { 
		cout << "non const version" << endl;
		return m_value; 
	}
};

int test4()
{
	Something2 something;
	something.getValue() = 10; // reference

	const Something2 something2;
	something2.getValue() = 1024; // const reference
}