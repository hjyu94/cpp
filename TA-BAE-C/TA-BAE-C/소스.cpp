#include <iostream>
using namespace std;

class Resource
{
public:
	int* m_data;
	int m_length;

	Resource(const int _length)
	{
		cout << "Resource 持失切" << endl;
		m_data = new int[_length];
		m_length = _length;
	}


};

template <typename T>
class AutoPtr
{
public:
	T* m_ptr;

	AutoPtr(T* _ptr = nullptr)
	{
		cout << "AutoPtr 持失切" << endl;
		m_ptr = _ptr;
	}

	
};

void main()
{
	AutoPtr<Resource> res1(new Resource(10));
	AutoPtr<Resource> res2 = res1;
}