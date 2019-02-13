#include <iostream>

using namespace std;

struct Employee // 14? 16? // 패딩 때문에 16
{
	short	id;		// 2 bytes
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};

int main()
{
	Employee emp1;

	cout << sizeof(Employee) << endl;	// 16
	cout << sizeof(emp1) << endl;		// 16

}
