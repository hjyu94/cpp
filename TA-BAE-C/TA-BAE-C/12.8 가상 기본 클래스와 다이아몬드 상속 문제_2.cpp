// 다이아몬드 상속의 문제를 해결하는 법: 가상 기본 클래스

#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PowerDevice: " << power << endl;
	}
};

//class Scanner : public PoweredDevice
class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << endl;
	}
};

//class Printer : public PoweredDevice
class Printer : virtual public PoweredDevice
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
		// , PoweredDevice(power) // PoweredDevice의 생성자 호출
	{
	}
};

int main()
{
	Copier cop(1, 2, 3);
	/*
		PoweredDevice: 3 // 생성자가 한번만 호출된다
		Scanner: 1
		Printer: 2
	*/

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;
	// 두 주소가 똑같이 출력됨. 같은얘를 가리킨다는 얘기
}