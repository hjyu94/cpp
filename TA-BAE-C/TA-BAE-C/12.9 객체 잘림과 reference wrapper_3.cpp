#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }
	virtual void speak() const { cout << m_name << " ???" << endl; }
};

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name)
	{}

	virtual void speak() const override
	{
		cout << m_name << " Mooo" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	virtual void speak() const override
	{
		cout << m_name << " Meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	virtual void speak() const override
	{
		cout << m_name << " Woof" << endl;
	}
};

void main()
{
	Dog dog("Dog");
	Cow cow("Cow");
	Cat cat("Cat");

	/********************************************/

	vector<Animal> vec_ani;
	vec_ani.push_back(dog);
	vec_ani.push_back(cow);
	vec_ani.push_back(cat);

	for (auto& e : vec_ani)
		e.speak();
	// Animal vec_ele_0 = dog; // 객체 잘림
	// ...
	// auto& e = vec_ele_0;
	// e.speak();

	// 다형성 발현 안됨

	/********************************************/

	vector<reference_wrapper<Animal>> vec_ref_ani;
	// Animal 레퍼런스 변수들을 모아놓은 벡터가 된다.
	vec_ref_ani.push_back(dog);
	vec_ref_ani.push_back(cow);
	vec_ref_ani.push_back(cat);

	for (auto& e : vec_ref_ani)
		e.get().speak();

	// reference_wrapper<Animal> vec_ele_0 = dog; 	
	// ...
	// auto& e = vec_ele_0;
	// Animal& r_ani = e.get()
	// r_ani.speak();

}