//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	int n;
//	cin >> s >> n;
//	for (int cnt = 1; cnt < n; ++cnt)
//	{
//		string str = "";
//		int k;
//		for (int i = 0; i < s.length(); i=k)//计算各个字母出现的个数, i=k,从不重复的字母开始
//		{
//			for (k = i; k < s.length() && s[k] == s[i]; ++k);//计算相同的字母个数
//			str += s[i] + to_string(k - i);//将计算的该字母和其相同的次数算入
//		}
//		s = str;
//	}
//	cout << s;
//	return 0;
//}