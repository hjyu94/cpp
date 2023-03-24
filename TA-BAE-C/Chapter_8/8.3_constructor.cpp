#include <iostream>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction() // no return type
	{
		m_numerator = 0;
		m_denominator = 1;

		cout << "Fraction() constructor" << endl;
	}

	// ���� �����ڰ� �ƹ��͵� ������
	// �����Ϸ��� �����ڸ� ���Ƿ� ���� �־��ش�.
	// Fraction() {}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print1()
{
	// �޸𸮿� �ν��Ͻ��� �ڸ��� ������ �ٷ� �����ڰ� �����.
	// �����ڿ� �Ķ���Ͱ� �ϳ��� ���� ���� frac() ��� frag ���� ��� �Ѵ�.
	Fraction frac; 

	frac.print();

	return 0;
}

//

class Fraction2
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction2(const int& num_in, const int& den_in = 1 /* default parameter */)
	{
		m_numerator = num_in;
		m_denominator = den_in;

		cout << "Fraction() constructor" << endl;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print2()
{
	Fraction2 one_thirds(1);
	one_thirds.print();

	return 0;
}

//

class Fraction3
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction3()
	{
		m_numerator = 1;
		m_denominator = 3;
	}

	Fraction3(const int& num_in = 1, const int& den_in = 3)
	{
		m_numerator = num_in;
		m_denominator = den_in;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print3()
{
	// ����Ʈ �����ڸ� ���� ���� ���� frac() �� �ƴ϶� frac �� �θ��µ�
	// ���� Ŭ������ �����ڿ� ����Ʈ �����ڶ�� ������ �� �ִ� �Լ��� 2�� �̻��̶� ���� �߻�
	// �����ϴ� ������ �� ��� �Ķ���Ϳ� ���� ����Ʈ �Ķ���͸� ���� �ִ� �����ڴ� ����Ʈ �����ڷ� ����.
	Fraction3 frac;

	return 0;
}

//


class Fraction4
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction4(const int& num_in = 1, const int& den_in = 3)
	{
		m_numerator = num_in;
		m_denominator = den_in;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int print4()
{
	// assign operator overloading �� ������ ����Ʈ�� �����.
	Fraction4 copy = Fraction4{ 1, 3 };

	// uniform initialization
	// public field �� ��� ����.
	// �굵 ������ ȣ�� ���ش�.
	// �� Ÿ�Ժ�ȯ�� ������ �ʾƼ� f1{ 1.0, 3 }; �̷������� ��� �Ұ���
	Fraction4 f1{ 1, 3 };

	// ���� ����ϱ� ������ Ÿ�Ժ�ȯ�� ���ش�. ��� warning ������ ����Ѵ�.
	// f2(1.0, 3); �� ����.
	Fraction4 f2(1, 3);
	return 0;
}

//

class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor" << endl;
	}
};

int test()
{
	// class Second constructor()
	// class First constructor()
	// ����ʵ�� �� �ִ� sec �� �����ں��� ȣ��ȴ�.
	First fir;

	return 0;
}