// move semantics가 어떻게 작용하는지 어떤 장점이 있느지
// 주기적으로 move semantics를 사용하다 보면
// 컴파일러의 결정이 아니라 프로그래머 스스로 move semantics를 사용할지 말지
// 결정하고 싶을 때가 있는데 이럴 때 사용가늫안 std::move를 알아보자.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Resource
{
private:
	int* m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource(const int _iLength = 0)
	{
		cout << "Resource length constuctor" << endl;
		m_data = new int[_iLength];
		m_length = _iLength;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			cout << m_data[i] << ' ';
		cout << endl;
	}

	void setAll(const int& v)
	{
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = v;
	}
};

template<typename T>
class AutoPtr
{
public:
	T* m_ptr;

public:
	AutoPtr(T* _pInput = nullptr)
		: m_ptr (_pInput)
	{
		cout << "AutoPtr 기본 생성자" << endl;
	}

	~AutoPtr()
	{
		cout << "AutoPtr 소멸자" << endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(const AutoPtr& a)
	{
		cout << "AutoPtr 복사 생성자" << endl;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	AutoPtr& operator= (const AutoPtr& a)
	{
		cout << "AutoPtr 복사 대입 생성자" << endl;
		if (&a == this) return *this;
		if (m_ptr != nullptr) delete m_ptr;
		
		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// 복사 생성자나 복사 대입 생성자를
	// 강제로 사용하지 않게끔 하고 싶을 때
	// AutoPtr(const AutoPtr& a) = delete;
	// AutoPtr& operator= (const AutoPtr& a) = delete;

	AutoPtr(AutoPtr&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
		cout << "AutoPtr 이동 생성자" << endl;
	}

	AutoPtr& operator= (AutoPtr&& a)
	{
		cout << "AutoPtr 이동 대입 생성자" << endl;
		if (&a == this) return *this;
		if (!m_ptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

template<typename T>
void MySwap(T& a, T& b)
{
	//1) 복사가 많이 일어남.
	T temp = a;	// 복사 생성자
	a = b;		// 복사 대입 생성자
	b = temp;	// 복사 대입 생성자

	/*
		Resource res = res_a;	// 복사 생성자
		res_a = res_b;			// 복사 대입 생성자
		res_b = res;			// 복사 대입 생성자
	*/

	////2) std::move 를 이용해보자 -> r-value로 인식
	//T tmp(std::move(a));
	//a = std::move(b);
	//b = std::move(tmp);
}

int main()
{
	{
		AutoPtr<Resource> res1(new Resource(10));
		cout << res1.m_ptr << endl;

		AutoPtr<Resource> res2(res1); // 복사 생성자
		// AutoPtr<Resource> res2;
		// res2 = res1; 이거는 복사 대입 생성자 

		cout << res1.m_ptr << endl; // 주소값 1
		cout << res2.m_ptr << endl; // 주소값 2 
		// (내부적으로 새롭게 동적할당 한 뒤, 거기에 복사하기)
		// copy semantics, value semantics
	}

	cout << endl;
	
	{
		AutoPtr<Resource> res1(new Resource(10));
		cout << res1.m_ptr << endl; // 주소값 1

		AutoPtr<Resource> res2(std::move(res1)); // 이동 생성자
		// std::move는 r-value를 리턴함
		// 생성자가 res1을 인식할때 l-value가 아니라 r-value로 인식해주는 것
		
		// (새롭게 동적할당해서 쓰는거라면 문제는 없긴 하지만)
		// res1은 이제 더 이상 사용하지 않을 것이라고
		// 프로그래머가 판단했을 때 r-value처럼 넘겨줘 버릴 수 있다.

		cout << res1.m_ptr << endl; // 주소값 1
		cout << res2.m_ptr << endl; // 주소값 2 
		// move semantics
		// 주소를 빼앗기고 nullptr이 되며
		// 빼앗은 얘는 뺏긴 얘의 주소값을 갖게 된다.
	}

	cout << endl;

	{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		res1->print();
		res2->print();

		MySwap(res1, res2);

		res1->print();
		res2->print();
		// Resource 에 대해서 이동 생성자, 이동 대입 생성자 등을
		// 우리가 직접 구현해 놓았기 때문에 가능한 일이다.
	}
	cout << endl;
	{
		vector<string> v;
		string str = "Hello";
		
		v.push_back(str); 
		// push_back 위에 마우스를 올려놔보자.
		// l-value로 받아들인다. copy-semantics 사용한다.
		
		cout << str << endl;	// Hello
		cout << v[0] << endl;	// Hello

		v.push_back(std::move(str));
		// push_back 위에 마우스를 올려놔보자.
		// r-value로 받아들인다. move-semantics
		
		cout << str << endl; // 아무것도 출력 안됨, move-semantics라서 빼앗긴 것
		cout << v[0] << " " << v[1] << endl; // Hello Hello

		// std::vector를 구현한 사람들이
		// r-value에 대해서 이동 생성자, 이동 대입 생성자 등을
		// 미리 구현해놓았기 때문에 std::move를 사용 가능 한것.
	}
	cout << endl;
	{
		string x("abc");
		string y("de");

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;

		MySwap(x, y);

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}
}