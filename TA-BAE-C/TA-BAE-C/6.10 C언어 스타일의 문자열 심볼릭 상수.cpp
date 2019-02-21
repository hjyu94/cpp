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
	// 문자열이 같으면 같은 주소가 출력됨

	char c = 'Q';
	cout << &c << endl; // Qㅁㅁㅁㅁㅁㅁㅁㅁ // null 까지 출력
	cout << *&c << endl; // Q
	
	// cout에서 문자열의 주소가 들어오면 주소가 아니라 문자열이 출력된다!!
	// cout에서 단일 문자의 주소가 들어올 때도 주소가 아니라 문자열이 출력된다.
}