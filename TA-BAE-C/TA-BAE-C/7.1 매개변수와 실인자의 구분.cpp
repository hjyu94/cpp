#include <iostream>

using namespace std;

//#### 매개변수와 실인자의 구분
int foo(int x, int y); // prototype
// x, y는 foo라는 함수의 parameter, 매개변수

int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here


//#### 값에 의한 전달
void doSomething(int x)
{
	cout << "In func " << x << ", " << &x << endl;
} 
// 새롭게 변수를 만들고 실인자의 값이 매개변수 x로 복사된다.


//#### 참조에 의한 전달
void doSomething2(int &x)
{
	cout << x << ", " << &x << endl;
	x = x + 1;
}
// 레퍼런스 변수를 이용하기 때문에 주소도 똑같고 복사도 이뤄지지 않는다.


// degree: 값에 의한 전달, 값이 바뀌어도 함수를 나갈때 사라짐. 입력으로 쓰인 것
// sin_out, cos_out: 참조에 의한 전달, 값이 바뀐다. 입출력으로 쓰임
// 레퍼런스를 함수를 이용해서 여러개의 값을 리턴해주는 꼴로 사용한 예

// const double degree: 매개변수가 const인 경우?
//	: 함수 내에서 해당 변수의 값을 바꾸지 않겠다.
// cf) 함수가 const인 경우?
//	: 클래스에서 멤버 함수를 const로 만들 수 있는데
//	: 해당 클래스의 멤버 변수 값을 바꾸지 않겠다는 표시이다.
void getSinCos(const double degree, double &sin_out, double &cos_out)
{
	static const double pi = 3.141592;
	// static: 한번 정의되면 나중에 또 정의될때는 재정의 되지 않음. 재사용된다.
	// 함수 밖에서는 pi 변수 사용 불가 (4.2 참고)

	double radians = degree * pi / 180.0;

	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

//#### 포인터에 의한 전달
void doSomething3(int *&ptr) /* ((int*) &ptr) */
{
	cout << ptr << ", " << &ptr << endl;
}
// 이 경우 포인터 변수를 레퍼런스 변수로 받기 때문에
// 함수 내에서 출력한 포인터 변수의 주소도 동일하게 출력된다.

int main()
{
	foo(6, 7); 
	// 이때 6과 7을 arguments, actual parameter 라고 한다
	// foo 함수의 매개변수 x, y로 6, 7이 복사된다. 

	cout << "값에 의한 전달" << endl;
	int x = 6;
	cout << "In main " << x << ", " << &x << endl;
	doSomething(x);
	cout << endl;
	
	cout << "참조에 의한 인수 전달" << endl;
	int y = 10;
	cout << y << ", " << &y << endl;
	doSomething2(y);
	cout << y << ", " << &y << endl;

	double sin(0.0);
	double cos(0.0);
	getSinCos(30.0, sin, cos);
	cout << sin << ", " << cos << endl;
	cout << endl;

	// 참조에 의한 인수 전달의 단점
	doSomething2(5);
	// 이처럼 참조변수가 들어가야 할 자리에 리터럴 상수값이 들어오게 된다면
	// void doSomething2(int &x)를
	// void doSomething2(const int &x)나
	// void doSomething2(int x)로 바꾸면 된다

	// 이럴 경우를 대비해서 매개변수들은 가능하다면
	// 정의할 때부터 const로 지정해주면 좋다.

	cout << "포인터를 인수로 전달" << endl;
	int z = 5;
	int *ptr = &z;
	doSomething3(ptr);
	// void doSomething3(int *&ptr);

}