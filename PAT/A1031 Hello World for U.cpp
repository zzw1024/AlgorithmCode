////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	string str, s;
////	cin >> str;
////	int m = (str.length() + 2) / 3;
////	s.assign(str.length() - 2 * m, ' ');
////	for(int i=0;i<m-1;++i)
////		cout << str[i] << s << str[str.length() - i - 1] << endl;
////	s.assign(str.begin() + m - 1, str.end() - m + 1);
////	cout << s << endl;
////	return 0;	
////}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string str1, str2, str3, str;
//	int n1, n2, n3, k;
//	cin >> str;
//	n1 = n3 = (str.length() + 2) / 3 - 1;
//	n2 = str.length() - n1 - n3;
//	str1.assign(str.begin(), str.begin() + n1);
//	str2.assign(str.begin() + n1, str.begin() + n1 + n2);
//	str3.assign(str.begin() + n1 + n2, str.end());
//	reverse(str3.begin(), str3.end());
//	str.assign(n2 - 2, ' ');
//	for (int i = 0; i < n1; ++i)
//	{
//		cout << str1[i] << str << str3[i] << endl;
//	}
//	cout << str2 << endl;
//	return 0;
//	
//
//}

