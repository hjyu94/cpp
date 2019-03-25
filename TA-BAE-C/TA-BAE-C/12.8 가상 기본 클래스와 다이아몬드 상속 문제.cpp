// 가상 기본 클래스

/*
		A			A	A
	  /   \			|	|
	B		C		B	C
	  \   /			 \ /
		D			  D

	다이아몬드 상속의 문제: 
		왼쪽과 같이 상속받았다고 생각했는데
		A의 멤버 변수 주소를 찍어보면 다르게 나옴. 
		오른쪽과 같은 상속구조를 가지게 된 것
*/

#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice: " << power << endl;
	}
};

class Scanner : public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << endl;
	}
};

class Printer : public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << endl;
	}
};


class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power)
	{
	}
};


int main()
{
	Copier cop(1, 2, 3);
	/*
		PoweredDevice: 3
		Scanner: 1

		PoweredDevice: 3
		Printer: 2

		생성자가 두번 호출됨
	*/

	//cout << cop.m_i << endl; // X // ambiguous

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;
	// 주소가 다르게 출력됨
}