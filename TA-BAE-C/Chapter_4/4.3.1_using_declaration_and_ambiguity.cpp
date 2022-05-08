#include <iostream>

int main_4_3_1()
{
	// (1)
	// using namespace std;
	
	// (2)
	using std::cout; // using namespace std::cout (X)
	using std::endl;

	cout << "Hello" << endl;

	return 0;
}