#include <iostream>

using namespace std;

class A_Device
{
private:
	int m_id;

public:
	A_Device(const int& id) { m_id = id; };
	void doA() {};
	int getID() { return m_id; };
};

class B_Device
{
private:
	int m_id;

public:
	B_Device(const int& id) { m_id = id; };
	void doB() {};
	int getID() { return m_id; };
};

// 다중 상속
class AB_Device : public A_Device, public B_Device
{
public:
	AB_Device(int a_id, int b_id)
		: A_Device(a_id), B_Device(b_id)
	{}
};

void main()
{
	AB_Device AandB(10, 20);

	// A의 함수와 B의 함수 모두 호출 가능
	AandB.doA();
	AandB.doB();
	
	// 같은 이름의 함수가 있는 경우는 어떻게 해야 할까?
	AandB.getID();				// X // 모호성
	AandB.A_Device::getID();	// O
	AandB.B_Device::getID();	// O

}