#pragma once

#include "13.4 Storage.h"

template<>
void Storage<double>::print()
{
	using namespace std;
	cout << "Double Type" << endl;
	cout << m_data << endl;
	cout << std::scientific << m_data << endl; // scientific notation
}