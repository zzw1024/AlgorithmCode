////#include <iostream>
////#include <unordered_map>
////using namespace std;
//////原以为将各个节点给连在一起，然后找公共节点，后来才发现想多了
//////谁出现了两次，谁就是公共节点
//////但是，未通过测试，可能存在环形链表，故只能遍历的找两条链表的公共部分
////int main()
////{
////	int head1, head2, N, addr, next;
////	char c;
////	cin >> head1 >> head2 >> N;
////	unordered_map<int, pair<int, bool>>list;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> addr >> c >> next;
////		list[addr] = make_pair(next,false);
////	}
////	for (int i = head1; i != -1; i = list[i].first)
////		list[i].second = true;
////	for (int i = head2; i != -1; i = list[i].first)
////	{
////		if (list[i].second == true)
////		{
////			printf("%05d\n", i);
////			return 0;
////		}
////	}
////	printf("-1\n");
////	return 0;
////}
//
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int head1, head2, n, res = -1;
//	int nodes[100010], isSharing[100010];
//	fill(nodes, nodes + 100010, -1);
//	fill(isSharing, isSharing + 100010, -1);
//	cin >> head1 >> head2 >> n;
//	while (n--)
//	{
//		int a, b;
//		char c;
//		cin >> a >> c >> b;
//		nodes[a] = b;
//	}
//	int p = head1;
//	while (p != -1)
//	{
//		isSharing[p] = 1;
//		p = nodes[p];
//	}
//	p = head2;
//	while (p != -1)
//	{
//		if (isSharing[p] == 1)
//		{
//			res = p;
//			break;
//		}
//		p = nodes[p];
//	}
//	if (res == -1)
//		printf("%d\n", res);
//	else
//		printf("%05d\n", res);
//	return 0;
//}