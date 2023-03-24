#include "8.8_class_header.h"

using namespace std;
// cpp ������ �ٸ� ���Ͽ� include ���� �ʱ� ������
// ������ϰ� �ٸ��� using namespace �� �ᵵ ���� �����ϴ�.
 
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
