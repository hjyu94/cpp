#include <iostream>
using namespace std;

template<typename T>
class Resource
{
public:
	T* m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource()
	{
		cout << "Resource default constructor" << endl;
	}

	Resource(unsigned length)
	{
		m_data = new T[length];
		m_length = length;
	}

	Resource(const Resource& res)
	{
		// deep copy (shallo copy, X)
		cout << "Resource copy constructor" << endl;
		Resource(res.m_length);
		for (unsigned i = 0; i < res.m_data; ++i)
			m_data[i] = res.m_data[i];
	}

	~Resource()
	{
		cout << "Resource dstroyed" << endl;
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}
	}

	// copy assignment
	Resource& operator = (Resource& res)
	{
		cout << "Resource copy assignment" << endl;
		
		if (&res == this) return *this;
		if (this->m_data != nullptr) delete[] m_data;

		m_length = res.m_length;
		m_data = new T[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];

		return *this;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			cout << m_data[i] << " ";
		cout << endl;
	}
};

template<typename T>
class AutoPtr
{
private:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
		cout << "AutoPtr default constructor" << endl;
	}

	~AutoPtr()
	{
		cout << "AutoPtr destructor" << endl;
	}

	////##1. Parameter: L-value reference
	//
	//AutoPtr(const AutoPtr& a)
	//{
	//	cout << "AutoPtr copy constructor" << endl;
	//	
	//	// deep copy 
	//	// -> 내부적으로 복사하는 과정이 있어서 속도가 좀 느림
	//	*m_ptr = *a.m_ptr; // deep copy: resource copy assignment
	//	//m_ptr = a.m_ptr; // shallow copy
	//	a.m_ptr = nullptr; 
	//}
	//
	//AutoPtr& operator = (const AutoPtr& a)
	//{
	//	cout << "AutoPtr copy assignment" << endl;
	//	
	//	if (&a == this) return *this;
	//	
	//	m_ptr = new T;
	//	// deep copy
	//	// 모든 데이터를 하나하나 복사해오기 때문에 느려지기는 한다
	//	*m_ptr = *a.m_ptr;
	//	
	//	return *this;
	//}
	
	////##2. Parameter: R-value reference
	AutoPtr(AutoPtr&& a)
		// a는 메모리를 잡을 애가 아니라
		// 잠깐 있다가 사라질 놈
		// R value로 받아서 shallow copy만 진행
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // really necessary?
		// AutoPtr의 소멸자가 혹시나 소멸될까봐 안전의 차원

		cout << "AutoPtr move constructor" << endl;
		// 집을 넘겨줄 때 열쇠만 딱 주는 꼴.
		// 집을 통째로 들어서 옮기는 일이 필요 없음.
	}

	AutoPtr& operator = (AutoPtr&& a)
	{
		cout << "AutoPtr move assignment" << endl;
		
		if (&a == this)
			return *this;
		
		if (!m_ptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // really necessary?

		return *this;
	}
};

AutoPtr<Resource<int>> generateResource()
{
	AutoPtr<Resource<int>> res(new Resource<int>(100000));

	return res;
	// 복사하는 과정이 진행된다.
}

void main()
{
	{
		AutoPtr<Resource<int>> main_res;
		main_res = generateResource();
		// return 되는 값을 R-value
	}

}