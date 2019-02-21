// 부모 클래스의 포인터인데 자식클래스의 함수를 찾아가서 잘 수행해준다.
// 이러한 성질을 다형성이라고 부른다.

#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}
	virtual void speak() const { cout << m_name << " ???" << endl; }
};

/************************************************************************/

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}
	void speak() const { cout << m_name << " Woof" << endl; }
};


class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}
	void speak() const { cout << m_name << " Meow" << endl; }
};

/************************************************************************/

void main()
{
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4") };
	Dog dogs[] = { Dog("Dog1"), Dog("Dog2"), Dog("Dog3"), Dog("Dog4"), Dog("Dog5") };

	/*
	for (int i = 0; i < 4; ++i)
		cats[i].speak();

	for (int i = 0; i < 5; ++i)
		dogs[i].speak();
	*/
	
	Animal* my_animals[] =
	{
		&cats[0],&cats[1],&cats[2],&cats[3],
		&dogs[0],&dogs[1],&dogs[2],&dogs[3],&dogs[4],
		// ...
	};

	for (auto element : my_animals)
		element->speak();
}
