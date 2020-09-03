//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//struct Node
//{
//	int x =0, y=0, w=0, h=0;
//	int LUx = 0, LUy = 0, LDx = 0, LDy = 0, RUx = 0, RUy = 0, RDx = 0, RDy = 0;
//	string name = "";
//	int depth = 1;
//};
//
//int textID = 0;
//unordered_map<string, int>mapN;
//
//bool cmp(Node a, Node b)
//{
//	int aID = 0, bID = 0;
//	if (a.name != "")
//		aID = mapN[a.name];
//	else
//		aID = textID;
//	if (b.name != "")
//		bID = mapN[b.name];
//	else
//		bID = textID;
//
//	if (a.depth == b.depth)
//		return aID < bID;
//	else
//		return a.depth < b.depth;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<Node>v(n);
//	for (int i = 0; i < n; ++i)
//	{
//		string str;
//		cin >> str;
//		if (str == "Image")
//			cin >> v[i].x >> v[i].y >> v[i].w >> v[i].h >> v[i].name;
//		else
//			cin >> v[i].x >> v[i].y >> v[i].w >> v[i].h;
//		//вСио╫г
//		v[i].LUx = v[i].x - v[i].w / 2;
//		v[i].LUy = v[i].y + v[i].h / 2;
//		//вСоб╫г
//		v[i].LDx = v[i].x - v[i].w / 2;
//		v[i].LDy = v[i].y - v[i].h / 2;
//		//срио╫г
//		v[i].RUx = v[i].x + v[i].w / 2;
//		v[i].RUy = v[i].y + v[i].h / 2;
//		//сроб╫г
//		v[i].RDx = v[i].x + v[i].w / 2;
//		v[i].RDy = v[i].y - v[i].h / 2;		
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		string str;
//		cin >> str;
//		cin >> mapN[str];
//	}
//	cin >> textID;
//	v[0].depth = 1;
//	for (int i = 1; i < n; ++i)
//	{
//		v[i].depth = 1;
//		for (int j = 0; j < i; ++j)
//		{
//			if ((v[i].LUx >= v[j].LUx &&v[i].LUx <= v[j].RUx && v[i].LUy >= v[j].LDy && v[i].LUy <= v[j].LUy) ||
//				(v[i].LDx >= v[j].LUx &&v[i].LDx <= v[j].RUx && v[i].LDy >= v[j].LDy && v[i].LDy <= v[j].LUy) ||
//				(v[i].RUx >= v[j].LUx &&v[i].RUx <= v[j].RUx && v[i].RUy >= v[j].LDy && v[i].RUy <= v[j].LUy) ||
//				(v[i].RDx >= v[j].LUx &&v[i].RDx <= v[j].RUx && v[i].RDy >= v[j].LDy && v[i].RDy <= v[j].LUy))
//			{
//				if (v[i].name == v[j].name && v[i].depth < v[j].depth)
//					v[i].depth = v[j].depth;
//				else if (v[i].depth < v[j].depth + 1)
//					v[i].depth = v[j].depth + 1;
//			}
//		}
//	}
//	//еепР
//	sort(v.begin(), v.end(), cmp);
//	int res = 1;
//	for (int i = 1; i < n; ++i)
//	{
//		if (!(v[i].depth == v[i - 1].depth && v[i].name == v[i - 1].name))
//			++res;
//	}
//	cout << res << endl;
//	return 0;
//}