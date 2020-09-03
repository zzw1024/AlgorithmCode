////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	int n, num, a, b;
////	cin >> n;
////	while (n--)
////	{
////		string str, str1, str2;
////		cin >> str;
////		str1.assign(str.begin(), str.begin() + str.length() / 2);
////		str2.assign(str.begin() + str.length() / 2, str.end());
////		num = atoi(str.c_str());
////		a = atoi(str1.c_str());
////		b = atoi(str2.c_str());
////		if ((a*b) > 0 && num % (a*b) == 0)
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////	
////}
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n, n1, n2;
//	string s, s1, s2;
//	cin >> n;
//	while (n--)
//	{
//		cin >> s;
//		s1.assign(s.begin(), s.begin() + s.length() / 2);
//		s2.assign(s.begin() + s.length() / 2, s.end());
//		n1 = atoi(s1.c_str());
//		n2 = atoi(s2.c_str());
//		if ((n1*n2)>0 && atoi(s.c_str()) % (n1*n2) == 0)//n1*n2会溢出
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}