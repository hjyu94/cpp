#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	{
		stringstream os;

		// string stream에 문자열 넣기
		os << "Hello, World!"; // <<: insertion operator // extraction operator
		os.str("Hello, World!"); // 현재 버퍼에 있는 것을 바꿈

		string str;

		//// ' ' 있으면 구분자로 사용함
		//os >> str;
		//cout << str << endl; // Hello,

		str = os.str(); // 버퍼에 있는 것 모두 가져오기
		cout << str << endl; // Hello, World!

		os << "Hello, World!";
		os << "Hello, World!";
		str = os.str();
		cout << str << endl; // Hello, World!Hello, World!

		os << "Hello, World!";
		os << "Hello, World!";
		os.str("Hello, World!\n"); // 현재 버퍼를 비우고 넣는다. 개행도 읽는다.
		str = os.str();
		cout << str << endl;

		os << "Hello, World!" << endl; // string stream에 endl도 들어간다.
		str = os.str();
		cout << str << endl;

		os.str("12345 67.89");
		string str1;
		string str2;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl;

		os.str("1234567.89");
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl;
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		string str1, str2;

		os << i << d;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl; // 1234567.89|
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		string str1, str2;

		os << i << " " << d;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl; // 12345|67.89
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		//os << i << " " << d;
		os << "12345 67.89";

		int i2;
		double d2;

		os >> i2 >> d2;

		cout << i2 << "|" << d2 << endl;
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		os << "12345 67.89";
		
		// os.str(""); // 파라매터가 있으면 버퍼를 덮어씌우고
		// == os.str(string());
		
		os.clear(); // state까지 초기화
		
		os << "Hello";
		cout << os.str() << endl; // 파라매터가 없으면 리턴을 한다.
		// 12345 67.89Hello
	}
	return 0;
}