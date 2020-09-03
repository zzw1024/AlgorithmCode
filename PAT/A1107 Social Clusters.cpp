////#include <iostream>
////#include <numeric>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int hobby[1005], father[1005];
////int findFather(int x) 
////{//查找父亲结点并进行路径压缩
////	if (x == father[x])
////		return x;
////	int temp = findFather(father[x]);
////	father[x] = temp;
////	return temp;
////}
////void unionSet(int a, int b) 
////{//合并两个集合
////	int ua = findFather(a), ub = findFather(b);
////	if (ua != ub)
////		father[ua] = ub;//这里是关键，即将此位置的father改为最近有共同爱好的人
////}
////int main() {
////	int n, m, a;
////	cin >> n;
////	for (int i = 0; i <= n; ++i)father[i] = i;//初始化
////	for (int i = 1; i <= n; ++i) 
////	{
////		scanf("%d:", &m);
////		while (m--) 
////		{
////			cin >> a;
////			if (hobby[a] == 0)//没有人有当前这个爱好
////				hobby[a] = i;//i作为第一个有该爱好的人
////			else//有人喜欢该爱好
////				unionSet(hobby[a], i);//将有同样爱好的两个人合并为一个集合
////		}
////	}
////	vector<int>result(n + 1, 0);//储存每个集合的人数
////	for (int i = 1; i < n + 1; ++i)
////		++result[findFather(i)];//向前寻找father
////	sort(result.begin(), result.end(), [](int a, int b) {return a > b; });
////	int cnt = 0;
////	for (auto t : result)
////		if (t != 0)
////			cnt++;
////	cout << cnt << endl;
////	for (int i = 0; i < cnt; ++i)//输出result前cnt个元素(result已经从大到小排序，输出的都是集合个数不为0的)
////		printf("%s%d", i > 0 ? " " : "", result[i]);
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, father[1010], hobby[1010] = { 0 }, resNum[1010] = { 0 };
//int findFather(int x)
//{
//	if (x == father[x])
//		return x;
//	int temp = findFather(father[x]);
//	father[x] = temp;
//	return temp;
//}
//void Union(int a, int b)
//{
//	int aF = findFather(a), bF = findFather(b);
//	if (aF != bF)
//		father[aF] = bF;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i <= n; ++i)
//		father[i] = i;
//	for (int i = 1; i <= n; ++i)
//	{
//		int k, a;
//		scanf("%d:", &k);
//		while (k--)
//		{
//			cin >> a;
//			if (hobby[a] == 0)
//				hobby[a] = i;
//			else
//				Union(hobby[a], i);
//		}
//	}
//	for (int i = 0; i <= n; ++i)
//		++resNum[findFather(i)];
//	vector<int>res;
//	for (int i = 1; i <= n; ++i)
//		if (resNum[i] > 0)
//			res.push_back(resNum[i]);
//	sort(res.begin(), res.end(), [](int a, int b) {return a > b; });
//	cout << res.size() << endl;
//	for (int i = 0; i < res.size(); ++i)
//		cout << (i == 0 ? "" : " ") << res[i];
//	return 0;
//}