////方法一：
////使用查并集来求解
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <unordered_map>
//using namespace std;
//vector<int>father, w;
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
//int n, k;
//struct  Node
//{
//	int num = 0, wight = 0, head = -1;
//};
//int main()
//{
//	cin >> n >> k;
//	w.resize(2 * n + 1);
//	father.resize(2 * n + 1);
//	for (int i = 0; i < father.size(); ++i)
//		father[i] = i;
//	unordered_map<string, int>sTi;
//	unordered_map<int, string>iTs;
//	for (int i = 0; i < n; ++i)
//	{
//		string a, b;
//		int t;
//		cin >> a >> b >> t;
//		if (sTi.find(a) == sTi.end())
//			sTi[a] = sTi.size() + 1;
//		if (sTi.find(b) == sTi.end())
//			sTi[b] = sTi.size() + 1;
//		w[sTi[a]] += t;
//		w[sTi[b]] += t;
//		iTs[sTi[a]] = a;
//		iTs[sTi[b]] = b;
//		Union(sTi[a], sTi[b]);
//	}
//	int num = sTi.size();
//	vector<Node>res(num + 1);
//	map<string, int>heads;
//	for (int i = 1; i <= num; ++i)
//	{
//		int temp = findFather(father[i]);
//		res[temp].num++;
//		res[temp].wight += w[i];
//		if (res[temp].head == -1)
//			res[temp].head = i;
//		else if (w[i] > w[res[temp].head])
//			res[temp].head = i;
//	}
//	for (int i = 0; i < res.size(); ++i)
//	{
//		if (res[i].num > 2 && res[i].wight > 2 * k)
//			heads[iTs[res[i].head]] = res[i].num;
//	}
//	cout << heads.size() << endl;
//	for (auto ptr = heads.begin(); ptr != heads.end(); ++ptr)
//		cout << ptr->first << " " << ptr->second << endl;
//	return 0;
//}