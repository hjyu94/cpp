#include "8.8_class_header.h"

using namespace std;
// cpp 파일은 다른 파일에 include 되지 않기 때문에
// 헤더파일과 다르게 using namespace 를 써도 비교적 안전하다.
 
Calc::Calc(int init_value)
	: m_value(init_value)
{}

Calc& Calc::add(int value) { 
	m_value += value; 
	return *this; 
}

Calc& Calc::sub(int value) { 
	m_value -= value; 
	return *this; 
}

Calc& Calc::mul(int value) { 
	m_value *= value; 
	return *this; 
}
