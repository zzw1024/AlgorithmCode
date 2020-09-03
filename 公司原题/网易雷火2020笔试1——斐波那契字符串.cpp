//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	string s1, s2;
//	cin >> n >> s1 >> s2;
//	vector<int>res(26, 0), v1(26, 0), v2(26, 0);
//	for (int i = 0; i < s1.length(); ++i)
//		++v1[s1[i] - 'a'];
//	for (int i = 0; i < s2.length(); ++i)
//		++v2[s2[i] - 'a'];
//
//	if (n == 1)
//		res = v1;
//	else if (n == 2)
//		res = v2;
//	else
//	{
//		for (int i = 0; i < n - 2; ++i)
//		{
//			for (int j = 0; j < 26; ++j)
//				res[j] = v1[j] + v2[j];
//			v1 = v2;
//			v2 = res;
//		}
//	}
//	for(int i=0;i<26;++i)
//	{
//		if (res[i] > 0)
//			printf("%c:%d\n", 'a' + i, res[i]);
//	}
//	return 0;
//}
