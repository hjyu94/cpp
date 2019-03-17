// C, C++
// new, delete을 이용해서
// 동적 메모리를 직접 관리해야 한다는 점이 귀찮다
//
// 최근의 C에서는
// 스마트 포인터를 도입해서
// 상당부분 개선하였다.

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

/*****************************************************************/

// [RAII란?] resource acquisition is initialization
// 동적할당 받은 곳에서 메모리 반납까지 책임지고 처리해주어야 한다.
void doSomething()
{
	Resource *res = new Resource;
	// work with res
	delete res;
	return;
}

// [이때 생길 수 있는 문제 1]
// 중간에 리턴되어 res의 메모리 반납이 되지 않는 경우
void doSomething()
{
	Resource *res = new Resource; // dull pointer(스스로 메모리를 반납하지 않는 포인터)
	// work with res

	if (true) return; // early return

	delete res;
	return;
}
/*
	if (true)
	{
		delete res;
		return;
	}

	이런식으로 바꾸면 가능하긴 하다
	근데 귀찮은건 매한가지고 실수로 빠뜨릴수도 있다.
*/

// [이때 생길 수 있는 문제 2]
// 중간에 예외처리 res의 메모리 반납이 되지 않는 경우
void doSomething()
{
	try
	{
		Resource *res = new Resource; // dull ptr
		// work with res

		if (true) throw - 1;

		delete res;
	}
	catch (...)
	{

	}
}

/*****************************************************************/
// 스스로 관리가 되는 포인터 클래스를 만들어보자

// std::auto_ptr<int>; 따라해보기 
// (C++98 때 만들었는데, C++17 에서는 사라짐)

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	// 소멸자가 호출될때 자동으로 메모리를 반납하도록 만든 클래스

	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
	}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}


	// 나머지는 포인터처럼 쓸 수 있게끔 구현한 함수
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

/*****************************************************************/

void doSomething()
{
	AutoPtr<Resource> auto_res(new Resource); // smart pointer
	
	if (true) return; // early return
	 
	return;
}

void doSomething()
{
	try
	{
		AutoPtr<Resource> auto_res(new Resource); // smart pointer

		if (true) throw - 1;
	}
	catch (...)
	{

	}
}

/*****************************************************************/

// AutoPtr의 단점
void doSomething()
{
	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;
		// Resource constructor는 한번만 호출됨
		// 마치 int i; int* ptr1 = &i; int* ptr2 = nullptr; 꼴

		cout << res1.m_ptr << endl; // 0x100
		cout << res2.m_ptr << endl; // 0x000

		res2 = res1;
		// 복사 생성자가 호출된다.
		// 멤버 변수들을 모두 복붙함.
		// 여기서는 m_ptr 값을 그대로 복붙

		cout << res1.m_ptr << endl; // 0x100
		cout << res2.m_ptr << endl; // 0x100
	}
	// 위의 괄호를 벗어나는 순간 res1, res2의 소멸자가 호출되는데
	// res1, res2 모두 같은 메모리를 가리키고 있어서
	// 똑같은 위치를 지우려고 함.
	// 지워진 메모리를 또 지우려고 들게된다.
	//
	// 소유권을 누가 갖느냐의 문제
	// 한 집을 두명이 가지고 있는 꼴
	//
	// 해결법?
	// res2 = res1; 을 실행할 때 소유권을 넘겨주면 된다.
}
