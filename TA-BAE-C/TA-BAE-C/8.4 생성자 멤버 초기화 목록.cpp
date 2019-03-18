		#include <iostream>

		using namespace std;

		class B
		{
		public:
			int m_b;

			B(const int& m_b_in)
/*7*/			: m_b(m_b_in)
/*6*/		{		
/*8*/			cout << "B constructor" << endl;
/*9*/		}
		};

		class Something
		{
		private:
			int	m_i = 999;
			int m_arr[5] = { 999, };
			B	m_b{ 999 };
			// 얘네가 가장 쪼렙. 약하다

		public:
			Something()
/*3*/			: m_i{ 1 },
/*5*/			m_b{ m_i - 1 },
/*4*/			m_arr{ 1,2,3,4,5 } /* 배열도 이니셜라이즈 리스트 사용 가능*/
/*2*/		{
/*10*/			m_i = 2; // 이게 제일 쎔
/*11*/			cout << "Something constructor" << endl;
/*12*/		}
		};

		int main()
		{
/*1*/		Something sth1;
			// 초기화를 클래스 내에서 기본값을 넣어줄수도 있고
			// 생성자에서 이니셜라이즈 리스트를 사용할수도 있는데
			// 둘 다 쓰게 되면 생성자가 우선이다.

			// 생성자의 {} 안에 넣어준 값이 최종값이 된다.
		}
