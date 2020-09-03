//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n, m, k, a, b;
//	cin >> n >> m;
//	unordered_map<int, vector<int>>thePair;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a >> b;
//		thePair[a].push_back(b);
//		thePair[b].push_back(a);
//	}
//	while (m--)
//	{
//		cin >> k;
//		vector<int>temp(k);
//		unordered_map<int, bool>nums;
//		bool flag = true;
//		for (int i = 0; i < k; ++i)
//		{
//			cin >>temp[i];
//			nums[temp[i]] = true;
//		}
//		for (int i = 0; i < k && flag; ++i)
//			for (auto a : thePair[temp[i]])
//				if (nums[a] == true)
//					flag = false;
//		cout << (flag ? "Yes" : "No") << endl;
//	}
//	return 0;
//}
//
