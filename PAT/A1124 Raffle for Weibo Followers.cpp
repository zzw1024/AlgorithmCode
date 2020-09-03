////#include <iostream>
////#include <unordered_map>
////#include <string>
////using namespace std;
////int m, k, s;
////int main()
////{
////	cin >> m >> k >> s;
////	unordered_map<string,int>res;
////	string str;
////	for (int i = 1; i <= m; ++i)
////	{
////		cin >> str;
////		if (i == s)
////		{
////			if (res[str] == 1)//输出过
////				s++;//后移动
////			else
////			{
////				cout << str << endl;
////				res[str] = 1;
////				s += k;
////			}
////		}
////	}
////	if (res.size() == 0)
////		cout << "Keep going..." << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n, k, m;
//	cin >> n >> k >> m;
//	vector<string>v(n+1);
//	unordered_map<string, int>map;
//	for (int i = 1; i <= n; ++i)
//		cin >> v[i];
//	for (int i = m; i <= n;)
//	{
//		if (map.find(v[i]) == map.end())
//		{
//			cout << v[i] << endl;
//			map[v[i]] = 1;
//			i += k;
//		}
//		else
//			i++;
//	}
//	if (map.size() == 0)
//		cout << "Keep going..." << endl;
//	return 0;
//}
