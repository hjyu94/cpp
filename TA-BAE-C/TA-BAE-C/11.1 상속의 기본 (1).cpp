#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}
};

class Daughter /* 상속! */: public Mother 
{
private:
	double m_d;

public:
	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};

int main()
{
	Mother mom; // 기본 생성자만 있을 때 이런식으로 생성 가능
	// 다른 경우라면 mom(인자1, 인자2, ...) 처럼 괄호가 필요하다
	mom.setValue(10); // 여기서는 m_i에 값 할당

	Daughter me;
	me.setValue(10); // 여기서는 m_i에? m_d에? 어디에 할당할까 // m_d에 할당함
					 // Daughter의 setValue가 호출됨
	
	// 만약 Daughter에서 오버라이딩 된 함수가 아니라
	// 부모의 함수를 호출하고 싶으면?
	me.Mother::getValue();
}

// 그럼 me를 이용해서 m_i에 값을 할당하고 싶으면?

/************************************************************/

class Mother
{
private:
	int m_i;

public:
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}
};

class Daughter : public Mother
{
private:
	double m_d;

public:
	void setValue(const int& i_in, const double& d_in)
	{
		// m_i이 private이라서 불가능
		m_i = i_in;
		m_d = d_in;

		// 해결법!
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};

int main()
{
	Daughter me;
	me.setValue(10, 13.4);
}

/********************************************************/

// 생성자: 메모리를 할당 할 때 값을 넣어준다
// 메모리를 할당 해놓고 나중에 값을 복붙해주는 역할이 아님

/********************************************************/

// const double degree: 매개변수가 const인 경우?
//	: 함수 내에서 해당 변수의 값을 바꾸지 않겠다.

// cf) 함수가 const인 경우?
//	: 클래스에서 멤버 함수를 const로 만들 수 있는데
//	: 해당 클래스의 멤버 변수 값을 바꾸지 않겠다는 표시이다.
