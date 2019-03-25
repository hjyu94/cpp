#include <iostream>
using namespace std;

class Resource
{
public:
	int* m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource()
	{
		cout << "Resource default constructed" << endl;
	}

	Resource(unsigned length)
	{
		cout << "Resource length constructed" << endl;
		m_data = new int[length];

		for (unsigned i = 0; i < length; ++i)
			m_data[i] = i;

		m_length = length;
	}

	Resource(const Resource& res)
	{
		cout << "Resource copy constructed" << endl;
		// deep copy (shallow copy X)
		Resource(res.m_length);
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];
	}

	~Resource()
	{
		cout << "Resource destroyed" << endl;
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}
	}

	// [copy assignment]
	// deep copy
	// AutoPtr<Resource> res2 = res1;
	// *m_ptr = *a.m_ptr; 이때 호출된다.
	Resource& operator = (Resource& res)
	{
		cout << "Resource copy assignment" << endl;
		
		if (&res == this) return *this;
		if (this->m_data != nullptr) delete[] m_data;

		m_length = res.m_length;
		m_data = new int[m_length];

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
	AutoPtr()
	{
		m_ptr = new T;
		cout << "AutoPtr default constructed" << endl;
	}

	AutoPtr(T* ptr)
		: m_ptr(ptr)
	{
		cout << "AutoPtr default constructed2" << endl;
	}

	~AutoPtr()
	{
		cout << "AutoPtr destructor" << endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	//##1. Parameter: L-value reference
	AutoPtr(AutoPtr& a)
	{
		cout << "AutoPtr copy constructed" << endl;
		
		// deep copy 
		// -> 내부적으로 복사하는 과정이 있어서 속도가 좀 느림
		m_ptr = new T;
		*m_ptr = *a.m_ptr; 
		// deep copy: resource copy assignment 호출됨
		// res1 = res2 꼴

		// m_ptr = a.m_ptr; // shallow copy

		//a.m_ptr = nullptr; 
	}
	
	AutoPtr& operator = (const AutoPtr& a)
	{
		cout << "AutoPtr copy assignment" << endl;
		
		if (&a == this) return *this;
		if (m_ptr != nullptr) delete m_ptr;

		// deep copy
		// 모든 데이터를 하나하나 복사해오기 때문에 느려지기는 한다
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
		
		return *this;
	}
	
	////##2. Parameter: R-value reference
	AutoPtr(AutoPtr&& a)
		// a는 메모리를 잡을 애가 아니라
		// 잠깐 있다가 사라질 놈
		// R value로 받아서 shallow copy만 진행
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // really necessary?
		// AutoPtr의 소멸자가 혹시나 소멸될까봐 안전의 차원

		cout << "AutoPtr move constructed" << endl;
		// 집을 넘겨줄 때 열쇠만 딱 주는 꼴.
		// 집을 통째로 들어서 옮기는 일이 필요 없음.
	}

	AutoPtr& operator = (AutoPtr&& a)
	{
		cout << "AutoPtr move assignment" << endl;
		
		if (&a == this) return *this;
		if (!m_ptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // really necessary?

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10));
	return res;
	// 복사하는 과정이 진행된다.
}

void main()
{
	// l value parameter
	{
		AutoPtr<Resource> res1(new Resource(10));
		AutoPtr<Resource> res2 = res1;
	}
	cout << endl;

	// r value parameter
	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
		// return 되는 값을 R-value

		cout << main_res->m_data[2] << endl;
	}

}