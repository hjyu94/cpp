#include <iostream>
#include <tuple>

using namespace std;

std::tuple<int, double> getTuple()
{
	int a = 10;
	float d = 3.14f;
	return std::make_tuple(a, d);
}

int main()
{
	std::tuple<int, double> my_tp = getTuple();
	std::get<0>(my_tp); // a
	std::get<1>(my_tp); // d
}