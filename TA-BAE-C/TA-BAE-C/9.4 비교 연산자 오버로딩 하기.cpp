// std::sort()를 사용하려면 크기 비교 연산자가 되어있어야 한다.

#include <iostream>
#include <vector>
#include <algorithm> // for sorting
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend ostream& operator << (ostream& out, Cents cents)
	{
		out << cents.m_cents;
		return out;
	}

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}

	friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents > c2.m_cents;
	}

	// std::sort() 에서 내부적으로 > 연산자가 아니라 < 연산자를 사용한다.
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		//return c1.m_cents < c2.m_cents;
		return c1.m_cents > c2.m_cents;
	}
};

void main()
{
	// 기본 데이터 타입
	int a = 3, b = 3;
	if (a == b)
		cout << "Equal int" << endl;
	
	// 사용자 정의 자료형
	Cents cents1(6);
	Cents cents2(5);
	if(cents1 == cents2)
		cout << "Equal cents" << endl;
	if(cents1 != cents2)
		cout << "Not equal cents" << endl;

	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << ' ';
	cout << endl;

	std::sort(begin(arr), end(arr)); 
	// 크기 비교 연산자를 오버로딩해주지 않으면 객체들을 서로 비교할 수 없음

	for (auto& e : arr)
		cout << e << ' ';
	cout << endl;

}