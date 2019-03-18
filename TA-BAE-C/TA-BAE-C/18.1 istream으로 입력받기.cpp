#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void main()
{
	cout << "Enter a number" << endl;
	
	int i;
	cin >> i;
	cout << i << endl;

	/**********************************/

	char buf[5];

	cin >> buf;
	// [입력] abcde // 에러
	// [입력] abcd  // OK

	cout << buf << endl;

	/**********************************/

	// 그럼 항상 조심해서 입력해야 하느냐?
	// #include <iomanip>
	char buf2[5];

	cin >> setw(5) >> buf2;
	cout << buf2 << endl;
	// setw(5): 
	// 버퍼에 내용이 들어가고 그 중에서 5개만 가지고 옴
	// 마지막 글자 자리에는 널 포인터가 들어감
	// 
	// 여러 글자를 입력하면 5글자를 기준으로 뜯어서 받아들임
	// 나머지 글자는 버퍼에 그대로 남아있다.	

	cin >> setw(5) >> buf2;
	cout << buf2 << endl;

	cin >> setw(5) >> buf2;
	cout << buf2 << endl;

	/**********************************/

	// 한글자씩 계속 받아보자
	char ch;

	while (cin >> ch)
		cout << ch;
	// [입력] Hello World
	// [출력] HelloWorld
	
	/**********************************/
	
	int i;
	float f;
	cin >> i >> f;
	cout << i << " " << f << endl;
	// [입력] 1024 3.14
	// [출력] 1024 3.14
	//
	// 빈칸으로 구분이 되어진다.

	/**********************************/

	// 빈칸조차 받고 싶은 경우
	while (cin.get(ch))
		cout << ch;
	// [입력] Hello. World
	// [출력] Hello. World
	// 
	// 빈칸도 잘 읽어온다.

	/**********************************/
	
	char buf3[5];
	cin.get(buf3, 5);
	cout << buf3 << endl;
	// [입력] Hello. World
	// [출력] Hell

	/**********************************/

	char buf4[5];
	cin.get(buf4, 5);
	cout << cin.gcount() << buf4 << endl;
	cin.get(buf4, 5);
	cout << cin.gcount() << buf4 << endl;
	
	// [입력] Hello. World!!
	// [출력] 4 Hell
	//		  4 o. W
	//
	// cin.gcount(): 몇 글자 읽어들였는지 세는 함수

	/**********************************/

	char buf5[5];
	cin.getline(buf5, 5); // 어쨌던 줄을 한번에 다 읽어옴
	cout << cin.gcount() << buf5 << endl; // 4 Hell
	cin.getline(buf5, 5); // 첫번째 getline이 한줄을 다 읽어버려서 더이상 읽을게 X
	cout << cin.gcount() << buf5 << endl;

	/**********************************/

	char buf6[100];
	cin.getline(buf6, 100);
	cout << cin.gcount() << " " << buf6 << endl;
	// [입력] Hello
	// [출력] 6 Hello
	//
	// 줄바꿈 문자까지 같이 읽는다

	/**********************************/

	char buf7[100];
	cin.get(buf7, 100);
	cout << cin.gcount() << " " << buf7 << endl;
	
	// [입력] Hello
	// [출력] 5 Hello
	//		  1
	
	/**********************************/

	string str_buf;
	getline(cin, str_buf);
	cout << cin.gcount() << " " << str_buf << endl;
	// [입력] Hello. World
	// [출력] 0 Hello. World
	//
	// 버퍼 사이즈를 전혀 고민 하지 않고 읽어옴

	/**********************************/

	char buf8[1024];

	cin.ignore();
	cin >> buf8;
	cout << buf8 << endl;
	// [입력] Hello
	// [출력] ello
	//
	// cin.ignore() 입력받은 문자를 (인자값)개 만큼 무시함

	cin.ignore(2);
	cin >> buf8;
	cout << buf8 << endl;
	// [입력] Hello
	// [출력] llo

	/**********************************/

	char buf9[1024];
	cout << (char)cin.peek() << endl;
	cin >> buf9;
	cout << buf9 << endl;
	// [입력] Hello
	// [출력] H
	//		 Hello
	//
	// 보통 한개 읽어들여서 버퍼에서 하나 꺼내기 때문에
	// 다음에서는 ello 가 출력되는게 일반적인데
	// peek은 들여다 보기만 하고 꺼내지는 않는 것
	// 가장 먼저 읽어올 글자가 뭔지 살짝 들여다 보는 것 뿐
	// 버퍼에서 꺼내지 않아서 다음에 출력할때 영향 끼치지 X

	/**********************************/

	char buf10[1024];

	cin >> buf10;
	cout << buf10 << endl;
	
	cin.unget();
	
	cin >> buf10;
	cout << buf10 << endl;

	// [입력] Hello
	// [출력] Hello
	//		 o
	//
	// peek()의 반대 개념. 
	// 마지막에 읽은 문자를 도로 버퍼에 넣는다.

	/**********************************/

	char buf11[1024];

	cin >> buf11;
	cout << buf11 << endl;

	cin.putback('A');

	cin >> buf10;
	cout << buf10 << endl;
	
	// [입력] Hello
	// [출력] Hello
	// 		  A
	//
	// putback() 원하는 글자를 다시 버퍼에 집어 넣는다.
}