// 영역 제한 열거형, 열거형 클래스

#include <iostream>

using namespace std;

int main_4_8__1()
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
		cout << "How can color be the same as fruit?" << endl;

	return 0;
}

int main_4_8__2()
{
	enum class Color // not enum, it is enum 'class'
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

	/*
		// Comparision is not possible
		// If you want to compare two enum, you may use static_cast
	
		if (color == fruit)
			cout << "How can color be the same as fruit?" << endl;
	*/

	return 0;
}

