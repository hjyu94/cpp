#include <iostream>
#include <vector>

using namespace std;

void main1()
{
	typedef float distance_t;

	double		my_distance;
	distance_t	home2work;
	distance_t	home2school;

	// 이때 
	// typedef float distance_t; 를
	// typedef double distance_t; 로 바꿔주면
	// 순식간에 모든 distance_t가 double이 되므로
	// 코드의 유지보수가 간편해진다.
}

int main()
{
	vector<pair<string, int>> pairlist1;
	// 타이핑 귀찮고 보기도 불편함
	// 밑으로 바꾸면 좀 펀해짐

	// 둘 다 같음
	typedef vector<pair<string, int>> pairlist_t;
	using pairlist_t = vector<pair<string, int>>;
	// assignment를 하는 것 같아 보이지만
	// 차이점은 원래 assignment는 메모리를 차지하지만
	// 위는 메모리를 차지하지 않고 컴파일러에게 pairlist_t가 어떤 타입인지 알려줄 뿐

	pairlist_t pairlist_1;
	pairlist_t pairlist_2;
}