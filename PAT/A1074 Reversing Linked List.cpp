//////s首先说明一下PAT的常见陷阱，就是给出的数据未必是一条链表，可能是多条，
//////所以首先从输入的数据的中找到那条链表
//////巨简单，使用vector反转就行了
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int head, N, K;
////int nodes[100100], nexts[100100];
////vector<int>list;
////int main()
////{
////	cin >> head >> N >> K;
////	int adrr, data, next, temp = head;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> adrr >> data >> next;
////		nodes[adrr] = data;
////		nexts[adrr] = next;
////	}
////	while (temp != -1)//找出这条链表
////	{
////		list.push_back(temp);
////		temp = nexts[temp];
////	}
////	for (int i = K; i <= list.size(); i += K)
////		reverse(list.begin() + i - K, list.begin() + i);
////	for (int i = 0; i < list.size(); ++i)
////	{
////		printf("%05d %d ", list[i], nodes[list[i]]);
////		if (i < list.size() - 1)
////			printf("%05d\n", list[i+1]);
////		else
////			printf("-1\n");
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int addr, num, next;
//};
//int main()
//{
//	int head, n, k;
//	cin >> head >> n >> k;
//	vector<Node>v(1000100), res;
//	while (n--)
//	{
//		int addr, num, next;
//		cin >> addr >> num >> next;
//		v[addr] = { addr,num,next };
//	}
//	if (head == -1)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	while (head != -1)
//	{
//		res.push_back(v[head]);
//		head = v[head].next;
//	}
//	for (int i = 0; i + k <= res.size(); i += k)
//		reverse(res.begin() + i, res.begin() + i + k);
//	for (int i = 0; i < res.size() - 1; ++i)
//		printf("%05d %d %05d\n", res[i].addr, res[i].num, res[i + 1].addr);
//	printf("%05d %d -1\n", res[res.size() - 1].addr, res[res.size() - 1].num);
//	return 0;
//}
//
