#include <iostream>

using namespace std;

char* getName()
{
	return "Jack Jack";
}

int main()
{
	// char name[] = "Jack Jack";
	char * name = "Jack Jack";
	
	const char * name2 = "Jack Jack";
	name2 = "Another"; // O

	char * const name3 = "Jack Jack";
	name3 = "Another"; // X

	cout << (uintptr_t)name << name << endl;		// 14322480 Jack Jack
	cout << (uintptr_t)name2 << name2 << endl;		// 14322480 Jack Jack
	cout << (uintptr_t)getName() << getName() << endl; // 14322480 Jack Jack
	// 庚切伸戚 旭生檎 旭精 爽社亜 窒径喫

	char c = 'Q';
	cout << &c << endl; // Qけけけけけけけけ // null 猿走 窒径
	cout << *&c << endl; // Q
	
	// cout拭辞 庚切伸税 爽社亜 級嬢神檎 爽社亜 焼艦虞 庚切伸戚 窒径吉陥!!
	// cout拭辞 舘析 庚切税 爽社亜 級嬢臣 凶亀 爽社亜 焼艦虞 庚切伸戚 窒径吉陥.
}