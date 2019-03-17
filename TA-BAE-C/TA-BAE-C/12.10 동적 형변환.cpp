#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_iBase = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_iDer = 1024;

	virtual void print() override
	{
		cout << "I'm dervied" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm dervied" << endl;
	}
};

void main()
{
	{
		Derived1 d1;
		Base* base = &d1;

		/*
			부모 클래스에는 없고 자식 클래스에만 있는 것들을 
			접근할 수 없어진다.
			d1.m_iDer;		// O
			base->m_iDer;	// X
		*/

		// base 변수가 다시 Derived를 가리키도록 할 수는 없을까?
		// (d1 쓰면 되지 뭐하러 바꿨다가 도로 바꾸냐고 물어본다면
		// 파라매터로 Base의 포인터가 넘어가는 경우등에서 사용됨)

		// 근데 왠만하면 동적형변환 안하는게 좋음. 헷갈림
		auto* base_to_d1 = dynamic_cast<Derived1*>(base);
		// base->m_iDer;	 // X
		base_to_d1->m_iDer; // O // 불가능했었던게 가능해짐

		d1.m_iDer = 2048;
		cout << d1.m_iDer << endl; // 2048
		base_to_d1->m_iDer = 256;
		cout << d1.m_iDer << endl; // 256

		/**************************************************/

		// [주의사항]
		auto* base_to_d2 = dynamic_cast<Derived2*>(base);
		// cout << base_to_d2->m_name << endl;
		// 어라... 에러도 안 뜨고 아무것도 안 뜬다 왜지?
		// (Derived1 -> Base -> Derived2 라서 사실 당연하긴 함)

		if (base_to_d2 != nullptr)
			base_to_d2->print();
		else
			cout << "Failed" << endl;
		// 캐스팅에 실패하면 nullptr을 반납한다
	}
	cout << endl << endl;


	/******************************************************************************/
	// dynamic cast와는 달리
	// static cast는 할 수 있는 한 최대로 되는걸로 밀어붙인다.
	// 어떤 경우에는 안돼야 할 것도 됨.
	Derived1 d1;
	Base* base = &d1;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	if (base_to_d1 != nullptr)
	{
		base_to_d1->print();
		cout << base_to_d1->m_iDer << endl;;
	}
	else
		cout << "Failed" << endl;

	auto* base_to_d2 = dynamic_cast<Derived2*>(base);
	if (base_to_d2 != nullptr)
	{
		base_to_d2->print();
		cout << base_to_d2->m_name << endl;
	}
	else
		cout << "Failed" << endl;

	/*
		[출력]
		Derived
		1024
		Failed
	*/

	/********************************************************/

	base_to_d1 = static_cast<Derived1*>(base);
	if (base_to_d1 != nullptr)
	{
		base_to_d1->print();
		cout << base_to_d1->m_iDer << endl;;
	}
	else
		cout << "Failed" << endl;

	base_to_d2 = static_cast<Derived2*>(base);
	if (base_to_d2 != nullptr)
	{
		base_to_d2->print();
		cout << base_to_d2->m_name << endl;
	}
	else
		cout << "Failed" << endl;

	/*
		[출력]
		Derived
		1024
		Derived
		("Dr. Two" 가 나오지는 않는다.)
	*/

}