////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	int ascll[200] = { 0 };
////	string str = "", S1, S2;
////	getline(cin, S1);
////	getline(cin, S2);//注意S2也可能有空格
////	cin >> S2;
////	for (int i = 0; i < S2.length(); ++i)
////		ascll[S2[i]] = -1;
////	for (int i = 0; i < S1.length(); ++i)
////		if (ascll[S1[i]] == 0)
////			cout << S1[i];
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	bool c[128] = { false };
//	string str, s, res = "";
//	getline(cin, str);
//	getline(cin, s);
//	for (int i = 0; i < s.length(); ++i)
//		c[s[i]] = true;
//	for (int i = 0; i < str.length(); ++i)
//		if (c[str[i]] == false)
//			res += str[i];
//	cout << res << endl;
//	return 0;
//}