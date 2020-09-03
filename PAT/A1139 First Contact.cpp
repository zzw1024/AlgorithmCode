////#include <iostream>
////#include <vector>
////#include <string>
////#include <algorithm>
////using namespace std;
////vector<int>graph[10005];//图
////bool boy[10005];//下标为ID，元素表示该ID是否是男
////int N, M, K, vstart, vend;
////int main() 
////{
////	scanf("%d%d", &N, &M);
////	for (int i = 0; i < M; ++i) 
////	{//读取边的数据
////		string a, b;
////		cin >> a >> b;
////		int ia = abs(stoi(a)), ib = abs(stoi(b));//将字符串化为正整数
////		graph[ia].push_back(ib);//向图中加入边
////		graph[ib].push_back(ia);//向图中加入边
////		boy[ia] = (a[0] != '-');//表示该人性别
////		boy[ib] = (b[0] != '-');//表示该人性别
////	}
////	scanf("%d", &K);
////	while (K--)
////	{
////		scanf("%d%d", &vstart, &vend);//读取首尾结点
////		vector<pair<int, int>>result;//存储符合题目要求的两个结点
////		for (int i : graph[abs(vstart)])//遍历首节点的朋友
////			if (i != abs(vend) && i != abs(vstart) && boy[i] == boy[abs(vstart)])//找到非首尾结点且与首节点性别相同的朋友作为第一个节点
////				for (int j : graph[i])//遍历第一个节点的朋友
////					if (j != abs(vend) && j != abs(vstart) && boy[j] == boy[abs(vend)])//找到非首尾结点且与尾节点性别相同的朋友作为第二个节点
////						for (int k : graph[j])//遍历第二个节点的朋友
////							if (k == abs(vend))//尾结点是第二个节点的朋友
////								result.push_back({ i,j });//i,j两个节点符合要求
////		printf("%d\n", result.size());
////		sort(result.begin(), result.end());//排序
////		for (auto&i : result)//输出
////			printf("%04d %04d\n", i.first, i.second);
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int n, m;
//bool friends[10005][10005] = { false };
//bool isMan[10005] = { false };
//int main()
//{
//	cin >> n >> m;
//	int a, b, c, d;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> a >> b;
//		isMan[abs(a)] = a > 0;
//		isMan[abs(b)] = b > 0;
//		friends[abs(a)][abs(b)] = friends[abs(b)][abs(a)] = true;
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> a >> b;
//		vector<pair<int, int>>res;
//		for (c = 0; c < 10005; ++c)
//			if (c!=abs(b) && friends[abs(a)][c] && isMan[abs(a)] == isMan[c])//是朋友且同性
//				for (d = 0; d < 10005; ++d)
//					if (d!=abs(a) && friends[d][c] && friends[d][abs(b)] && isMan[abs(b)] == isMan[d])
//						res.push_back(make_pair(c, d));
//		sort(res.begin(), res.end(), [](pair<int, int>p1, pair<int, int>p2) {
//			if (p1.first == p2.first)return p1.second < p2.second;
//			else return p1.first < p2.first; });
//		cout << res.size() << endl;
//		for (auto v : res)
//			cout << v.first << " " << v.second << endl;
//	}
//	return 0;
//}
//
