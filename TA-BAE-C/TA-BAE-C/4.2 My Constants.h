#pragma once

namespace Constants
{
	extern const double pi;
	extern const double gravity;
	// ...
}
// 헤더에는 선언만 해두는 것이 좋다.
// 정의까지 되어 있다면, 여러개의 파일에서 헤더를 인클루드 할 때마다
// 변수가 복사되기 때문이다.(주소를 찍어봐도 다르게 출력된다.)
