#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Object
// 변수 + 함수

class Friend {
public: // access specifier (public, private, protected), struct의 기본값은 public
	string m_name;
	string address;
	int age;
	double height, weight;

	void print() {
		cout << m_name << " " << address << endl;
	}

};

//// fr. 를 계속 쓰는게 더러워보임. Friend 구조체 안에서 정의하면 된다.
//void print(const Friend &fr) {
//	cout << fr.name << " " << fr.address << endl;
//}

void print(const string &name, const string &address, const int &age,
	const double &height, const double &weight)
{
	cout << name << " " << address << endl;
}

int main() {
	Friend jj{ "a","b",1,2,3 }; // uniform initialization
	// 실제로 메모리를 차지하게 해주는 것. instanciation, instance
	// 실존하는지 아닌지의 여부는 메모리를 차지하고 있는지로 확인한다.

	jj.m_name = "Jack Jack";

	print(jj.m_name, jj.address, jj.age, jj.height, jj.weight); // member variables
	jj.print();

	vector<string> name_vec;
	vector<string> addr_vec;
	vector<int> age_vec;
	vector<double> height_vec;

	print(name_vec[0], addr_vec[0], 0, 0, 0); // ...

	vector<Friend> my_friends;
	my_friends.resize(2);
	my_friends[0].print();
	my_friends[1].print();

	// 천명이면 어떡해...?
	for (auto &ele : my_friends)
		ele.print();
}