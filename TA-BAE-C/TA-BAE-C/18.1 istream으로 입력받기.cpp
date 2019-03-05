#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	char buf[5];

	cin >> setw(5) >> buf;
	cout << buf << endl;

	cin >> setw(5) >> buf;
	cout << buf << endl;

	cin >> setw(5) >> buf;
	cout << buf << endl;
}