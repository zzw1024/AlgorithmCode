////#include <iostream>
////#include <string>
////#include <algorithm>
////
////using namespace std;
////string str, t1, t2;
////int res = 1;
//////最普通的遍历
////void way1()
////{
////	for (int i = 0; i < str.length(); ++i)
////	{
////		for (int j = str.length() - 1; j > i; --j)
////		{
////			t1.assign(str.begin() + i, str.begin() + j + 1);
////			t2.assign(t1.rbegin(), t1.rend());
////			if (t1 == t2)
////				res = res > t1.length() ? res : t1.length();
////		}
////	}
////}
////
//////利用回文子串中心的两边相同
////void way2()
////{
////	for (int i = 0; i < str.size(); ++i) {
////		int j;
////		for (j = 1; i - j >= 0 && i + j < str.size() && str[i + j] == str[i - j]; ++j);//以当前字符为回文中心查找最长回文子串
////		res= max(res, 2 * j - 1);//更新回文子串最大长度
////		for (j = 0; i - j >= 0 && i + j + 1 < str.size() && str[i - j] == str[i + 1 + j]; ++j);//以当前字符为回文中心左侧字符查找最长回文子串
////		res = max(res, 2 * j);//更新回文子串最大长度
////	}
////}
////
//////使用动态规划
////void way3()
////{
////	int dp[1010][1010];
////	for (int i = 0; i < str.length(); i++)
////	{
////		dp[i][i] = 1;
////		if (i < str.length() - 1 && str[i] == str[i + 1])
////		{
////			dp[i][i + 1] = 1;
////			res = 2;
////		}
////	}
////	for (int L = 3; L <= str.length(); L++)
////	{
////		for (int i = 0; i + L - 1 < str.length(); i++) //长度的跨度为L
////		{
////			int j = i + L - 1;
////			if (str[i] == str[j] && dp[i + 1][j - 1] == 1) 
////			{
////				dp[i][j] = 1;
////				res = L;
////			}
////		}
////	}
////}
////
////int main()
////{
////	getline(cin, str);
////	way1();
////	cout << res << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int res = 1;
//	for (int i = 0; i < str.length(); ++i)
//	{
//		int j;
//		for (j = 1; (i - j) >= 0 && (i + j) < str.length() && str[i - j] == str[i + j]; ++j);//中心回文
//		res = res > (j - 1) * 2 + 1 ? res : (j - 1) * 2 + 1;
//		for (j = 0; (i - j) >= 0 && (i + j + 1) < str.length() && str[i - j] == str[i + j + 1]; ++j);//双回文
//		res = res > j * 2 ? res : j * 2;
//	}
//	cout << res << endl;
//	return 0;
//}
