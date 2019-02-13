#include <iostream>

using namespace std;

void getSinCos(const double degree, double *sin_out, double *cos_out)
{
	static const double pi = 3.141592;
	// static: 한번 정의되면 나중에 또 정의될때는 재정의 되지 않음. 재사용된다.

	double radians = degree * pi / 180.0;

	/* de-referencing */       *sin_out = std::sin(radians);
	/* 포인터가 가리키는 실제 값*/ *cos_out = std::cos(radians);
}

int main()
{
	double degree = 30;
	double sin, cos;

	getSinCos(degree, &sin, &cos);

	cout << sin << ", " << cos << endl;
}