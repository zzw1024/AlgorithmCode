//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//struct Node
//{
//	int addr, val, next;
//}nodes[100010];
//int main()
//{
//	int head, head1, head2, n;
//	cin >> head1 >> head2 >> n;
//	vector<Node>v1, v2, res;//存储列表值
//	for (int i = 0; i < n; ++i)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		nodes[a] = { a,b,c };
//	}
//	for (int p = head1; p != -1; p = nodes[p].next)
//		v1.push_back(nodes[p]);
//	for (int p = head2; p != -1; p = nodes[p].next)
//		v2.push_back(nodes[p]);
//	if (v1.size() > v2.size())
//		head = head1;
//	else
//	{
//		v2 = v1;//v2是短边
//		head = head2;
//	}
//	int k = 0;
//	while (head != -1)
//	{
//		res.push_back(nodes[head]);
//		++k;
//		if (k % 2 == 0 && !v2.empty())//两个中间插一个
//		{
//			res.push_back(v2.back());
//			v2.pop_back();
//		}
//		head = nodes[head].next;
//	}
//	for (int i = 0; i < res.size() - 1; ++i)
//		printf("%05d %d %05d\n", res[i].addr, res[i].val, res[i+1].addr);
//	printf("%05d %d %d\n", res.back().addr, res.back().val, -1);
//	return 0;
//}