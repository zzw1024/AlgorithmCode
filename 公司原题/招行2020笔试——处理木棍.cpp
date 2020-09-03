//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void DFS(vector<int>&len, vector<int>&wight, int index, int& res, const int n)
//{
//	if (index == n)
//	{
//		int temp = 1;
//		for (int i = 1; i < n; ++i)
//			if (!(len[i] >= len[i - 1] && wight[i] >= wight[i - 1]))
//				++temp;
//		res = res < temp ? res : temp;
//		return;
//	}
//	for (int i = index; i < n; ++i)
//	{
//		if (!(len[i] == wight[index] && wight[i] == wight[index]))
//		{
//			swap(len[i], len[index]);
//			swap(wight[i], wight[index]);
//			DFS(len, wight, index + 1, res, n);
//			swap(len[i], len[index]);
//			swap(wight[i], wight[index]);
//		}
//	}
//}
//
//struct Stick
//{
//	int L, W, cost = 1;//每根木棍单独处理消耗1
//};
//
//int main()
//{
//	int T, n;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n;
//		vector<Stick>v(n);
//		for (int i = 0; i < n; ++i)
//			cin >> v[i].L;
//		for (int i = 0; i < n; ++i)
//			cin >> v[i].W;
//
//
//		sort(v.begin(), v.end(), [](pair<int, int>p1, pair<int, int>p2) {
//			if (p1.first == p2.first)return p1.second < p2.second;
//			else return p1.first < p2.first; }) ;
//		
//		int res = 0, sum = 0, L, W;
//		while (sum < n)
//		{
//			L = W = 0;
//			for (int i = 0; i < n; ++i)
//			{
//				if (v[i].cost == 1 && v[i].L >= L && v[i].W >= W)
//				{
//					v[i].cost = 0;//不需要花销
//					L = v[i].L;
//					W = v[i].W;
//					++sum;
//				}
//			}
//			++res;//轮询一组，找到了一组花销最小的排序，即无花销，然后继续再在下一组cost=1中进行轮询
//		}
//		cout << res << endl;
//	}
//	return 0;
//}
//
