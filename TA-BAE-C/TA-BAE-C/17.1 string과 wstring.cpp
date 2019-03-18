#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

using namespace std;

int main(void)
{
	// c-style string example
	{
		char* strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		cout << strHello << endl;
	}

	// basic_string<>, string, wstring
	{
		// basic_string의 서로 다른 instantiation
		typedef basic_string<char, char_traits<char>, allocator<char> >
			string;
		typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >
			wstring;

		std::string String;
		std::wstring Wstring;

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
		typedef unsigned short wchar_t;
#endif
		wchar_t wc;
		// char의 경우 데이터 사이즈가 작다.
		// wchar_t는 데이터 사이즈를 많이 사용하는 문자를 표현하기 위해 사용
		// wide character, unicode 표현에 사용한다
		// 특히 국제어를 표현할 때 사용한다.
	}

	// wstring example
	{
		const std::wstring texts[] =
		{
			L"안녕하세요", // Korean
			L"Ñá", //Spanish
			L"forêt intérêt",  //French
			L"Gesäß",  //German
			L"取消波蘇日奇諾",  //Chinesse
			L"日本人のビット",  //Japanese
			L"немного русский",  //Russian
			L"ένα κομμάτι της ελληνικής",  //Greek
			L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ",  //Punjabi
			L"کمی از ایران ", //Persian
			L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu
			L"Но какво, по дяволите, е това?", //Bulgarian
		};
		
		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale()); 
		// 그 locale을 wcout에서 사용하겠다.
		// wcout: wide console out

		for (size_t i = 0; i < 12; ++i)
			std::wcout << texts[i] << endl;
	}
}