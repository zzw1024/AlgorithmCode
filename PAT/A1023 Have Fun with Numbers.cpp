////#include <iostream>
////#include <algorithm>
////#include <string>
////using namespace std;
//////会溢出，不能使用简单的加减
////
////int main()
////{
////	string a, b = "", res;
////	cin >> a;
////	int k = 0;
////	for (int i = a.length() - 1; i >= 0; --i)
////	{
////		k = k + (a[i] - '0') + (a[i] - '0');
////		b += k % 10 + '0';
////		k /= 10;
////	}
////	if (k > 0)
////		b += k + '0';
////	res.assign(b.rbegin(), b.rend());	
////	sort(a.begin(), a.end());
////	sort(b.begin(), b.end());
////	if (a == b)
////		cout << "Yes" << endl;
////	else
////		cout << "No" << endl;
////	for (auto c : res)
////		cout << c;
////	cout << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string s1, s2, s3;
//	cin >> s1;
//	s2 = s1;
//	int temp, index = 0;
//	for (int i = s1.length()-1; i >= 0; i--)
//	{
//		temp = s1[i] - '0' + s1[i] - '0' + index;
//		s2[i] = temp % 10 + '0';
//		index = temp / 10;
//	}
//	if (index > 0)
//		s2.insert(s2.begin(), index + '0');
//	s3 = s2;
//	sort(s1.begin(), s1.end());
//	sort(s2.begin(), s2.end());
//	if (index > 0 || s1 != s2)
//		cout << "No" << endl;
//	else
//		cout << "Yes" << endl;
//	cout << s3 << endl;
//	return 0;
//}