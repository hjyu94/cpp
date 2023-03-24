#pragma once

#include <iostream>

// 헤더파일에서 이런식으로 쓰는건 좋지 않다.
//using namespace std;

class Calc
{
private:
	int		m_value;

public:
	Calc(int init_value);

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mul(int value);
};