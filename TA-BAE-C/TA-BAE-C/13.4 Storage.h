#pragma once
#include <iostream>

template<typename T>
class Storage
{
public:
	T m_data;

	Storage(T value)
	{
		m_data = value;
	}

	~Storage()
	{}

	// double type에 대해서 instantiation 될 때는
	// 다른 기능을 수행했으면 좋겠다고 하면?
	void print()
	{
		using namespace std;
		cout << m_data << endl;
	}
};

//template<>
//void Storage<double>::print()
//{
//	using namespace std;
//	cout << "Double Type" << endl;
//	cout << m_data << endl;
//	cout << std::scientific << m_data << endl; // scientific notation
//}
// 헤더파일과 cpp 파일을 분리해서 쓰고 싶은데..?
// 아무 표시 없이 cpp 파일에 빼면 템플릿 특수화를 했다는 걸 컴파일러가 모름

// 해결방법? 
// 헤더파일에 정의 선언 분리하지 말고 다 적어주기 (헤더온리)
// main.cpp 에서 #include "Storage.cpp" 적어주기