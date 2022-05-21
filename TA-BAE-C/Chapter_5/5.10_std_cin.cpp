#include <iostream>

int main_5_10()
{
	std::cin.ignore(32767, '\n'); // flush buffer
	std::cin.fail(); // return boolean
	std::cin.clear();

	return 0;
}