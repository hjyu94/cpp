// https://thrillfighter.tistory.com/531

#include <iostream>
using namespace std;

// 1과 2중 더 보안에 강력한 것으로 변한다.

class Base
{
private: /* 1-얘들 */
	int m_private;
protected:
	int m_protected;
public:
	int m_public;

	// 기반 클래스 내에서는 모두 접근 가능
	void setValue(int a, int b, int c)
	{
		m_public = a;
		m_protected = b;
		m_private = c;
	}
};

class public_Derived : /*2-여기*/ public Base
{
public:
	public_Derived(int a=0, int b=0, int c=0)
	{
		Base::m_public = a;
		Base::m_protected = b; // protected: 파생클래스의 정의부에서는 접근이 가능하지만
		Base::m_private = c;
	}
};

void A1(public_Derived public_derived){
	public_derived.m_public;
	public_derived.m_protected; // 외부에서는 접근이 불가능하다. 
								// (기반클래스의 객체나, 파생클래스의 객체)
	public_derived.m_private;
}

/******************************************************************************************************/

class protected_Derived : protected Base
// protected 상속 : 
// 기반 클래스의 속성 접근 지정자의 의미를 최소 protected로 만든다.
{
public:
	protected_Derived(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// -> protected
		Base::m_protected = b;	// 원래 protected
		Base::m_private = c;	// 원래 private으로 접근 불가
	}
};

void B1(protected_Derived protected_derived) {
	// protected 상속을 받아서
	// 모든 변수가 최소 protected인 상태

	protected_derived.m_public;		// protected 이므로 외부에서 접근 불가능
	protected_derived.m_protected;	// protected 이므로 외부에서 접근 불가능
	protected_derived.m_private;	// X
}


class protected_Derived2 : public protected_Derived
{
public:
	protected_Derived2(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// protected 이므로 접근 가능
		Base::m_protected = b;	// protected 이므로 접근 가능
		Base::m_private = c;	// 원래 private으로 접근 불가
	}
};

void B2(protected_Derived2 protected_derived) {
	protected_derived.m_public;		// protected 이므로 외부에서 접근 불가능
	protected_derived.m_protected;	// protected 이므로 외부에서 접근 불가능
	protected_derived.m_private;	// X
}

/******************************************************************************************************/

class private_Derived : private Base
{
public:
	private_Derived(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// -> private
		Base::m_protected = b;	// -> private
		Base::m_private = c;	// 원래 private으로 접근 불가
	}
};

void C(private_Derived private_derived)
{
	private_derived.m_public;		// private 이므로 접근 불가능
	private_derived.m_protected;	// private 이므로 접근 불가능
	private_derived.m_private;		// private 이므로 접근 불가능
}



class private_Derived2 : public private_Derived
{
public:
	private_Derived2(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// private 이므로 접근 불가능
		Base::m_protected = b;	// private 이므로 접근 불가능
		Base::m_private = c;	// private 이므로 접근 불가능
	}
};

void C2(private_Derived2 private_derived)
{
	private_derived.m_public;		// private 이므로 접근 불가능
	private_derived.m_protected;	// private 이므로 접근 불가능
	private_derived.m_private;		// private 이므로 접근 불가능
}