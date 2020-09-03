////#include <iostream>
////#include <string>
////#include <algorithm>
////using namespace std;
////int main()
////{
////	int A, B, preAns = -1, Ans = 0, flag = 0;
////	string Na, Nb;
////	cin >> Ans;	
////	while (preAns != Ans)
////	{
////		preAns = Ans;
////		Na = to_string(Ans);
////		while (Na.length() < 4)
////			Na += "0";
////		sort(Na.begin(), Na.end(), [](char a, char b) {return a > b; });
////		A = stoi(Na.c_str());
////		sort(Na.begin(), Na.end(), [](char a, char b) {return a < b; });
////		B = stoi(Na.c_str());
////		Ans = A - B;
////		if (flag == 1 && preAns == Ans)
////			break;
////		printf("%04d - %04d = %04d\n", A, B, Ans);
////		flag = 1;//怎么都得有一行输出
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, a, b;
//	cin >> n;
//	do
//	{
//		string s = to_string(n);
//		while (s.length() < 4)s += '0';
//		sort(s.begin(), s.end(), [](char a, char b) {return a > b; });
//		a = atoi(s.c_str());
//		sort(s.begin(), s.end(), [](char a, char b) {return a < b; });
//		b = atoi(s.c_str());
//		n = a - b;
//		printf("%04d - %04d = %04d\n", a, b, n);		
//	} while (n != 0 && n != 6174);
//	return 0;
//}