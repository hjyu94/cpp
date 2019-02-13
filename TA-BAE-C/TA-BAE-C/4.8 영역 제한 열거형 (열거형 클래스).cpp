// 영역 제한 열거형

#include <iostream>
using namespace std;

int main()
{
	enum Color
	{
		RED,
		BLUE,
	};

	enum Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = RED;
	Fruit fruit = BANANA;

	if (color == fruit)
		cout << "color is fruit ?" << endl;
}

/******************************************************/

#include <iostream>
using namespace std;

int main()
{
	enum class Color
	{
		RED,
		BLUE,
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = Color::RED;
	Fruit fruit = Fruit::BANANA;

	if (color == fruit)
		cout << "color is fruit ?" << endl;
}