////#include <iostream>
////#include <string>
////#include <vector>
////#include <algorithm>
////using namespace std;
//////排序问题
////int N;
////vector<string>v, temp;
////string res = "", str = "";
////void permuteDFS(int u,vector<bool>&visit)//使用DFS
////{
////	if (u == v.size())
////	{
////		for (auto a : temp)
////			str += a;
////		res = res > str ? str : res;
////		str = "";
////		return;
////	}
////	for (int i = 0; i < N; ++i)
////	{
////		if (visit[i] == true)continue;
////		visit[i] = true;
////		temp.push_back(v[i]);
////		permuteDFS(i + 1, visit);
////		temp.pop_back();
////		visit[i] = false;
////	}
////}
////
////void permutex(int u)//使用递归
////{
////	if (u == v.size())
////	{
////		for (auto a : v)
////			str += a;
////		res = res > str ? str : res;
////		str = "";
////	}
////	for (int i = u; i < N; ++i)
////	{
////		swap(v[i], v[u]);
////		permutex(i + 1);
////		swap(v[i], v[u]);
////	}
////}
////
////void Sort()//使用排序法则
////{
////	sort(v.begin(), v.end(), [](string a, string b) {return a + b < b + a; });
////	res = "";
////	for (auto a : v)
////		res += a;
////}
////
////int main()
////{
////	cin >> N;
////	v.resize(N);
////	vector<bool>visit(N, false);
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> v[i];
////		res += v[i];
////	}
////	//permutex(0);
////	//permuteDFS(0, visit);
////	Sort();
////	while (!res.empty() && res[0] == '0')
////		res.erase(0, 1);
////	if (res.size() == 0)cout << 0;
////	cout << res << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int n;
//int main()
//{
//	cin >> n;
//	vector<string>res(n);
//	for (int i = 0; i < n; ++i)
//		cin >> res[i];
//	sort(res.begin(), res.end(), [](string a, string b) {return (a + b) < (b + a); });
//	string str = "";
//	for (auto a : res)
//		str += a;
//	while (str.length() > 0 && str[0] == '0')
//		str.erase(0, 1);
//	if (str.length() == 0)
//		cout << 0 << endl;
//	else
//		cout << str << endl;
//	return 0;
//}
