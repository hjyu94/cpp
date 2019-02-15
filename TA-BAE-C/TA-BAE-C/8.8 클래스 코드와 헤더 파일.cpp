#include "8.8 클래스 코드와 헤더 파일.h"

inline Calc & Calc::add(int value)
{
	m_value += value;
	return *this;
}

inline Calc & Calc::add1(int value)
{
	m_value += value;
	return *this;
}

inline Calc & Calc::add2(int value)
{
	m_value += value;
	return *this;
}
