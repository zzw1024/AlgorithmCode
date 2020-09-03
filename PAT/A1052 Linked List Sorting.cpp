////#include <iostream>
////#include <map>
////using namespace std;
//////注意点
//////（1）题目给出的结点中可能有不在链表中的无效结点
//////
//////（2）最后一个测试点测试的是首地址为 - 1，即为空链表的情况，此时只输出0 - 1
//////
//////（3）输出时结点地址除 - 1外要有5位数字，不够则在高位补0 。所以地址 - 1要进行特判输出
////int main()
////{
////	int N, head, maxV = -1000000;
////	cin >> N >> head;
////	map<int, int>value;
////	map<int, pair<int, int>>data;
////	for (int i = 0; i < N; ++i)
////	{
////		int addr, val, next;
////		cin >> addr >> val >> next;
////		data.insert(make_pair(addr, make_pair(val, next)));
////	}
////	if (data.find(head) == data.end())
////	{
////		cout << 0 << " " << -1 << endl;
////		return 0;//该链表为空
////	}
////	while (head != -1)//遍历一下数据，找到是链表中的数据
////	{
////		value.insert(make_pair(data[head].first, head));
////		head = data[head].second;
////	}
////	printf("%d %05d\n", value.size(), value.begin()->second);
////	for (auto ptr = value.begin(); ptr != value.end(); ++ptr)
////	{
////		if (ptr == value.begin())
////			printf("%05d %d ", ptr->second, ptr->first);
////		else
////			printf("%05d\n%05d %d ", ptr->second, ptr->second, ptr->first);
////	}
////	printf("%d\n", -1);
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, head, nexts[100010], keys[100010];
//	fill(nexts, nexts + 100010, -1);
//	fill(keys, keys + 100010, 0);
//	cin >> n >> head;
//	vector<pair<int, int>>v;
//	for (int i = 0; i < n; ++i)
//	{
//		int addr, key, next;
//		cin >> addr >> key >> next;
//		nexts[addr] = next;
//		keys[addr] = key;
//	}
//	while (head != -1)
//	{
//		v.push_back(make_pair(head, keys[head]));
//		head = nexts[head];
//	}
//	sort(v.begin(), v.end(), [](pair<int, int>a, pair<int, int>b) {return a.second < b.second; });
//	if (v.size() == 0)
//		cout << 0 << " " << -1 << endl;
//	else
//	{
//		printf("%d %05d\n%05d", v.size(), v[0].first, v[0].first);
//		for (int i = 1; i < v.size(); ++i)
//			printf(" %d %05d\n%05d", v[i - 1].second, v[i].first, v[i].first);
//		printf(" %d %d\n", v[v.size() - 1].second, -1);
//	}
//	return 0;
//}