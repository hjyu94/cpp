//#include <iostream>
//
//using namespace std;
//
//int main_5_3_2()
//{
//	int x;
//	cin >> x;
//
//	//** declaration in another case
//	
//	// what's happening if x is 1, Will an error occur?
//	switch (x)
//	{
//	case 0:
//		int y;
//		break;
//
//	case 1:
//		y = 5;
//		cout << y << endl; // 5
//		break;
//	}
//
//	switch (x)
//	{
//	case 0:
//		int y;
//		y = 5;
//		break;
//
//	case 1:
//		cout << y << endl; // garbage printed, without error
//		break;
//	}
//	
//
//	// Even though declaration is inside case
//	// It is totally equal to below
//	// But this way is not recommeneded.
//
//	switch (x)
//	{
//		int y; // <--- !!!
//	case 0:
//		y = 5;
//		break;
//	case 1:
//		cout << y << endl;
//		break;
//	}
//
//
//	// But if there is {}, there will be an error
//
//	switch (x)
//	{
//	case 0:
//	{
//		int y;
//		y = 5;
//		break;
//	}
//	case 1:
//	{
//		//cout << y << endl; // <-- error !
//		break;
//	}
//	}
//
//	return 0;
//}