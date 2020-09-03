////#include <iostream>
////#include <unordered_map>
////#include <cmath>
////using namespace std;
////struct Node
////{
////	int addr, val;
////	Node(int a, int b) :addr(a), val(b) {}
////};
////struct List
////{
////	Node val;
////	List* next;
////	List(Node a) :val(a), next(nullptr) {}
////};
////int N, head, addr1, addr2, val, numbers[100100] = { 0 };
////int main()
////{
////	cin >> head >> N;
////	if (head == -1)//切记，此时有一个测试例子是头结点为-1，那么什么也不输出
////		return 0;
////	unordered_map<int, pair<int, int>>map;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> addr1 >> val >> addr2;
////		map[addr1] = make_pair(val, addr2);
////	}
////	//将链表组合起来
////	List* resHead = new List(Node(0, -1));
////	List* delHead = new List(Node(0, -1));
////	List* p = resHead;
////	while (head != -1)
////	{
////		List* q = new List(Node(head, map[head].first));
////		p->next = q;
////		p = q;
////		head = map[head].second;
////	}
////	List* pre = resHead, *delP = delHead;
////	p = pre->next;
////	while (p != nullptr)
////	{
////		if (numbers[abs(p->val.val)] == 1)
////		{
////			pre->next = p->next;//删除
////			List* q = new List(Node(p->val.addr, p->val.val));
////			delP->next = q;
////			delP = q;
////			delete p;
////			p = pre->next;
////		}
////		else
////		{
////			numbers[abs(p->val.val)]++;
////			pre = p;
////			p = pre->next;
////		}
////	}
////	p = resHead->next;
////	while (p != nullptr)
////	{
////		printf("%05d %d ", p->val.addr, p->val.val);	
////		p = p->next;
////		if (p == nullptr)
////			printf("%d\n", -1);
////		else
////			printf("%05d\n", p->val.addr);
////	}
////	p = delHead->next;
////	while (p != nullptr)
////	{
////		printf("%05d %d ", p->val.addr, p->val.val);
////		p = p->next;
////		if (p == nullptr)
////			printf("%d\n", -1);
////		else
////			printf("%05d\n", p->val.addr);
////	}
////	return 0;
////}
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//struct Node
//{
//	int addr, key;
//};
//int main()
//{
//	int n, head, addr, key, next, address[1000100], nextAddr[1000100];
//	bool isExist[100100] = { false };
//	cin >> head >> n;
//	if (head == -1)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	vector<Node>v, del;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> addr >> key >> next;
//		address[addr] = key;
//		nextAddr[addr] = next;
//	}
//	while (head != -1)
//	{
//		v.push_back({ head,address[head] });
//		head = nextAddr[head];
//	}
//	int flag = 0;
//	for (auto t : v)
//	{
//		if (isExist[abs(t.key)] == false)
//		{
//			if (flag == 0)
//			{
//				printf("%05d %d ", t.addr, t.key);
//				flag = 1;
//			}
//			else
//				printf("%05d\n%05d %d ", t.addr, t.addr, t.key);
//			isExist[abs(t.key)] = true;
//		}
//		else
//			del.push_back(t);
//	}
//	if (flag == 1)
//		printf("-1\n");
//	for (int i = 0; i < del.size(); ++i)
//		if (i == 0)
//			printf("%05d %d ", del[i].addr, del[i].key);
//		else
//			printf("%05d\n%05d %d ", del[i].addr, del[i].addr, del[i].key);
//	if(del.size()>0)
//		printf("-1\n");
//	return 0;
//}
//
//
//
//
