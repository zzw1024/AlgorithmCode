////#include <iostream>
////#include <string>
////#include <vector>
////#include <map>
////#include <algorithm>
////using namespace std;
////int N, K, m, n;
////int main()
////{
////	cin >> N >> K;
////	map<string, vector<int>>student;
////	string name;
////	for (int i = 0; i < K; ++i)
////	{
////		cin >> m >> n;		
////		for (int j = 0; j < n; ++j)
////		{
////			cin >> name;
////			student[name].push_back(m);
////		}
////	}
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> name;
////		sort(student[name].begin(), student[name].end(), [](int a, int b) {return a < b; });
////		cout << name << " " << student[name].size();
////		for (auto a : student[name])
////			cout << " " << a;
////		cout << endl;
////	}
////	return 0;
////}
//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	unordered_map<string, vector<int>>map;
//	for (int i = 1; i <= k; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		while (b--)
//		{
//			string name;
//			cin >> name;
//			map[name].push_back(a);
//		}
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		string name;
//		cin >> name;
//		vector<int>temp = map[name];
//		sort(temp.begin(), temp.end(), [](int a, int b) {return a < b; });
//		cout << name << " " << temp.size();
//		for (auto v : temp)
//			cout << " " << v;
//		cout << endl;
//	}
//	return 0;
//}