////#include <iostream>
////#include <string>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int N;
////int main()
////{
////	cin >> N;
////	string res = "", str;
////	vector<string>v;
////	int minL = 300;
////	getchar();
////	for (int i = 0; i < N; ++i)
////	{
////		getline(cin, str);		
////		reverse(str.begin(), str.end());
////		v.push_back(str);		
////		minL = minL < str.length() ? minL : str.length();
////	}
////	bool flag = true;
////	for (int i = 0; i < minL && flag; ++i)
////	{		
////		for (int j = 1; j < N && flag; ++j)
////		{
////			if (v[0][i] != v[j][i])
////				flag = false;
////		}
////		if (flag)
////			res += v[0][i];
////	}
////	reverse(res.begin(), res.end());
////	if (res.length() == 0)
////		cout << "nai" << endl;
////	else
////		cout << res << endl;
////
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	string res = "";
//	vector<string>v(n);
//	getchar();
//	for (int i = 0; i < n; ++i)
//		getline(cin, v[i]);
//	bool flag = true;
//	for (int i = 1; i <= v[0].length(); ++i)
//	{
//		char c = v[0][v[0].length() - i];
//		for (int j = 1; j < n && i <= v[j].length(); ++j)
//		{
//			if (v[j][v[j].length() - i] != c)
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//			res += c;
//		else
//			break;
//	}
//	if (res == "")
//		cout << "nai";
//	else
//		for (int i = res.length() - 1; i >= 0; --i)
//			cout << res[i];
//	return 0;
//}