#include <iostream>
using namespace std;

class Resource
{
public:
	int m_data[100];

public:
	Resource()
	{
		cout << "Resource constructor" << endl;
	}

	~Resource()
	{
		cout << "Resource destructor" << endl;
	}
};

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	/**********************************************/
	
	// copy constructor
	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // 소유권을 넘겨준다!!
	}

	// assignment operator
	AutoPtr& operator = (AutoPtr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr; // 이미 무언갈 갖고있다면 걔는 지워버리고
		m_ptr = a.m_ptr;

		a.m_ptr = nullptr; // 소유권을 넘겨준다!!
		return *this;
	}
	
};


void another(AutoPtr<Resource> ptr)
{}

void doSomething()
{
	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << res1.m_ptr << endl; // 0x100
		cout << res2.m_ptr << endl; // 0x000

		res2 = res1;
		// 복사 생성자가 호출된다.

		cout << res1.m_ptr << endl; // 0x000
		cout << res2.m_ptr << endl; // 0x100
	}
	
	// Move Semantics

	// Semantics: 컴파일은 되는데 내부적으로 그 의미가 뭐냐가 중요.
	// Syntax: 문법에 맞느냐 아니냐. 컴파일이 되느냐 안되느냐.

	// [syntax vs. semantics]
	int x = 1, y = 1;
	x + y;

	string str1("Hello"), str2("World");
	str1 + str2; 
	// 기호는 + 기호로 같지만 string 덧셈은 append의 의미를 갖는다.
	// 이게 semantics!

	// [Semantics]
	// value semantics (copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	{
		AutoPtr<Resource> res1(new Resource);
		another(res1);
		// doSometing 함수 res1을 실인자로 받음
		// 함수가 끝나면서 메모리를 반납해버리니까 함수 호출 이후에 문제가 생기기도 한다.
		// 이런 문제들 때문에 오토 포인터는 사용이 중지가 되었다
	}
}

