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
	void speak() const { cout << m_name << " ???" << endl; }
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
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak(); // my cat Meow
	dog.speak(); // my dog Woof

	// 자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?
	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak(); // my cat ???
	ptr_animal2->speak(); // my dog ???

	// for 문을 사용하기
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4") };
	Dog dogs[] = { Dog("Dog1"), Dog("Dog2"), Dog("Dog3"), Dog("Dog4"), Dog("Dog5") };

	for (int i = 0; i < 4; ++i)
		cats[i].speak();

	for (int i = 0; i < 5; ++i)
		dogs[i].speak();

	// 그런데 이때, 고양이 개 고릴라 골룸 돼지 새 등등 동물이 엄청나게 많다면
	// 각 클래스 별로 for 문을 돌려야 하나?

	// 부모의 클래스로 묶어버릴 수 있는데 이때 문제는, Meow나 Woof가 아니라 ???이 출력된다
	// 마치 부모 클래스인 것 처럼 작동한다.

	// 이럴 경우 Animal 클래스의 speak 함수에 virtual을 붙여서 해결한다! [다형성]
	Animal* my_animals[] =
	{
		&cats[0],&cats[1],&cats[2],&cats[3],
		&dogs[0],&dogs[1],&dogs[2],&dogs[3],&dogs[4],
		// ...
	};

	for (auto element : my_animals)
		element->speak();
} 
