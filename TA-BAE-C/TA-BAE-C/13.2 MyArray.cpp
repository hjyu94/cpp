#include "13.2 MyArray.h" // 써야 함 주의.

template<typename T>
inline int MyArray<T>::getLength()
{
	return m_length;
}

// cpp 파일로 함수의 정의를 따로 빼는 경우
// 템플릿 사용 주의


// explicit instantiation

template void MyArray<char>::print();
// print라는 함수를 char type에 대해 instantiation 하겠다!
template void MyArray<int>::print();
template void MyArray<double>::print();
template void MyArray<float>::print();

template class MyArray<char>;
template class MyArray<int>;
template class MyArray<double>;
template class MyArray<float>;
// class 자체를 특정 타입에 대해 instantiation 해줄수도 있다.
