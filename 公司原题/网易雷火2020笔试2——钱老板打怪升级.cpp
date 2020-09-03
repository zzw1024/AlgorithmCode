//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct value
//{
//	int Li, Ei;
//};
//
//int main()
//{
//	int n, T, res = 0;
//	cin >> n >> T;
//	vector<value>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].Li >> v[i].Ei;
//
//	sort(v.begin(), v.end(), [](value a, value b) {
//		if (a.Li == b.Li)return a.Ei > b.Ei;
//		else return a.Li < b.Li; });
//	for (int i = 0; i < n; ++i)
//	{
//		int eT = 0, tT = 0;
//		if (i==0 || (i > 0 && v[i].Li != v[i - 1].Li))
//		{
//			for (int j = i; j < n; ++j)
//			{
//				if (v[j].Li >= tT)
//				{
//					eT += v[j].Ei;
//					tT += T;
//				}
//			}
//		}
//		res = res > eT ? res : eT;
//	}
//	cout << res << endl;
//	return 0;
//}