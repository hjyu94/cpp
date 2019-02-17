namespace Constants
{
	// 다른 cpp 파일에서도 변수를 쓰거라
	extern const double pi(3.141592);
	extern const double gravity(9.8);

	// ...
}

// cpp 파일에서 초기화를 해준다.
// 값을 넣어주면 비로소 메모리를 차지하게 된다.