////#include <iostream>
////#include <vector>
////#include <set>
////#include <algorithm>
////#include <cmath>
////using namespace std;
////struct Node
////{
////	int ID, nums = 0;
////	double ss = 0.0, aa = 0.0;
////};
////int n;
////double num[10000] = { 0.0 }, area[10000] = { 0.0 };//房子数量//房子面积
////int mark[10000];//标记属于哪个家族
////vector<set<int>>sets(10000);//记录每个家庭有多少人
////vector<Node*>res;
////void combin(int my, int other)//合并家族
////{
////	for (auto ptr = sets[other].begin(); ptr != sets[other].end(); ++ptr)//将其他成员进行同化
////	{
////		mark[*ptr] = my;
////		sets[my].insert(*ptr);
////	}
////	sets[other].clear();//删除其他成员的标记
////}
////int main()
////{	
////	cin >> n;	
////	fill(mark, mark + 10000, -1);
////	for (int i = 0; i < n; ++i)
////	{
////		int my, parent, k, child, nn, aa;
////		cin >> my;
////		if (mark[my] == -1)//还未标记是哪个家族
////		{
////			mark[my] = my;//就以自己为标记
////			sets[mark[my]].insert(my);
////		}
////		for (int i = 0; i < 2; ++i)//添加父母
////		{
////			cin >> parent;
////			if (parent == -1)
////				continue;
////			if (mark[parent] == -1)//家人未标记
////			{
////				mark[parent] = mark[my];
////				sets[mark[my]].insert(parent);
////			}
////			else if (mark[parent] != -1 && mark[parent] != mark[my])//家人与自己标记不同
////				combin(mark[my], mark[parent]);//将家人同化为自己标记
////		}
////		cin >> k;
////		while (k--)
////		{
////			cin >> child;
////			if (mark[child] == -1)//孩子未标记
////			{
////				mark[child] = mark[my];
////				sets[mark[my]].insert(child);
////			}
////			else if (mark[child] != -1 && mark[child] != mark[my])//孩子与自己标记不同
////				combin(mark[my], mark[child]);//将孩子同化为自己标记
////		}
////		cin >> nn >> aa;
////		num[my] = nn;
////		area[my] = aa;
////	}
////	for (int i = 0; i < sets.size(); ++i)
////	{
////		if (sets[i].empty())
////			continue;
////		Node* temp = new Node;
////		temp->ID = *sets[i].begin();
////		temp->nums = sets[i].size();
////		for (auto ptr = sets[i].begin(); ptr != sets[i].end(); ++ptr)
////		{
////			temp->aa += area[*ptr];
////			temp->ss += num[*ptr];
////		}
////		temp->ss /= temp->nums;
////		temp->aa /= temp->nums;
////		res.push_back(temp);
////	}
////	sort(res.begin(), res.end(), [](Node*a, Node*b) {
////		if (abs(a->aa - b->aa) < 0.0001)
////			return a->ID < b->ID;
////		else
////			return a->aa > b->aa; });
////	cout << res.size() << endl;
////	for (auto v : res)
////		//printf("%04d %d %0.3f %0.3f\n", v->ID, v->nums, v->ss, v->aa);
////	return 0;
////}
//
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	double sets, areas;
//};
//struct Ans
//{
//	int id, nums;
//	double AVGs, AVGa;
//};
//int n;
//int father[10010];
//bool isMember[10010] = { false };
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
//	isMember[a] = true;
//	isMember[b] = true;
//	int aF = findFather(a), bF = findFather(b);
//	if (aF != bF)
//		father[aF] = bF;
//}
//int main()
//{
//	cin >> n;
//	unordered_map<int, Node>family;
//	for (int i = 0; i < 10010; ++i)
//		father[i] = i;
//	for (int i = 0; i < n; ++i)
//	{
//		int id, fa, mo, k, child;
//		double sets, areas;
//		cin >> id >> fa >> mo >> k;
//		if (fa != -1)
//			Union(id, fa);
//		if (mo != -1)
//			Union(id, mo);
//		while (k--)
//		{
//			cin >> child;
//			Union(id, child);
//		}
//		cin >> sets >> areas;
//		family[id] = { sets,areas };
//		isMember[id] = true;
//	}
//	unordered_map<int, vector<int>>res;
//	for (int i = 0; i < 10010; ++i)
//			if (isMember[i])
//				res[findFather(i)].push_back(i);
//	cout << res.size() << endl;
//	vector<Ans>v;
//	for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//	{
//		double As = 0.0, Aa = 0.0;
//		sort(ptr->second.begin(), ptr->second.end());
//		for (int i = 0; i < ptr->second.size(); ++i)
//		{
//			if (family.find(ptr->second[i]) != family.end())
//			{
//				As += family[ptr->second[i]].sets;
//				Aa += family[ptr->second[i]].areas;
//			}
//		}
//		v.push_back({ ptr->second[0],(int)ptr->second.size(),As / ptr->second.size() ,Aa / ptr->second.size() });
//	}
//	sort(v.begin(), v.end(), [](Ans a, Ans b) {if (a.AVGa == b.AVGa)return a.id < b.id; else return a.AVGa > b.AVGa; });
//	for (auto a : v)
//		printf("%04d %d %.3f %.3f\n", a.id, a.nums, a.AVGs, a.AVGa);
//	return 0;
//}
//
