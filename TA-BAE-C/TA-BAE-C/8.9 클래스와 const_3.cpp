// [C++] 클래스에서의 멤버 변수, 멤버 함수의 상수화 (const의 사용법)
// https://pacs.tistory.com/entry/C-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%97%90%EC%84%9C%EC%9D%98-%EB%A9%A4%EB%B2%84-%EB%B3%80%EC%88%98-%EB%A9%A4%EB%B2%84-%ED%95%A8%EC%88%98%EC%9D%98-%EC%83%81%EC%88%98%ED%99%94-const%EC%9D%98-%EC%82%AC%EC%9A%A9%EB%B2%95

// 레퍼런스 변수와 const 부분 다시 보기!

#include <iostream>

using namespace std;

class Something
{
public:
	string m_value = "default";

	/*string getValue() const
	{
		return m_value;
	}*/
	// 얘는 가능

	// 레퍼런스를 리턴하는데 함수가 const인 경우!
	/*const*/ string& getValue() const
		// 앞의 const 주석 처리하면 에러
	{
		cout << "const version" << endl;
		return m_value;
	}
	
	// string str = getValue();
	// str = "another";
	// 이런 일이 발생할 수 있다.

	// getValue()는 const 함수이므로 멤버 변수 값을 바꿔서는 안되므로
	// 이런 일이 생기는 것을 방지하고 싶으면
	// 반환 값으로 string&이 아니라 const string&을 사용해야 한다.
	
	// const string m_value = "default"; 일 때,
	// string& str_Ref = m_value;		// X
	// const string& str_Ref = m_value;	// O

	string& getValue()
	{
		cout << "non-const version" << endl;
		return m_value;
	}
};

void main()
{
	const Something const_sth;
	const_sth.getValue()=10;

	Something sth;
	sth.getValue()=10;
}

/*
오버로딩의 특징 :
1. 메소드 이름이 같아야 한다.
2. 리턴형이 같아도 되고 달라도 된다.
3. 파라미터 개수가 달라야한다.
4. 파라미터 개수가 같을 경우, 자료형이 달라야 한다.
(리턴타입은 같더라도 파라매터는 달라야 한다)

출처 : https ://memoryfilm.tistory.com/16 [린월의 Memory Film]
*/

// 파라매터가 같을때는 원래 오버로딩 안되지만 const의 여부로는 오버로딩이 가능하다.