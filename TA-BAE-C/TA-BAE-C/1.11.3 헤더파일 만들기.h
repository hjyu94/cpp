#pragma once

/* extern */ int add(int x, int y);
// 다른 cpp 파일에 있는 함수를 쓰겠다는 선언
// 링커가 add 함수를 찾아보게끔 만든다.

// [제일 좋은 방식]
// 헤더 파일에는 선언만 해주고
// cpp 파일에 정의를 분리한다.
