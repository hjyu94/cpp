#include <iostream>
#include <string>

using namespace std;

void main()
{
	// try, catch, throw
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw string("Negative input"); // O
		// if (x < 0.0) throw "Negative input"; // X
		// 우리 생각엔 string으로 바뀌어서 잘 들어갈 것 같지만
		// 예외처리는 형변환에 굉장히 엄격해서 안됨.
		// 이런 경우라면
		// catch(const char* error_message){...} 가 있어야 함

		throw - 1.0; // X
		// double을 받아주는 얘가 없어서 런타임 에러

		cout << sqrt(x) << endl;
	}

	catch (int x)
	{
		cout << "Catch integer: " << x << endl;
	}

	catch (string error_message)
	{
		cout << error_message << endl;
	}
} 