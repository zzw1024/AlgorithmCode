////#include <iostream>
////#include <vector>
////using namespace std;
////struct Node
////{
////	int val, next;
////}List[100010];
////int head, n, k;
////int main()
////{
////	cin >> head >> n >> k;
////	while (n--)
////	{
////		int address, data, next;
////		cin >> address >> data >> next;
////		List[address].val = data;
////		List[address].next = next;
////	}
////	int head1 = 100001, head2 = 100002, head3 = 100003;//分别是负数、中间数、>k数的链表
////	int p = head, p1 = head1, p2 = head2, p3 = head3;
////	while (p != -1)
////	{
////		if (List[p].val < 0)
////		{
////			List[p1].next = p;
////			p1 = p;
////		}
////		else if (List[p].val > k)
////		{
////			List[p3].next = p;
////			p3 = p;
////		}
////		else
////		{
////			List[p2].next = p;
////			p2 = p;
////		}
////		p = List[p].next;
////	}
////	//这里的顺序千万不要反了，因为next不是地址，要先改变，再赋值
////	List[p3].next = -1;
////	List[p2].next = List[head3].next;
////	List[p1].next = List[head2].next;	
////	p = List[head1].next;
////	while (List[p].next != -1)
////	{
////		printf("%05d %d %05d\n", p, List[p].val, List[p].next);
////		p = List[p].next;
////	}
////	printf("%05d %d %d\n", p, List[p].val, List[p].next);
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, k, head;
//	cin >> head >> n >> k;
//	if (head == -1)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	int addr[1000100] = { 0 }, next[1000100] = { 0 };
//	vector<int>v, Fu, Equ, More;
//	for (int i = 0; i < n; ++i)
//	{
//		int a, key, b;
//		cin >> a >> key >> b;
//		addr[a] = key;
//		next[a] = b;
//	}
//	while (head != -1)
//	{
//		if (addr[head] < 0)
//			Fu.push_back(head);
//		else if (addr[head] > k)
//			More.push_back(head);
//		else
//			Equ.push_back(head);
//		head = next[head];
//	}
//	for (auto a : Equ)
//		Fu.push_back(a);
//	for (auto a : More)
//		Fu.push_back(a);
//	for (int i = 0; i < Fu.size() - 1; ++i)
//		printf("%05d %d %05d\n", Fu[i], addr[Fu[i]], Fu[i + 1]);
//	printf("%05d %d -1\n", Fu.back(), addr[Fu.back()]);
//	return 0;
//}