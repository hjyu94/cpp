// 인터페이스 클래스: 순수 가상함수로만 이루어진 클래스
// 추상함수로 만들어진 함수들을 꼭 오버라이딩 해야 한다. 
// 외부에서 사용을 할 때 이러이러한 기능이 있을 거라고 예측하는 중개 역할.

#include <iostream>
#include <string>
using namespace std;

class IErrorLog // I+ErrorLog: I는 인터페이스 의미
{
public:
	/* 가상함수 */ virtual bool reportError(const char* errorMessage) = 0;
	/* 가상함수 */ virtual ~IErrorLog() {}
	// 소멸자는 가상함수일지라도 자식 클래스에서 따로 오버라이딩해주지 않아도 ㄱㅊ
	// 기본 소멸자가 만들어짐.
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage)
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage)
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

// 파라매터: 부모 클래스의 참조변수나 포인터변수
// 실인자: 자식 클래스의 객체

void doSomething(IErrorLog& log) // 파라매터로 인터페이스의 오브젝트를 사용
{
	log.reportError("Runtime error!!");
	// 부모 클래스의 참조변수에 자식 클래스의 객체를 넘겨주어
	// 다형성을 발현시킨다.
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}