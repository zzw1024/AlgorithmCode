//#include<iostream>
//
//using namespace std;
//
//
////【题目】
////据说著名犹太历史学家Josephus有过以下故事：
////在罗马人占领乔塔帕特后，39个犹太人与Josephus及他的朋友躲到一个洞中，
////39个犹太人决定宁愿死也不要被敌人抓到，于是决定了一个自杀方式，41个人排成一个圆圈，
////由第1个人开始报数，报数到3的人就自杀，然后再由下一个人重新报1，报数到3的人再自杀，
////这样依次下去，直到剩下最后一个人时，那个人可以自由选择自己的命运。
////这就是著名的约瑟夫问题。现在请用单向环形链表描述该结构并呈现整个自杀过程。
////
////输入：一个环形单向链表的头节点head和报数的值m。
////返回：最后生存下来的节点，且这个节点自己组成环形单向链表，其他节点都删掉。
////进阶：
////如果链表节点数为N，想在时间复杂度为O（N）时完成原问题的要求，该怎么实现？
////
////【题解】
////整个进阶解法的过程总结为：
////1.遍历链表，求链表的节点个数记为n，时间复杂度为O（N）。
////2.根据n和m的值，还有上文分析的Num（i - 1）和Num（i）的关系，递归求生存节点的编号；这一步的具体过程请参看如下代码中的getLive方法，getLive方法为单决策的递归函数，且递归为N层，所以时间复杂度为O（N）。
////3.最后根据生存节点的编号，遍历链表找到该节点，时间复杂度为O（N）。
////4.整个过程结束，总的时间复杂度为O（N）。
//
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(NULL) {}
//};
//
////第一种方法：单链表循环
//void findTheMan(Node* head, int k)
//{
//	Node*p  = head;
//	while (p->next)
//		p = p->next;
//	p->next = head->next;
//	p = head;
//	while(p->next!=p)
//	{
//		for (int i = 0; i < k-1; ++i)
//			p = p->next;	
//		cout << p->next->val << " ";
//		p->next = p->next->next;
//	}
//	cout << endl << "The last man: " << p->val << endl;
//}
//
////进阶解法：
//int  getLive(int tmp, int k)
//{
//	if (tmp == 1)
//		return 1;
//	return (getLive(tmp - 1, k) + k - 1) % tmp + 1;
//}
//
//void getTheMan(Node* head, int k)
//{
//	Node* p = head->next;
//	int tmp = 0;
//	while (p)
//	{
//		tmp++;
//		p = p->next;
//	}
//	tmp = getLive(tmp, k);
//	while (tmp--)
//		head = head->next;
//	cout << head->val << endl;
//}
//int main()
//{
//	Node* head = new Node();
//	Node* p = head;
//	for (int i = 1; i < 42; ++i)
//	{
//		Node*q = new Node(i);
//		p->next = q;
//		p = q;
//	}
//	//findTheMan(head,3);
//	getTheMan(head, 3);
//
//	return 0;
//}
