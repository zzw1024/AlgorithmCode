////#include <iostream>
////#include <set>
////using namespace std;
////int main()
////{
////	int n, m, boy, girl, id;
////	int couple[100005], flag[100005];
////	set<int>guests, res;
////	cin >> n;
////	fill(couple, couple + 100005, -1);
////	fill(flag, flag + 100005, 0);
////	while (n--)
////	{
////		cin >> boy >> girl;
////		couple[boy] = girl;
////		couple[girl] = boy;
////	}
////	cin >> m;
////	while (m--)
////	{
////		cin >> id;
////		guests.insert(id);
////		if (couple[id] == -1)
////			continue;
////		else if (flag[id] == 0)//对偶没有来
////		{
////			flag[id] = 1;
////			flag[couple[id]] = 1;
////		}
////		else if (flag[id] == 1)//对偶来了
////		{
////			flag[id] = -1;
////			flag[couple[id]] = -1;
////		}
////	}
////	for (auto a : guests)
////	{
////		if (flag[a] != -1)
////			res.insert(a);
////	}
////	cout << res.size() << endl;
////	for (auto a : res)
////		printf("%s%05d", (a == *(res.begin()) ? "" : " "), a);
////	return 0;
////}
//#include <iostream>
//#include <set>
//using namespace std;
//int main()
//{
//	int n, a, b;
//	int friends[100010];
//	bool flag[100010] = { false };
//	cin >> n;
//	set<int>res;
//	fill(friends, friends + 100010, -1);
//	while (n--)
//	{
//		cin >> a >> b;
//		friends[a] = b;
//		friends[b] = a;
//	}
//	cin >> n;
//	while (n--)
//	{
//		cin >> a;
//		flag[a] = true;
//		if (friends[a]!=-1 && flag[friends[a]] == true)
//			res.erase(friends[a]);
//		else
//			res.insert(a);
//	}
//	cout << res.size() << endl;
//	for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//		printf("%s%05d", (ptr == res.begin() ? "" : " "), *ptr);
//	return 0;
//}