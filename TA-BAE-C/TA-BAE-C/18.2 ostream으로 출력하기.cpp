#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout.setf(std::ios::showpos); // 플래그 셋팅
	cout << 108 << endl; // +108 // 부호까지 출력

	cout.unsetf(std::ios::showpos); // 플래그 셋팅 해제
	cout << 108 << endl; // +108 // 부호까지 출력

	cout.unsetf(std::ios::dec); // 10진수 모드를 끄고
	cout.setf(std::ios::hex); // 16진수 모드를 킨다
	cout << 108 << endl;
	
	// basefield: 여러 플래그 중 basefield의 플래그를 설정해 주겠다는 뜻
	cout.setf(std::ios::hex, std::ios::basefield);
	cout << 108 << endl;

	cout << std::hex << 108 << endl; // 16진수로 출력
	cout << std::dec << 110 << endl; // 10진수로 출력

	cout.setf(std::ios::uppercase);
	cout << std::hex << 108 << endl; // 16진수로 출력
	cout << std::dec << 110 << endl; // 10진수로 출력
	cout.unsetf(std::ios::uppercase);
	cout << endl;

	cout << true << ", " << false << endl;
	cout << std::boolalpha << true << ", " << false << endl;
	cout << endl;

	//cout << std::defaultfloat;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::fixed; // 소수점 뒤에 자리 고정시키기
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::scientific;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::scientific << std::uppercase;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::showpoint;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << -12345 << endl;
	////cout.fill('*'); // 빈칸을 *로 채워라
	cout << std::setw(10) << -12345 << endl; // 10자리를 채워서 출력하라
	cout << std::setw(10) << std::left << -12345 << endl; // 10자리를 채워서 출력하라
	cout << std::setw(10) << std::right << -12345 << endl; // 10자리를 채워서 출력하라 // 왼쪽으로 붙여서
	cout << std::setw(10) << std::internal << -12345 << endl; // 10자리를 채워서 출력하라 // 부호와 숫자 사이에 빈칸


	// 이 외에도 여러개의 플래그가 있음
	// 그 때, 그 때, 찾아서 사용하자.

	return 0;
}