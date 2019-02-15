#pragma once

#include <iostream>

using namespace std; 
// include하는 파일들에 전부 영향을 끼쳐버려서 여기에 안 쓰는게 좋음

class Calc
{
	//  using namespace std; // X

private:
	//	using namespace std; // X
	int m_value;

public:
	//	using namespace std; // X
	Calc(int init_value)
		: m_value(init_value)
	{}

	Calc& add(int value) 
	{
		m_value += value; 
		return *this; 
	}
	
	Calc& add1(int value) 
	{ 
		m_value += value; 
		return *this; 
	}
	
	Calc& add2(int value) 
	{ 
		m_value += value; 
		return *this; 
	}

	Calc& add3(int value) 
	{ 
		m_value += value; 
		return *this; 
	}

	void print()
	{
		using namespace std;
		cout << m_value << endl;
	}
};

/***********************************************/

// 헤더파일이 너무 길면 읽기 불편함
// 헤더파일엔 선언만 남겨두고
// 정의는 따로 빼두는게 좋다.

#pragma once

#include <iostream>

class Calc
{

private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	// 함수명 위에서 우클릭 - 빠른 작업 및 리팩터링 - 선언 위치 이동 - Ctrl + S (저장)
	Calc& add(int value);
	Calc& add1(int value);
	Calc& add2(int value);
	Calc& add3(int value)
	{
		m_value += value;
		return *this;
	}

	void print()
	{
		using namespace std;
		cout << m_value << endl;
	}
};
