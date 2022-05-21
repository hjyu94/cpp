#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>
#include <random> // since C++11

using namespace std;

unsigned int PRNG()
{
	static unsigned int seed = 5523; // only once initialized, so this is static variable
	seed = 8253729 * seed + 2396403; // get unexpected number with overflow
	return seed % 32768;
}

int getRandomNumber(int min, int max)
{
	// divide operation is slow, so store the return value, use repeatedly
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main_5_9()
{
	// (1) Pseudo Random Number Generator
	/*for (int count = 1; count <= 100; ++count)
	{
		cout << PRNG() << "\t";
		if (count % 5 == 0) cout << endl;
	}*/


	// (2) When below code is executed repeatedly,
	// random numbers are the same.
	// But in case you debug, fixing seed number is more easy to debug.
	/*std::srand(5323);
	for (int count = 1; count <= 100; ++count)
	{
		cout << std::rand() << "\t";
		if (count % 5 == 0) cout << endl;
	}*/


	// (3) So to get random numbers,
	// you often set seed number to time value.
	/*std::srand(static_cast<unsigned int>(std::time(0)));
	for (int count = 1; count <= 100; ++count)
	{
		cout << std::rand() << "\t";
		if (count % 5 == 0) cout << endl;
	}*/


	// (4) if you want to get random number between min and max
	// use below code.
	/*for (int count = 1; count <= 100; ++count)
	{
		cout << getRandomNumber(5, 8) << "\t";
		if (count % 5 == 0) cout << endl;
	}*/

	// (5) This way is less precise.
	/*for (int count = 1; count <= 100; ++count)
	{
		cout << rand() % 4 + 5 << "\t";
		if (count % 5 == 0) cout << endl;
	}*/

	// (6) This way is more precise statistically.
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> dice(1, 6);

	for (int count = 1; count <= 20; ++count)
		cout << dice(mersenne) << endl;

	return 0;
}