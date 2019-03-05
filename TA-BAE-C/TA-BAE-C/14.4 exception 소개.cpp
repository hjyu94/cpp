#include <iostream>
#include <string>
#include <exception>
using namespace std;

class CustomException : public std::exception
{
public:
	// noexcept: not throw any exception
	// 해당 함수 안에서는 예외를 던지지 않겠다.
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

void main()
{

	try
	{
		std::string s; // std library라서 std::Exception에서 잡아줄 수 있음
		s.resize(-1); 
		// 음수로 resize 할 수 없음
		// 내부적으로 Exception을 throw함

	}
	// exception: 부모 클래스
	// length_error: 자식 클래스
	catch (std::length_error& exception)
	{
		cout << "length_error" << endl;
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		// class std::length_error
		cerr << exception.what() << endl;
		// string too long
	}
	
	/********************************************/

	try
	{
		throw runtime_error("Bad thing happend");
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		// class std::runtime_error
		cerr << exception.what() << endl;
		// Bad thing happened
	}

	/********************************************/
	
	try
	{
		throw CustomException();
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		// class CustomException
		cerr << exception.what() << endl;
		// Custom exception
	}

}