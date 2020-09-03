//#include <iostream>
//#include <list>
//using namespace std;
//
//
////
////【题目】
////分别实现两个函数，一个可以删除单链表中倒数第K个节点，另一个可以删除双链表中倒数第K个节点。
////【要求】
////如果链表长度为N，时间复杂度达到O（N），额外空间复杂度达到O（1）。
////【题解】
////从头遍历链表，每移动一次，K--，直至移动到链表尾部，此时
////k>0,说明k太大，链表不用删除
////k==0，链表长度即是k， 删除头结点即可
////k<0,再次重头遍历链表，每移动一次，k++,
////当k==0时，此时结点为要删除结点的前结点，使其指向下一个结点即可
////双向链表一样，只不过需要注意前结点就好
//
//
//struct SNode
//{
//	int val;
//	SNode* next;
//	SNode(int a = 0) :val(a), next(nullptr) {}
//};
//
//struct DNode
//{
//	int val;
//	DNode* pre;
//	DNode* next;
//	DNode(int a = 0) :val(a), pre(nullptr), next(nullptr) {}
//};
//
//template<typename T>
//void printList(T head)
//{
//	T p = head->next;
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	cout << endl;
//}

//SNode* DeleteSList(SNode* head, int k)
//{
//	SNode*p = head->next;
//	while (p)
//	{
//		--k;
//		p = p->next;
//	}
//	if (k > 0)//k大于链表的长度，不用删除
//		return head;
//	else if (k == 0)//k==链表的长度，删除头结点即可
//		return head->next;
//	p = head;
//	while (k != 0)//找到删除结点的前结点
//	{
//		++k;
//		p = p->next;
//	}
//	p->next = p->next->next;
//	return head;
//}
//
//DNode* DeleteDList(DNode* head, int k)
//{
//	DNode*p = head->next;
//	while (p)
//	{
//		--k;
//		p = p->next;
//	}
//	if (k > 0)//k大于链表的长度，不用删除
//		return head;
//	else if (k == 0)//k==链表的长度，删除头结点即可
//		return head->next;
//	p = head;
//	while (k != 0)//找到删除结点的前结点
//	{
//		++k;
//		p = p->next;
//	}
//	p->next->next->pre = p;
//	p->next = p->next->next;
//	return head;
//}
//
//
//int main()
//{
//	SNode* head1 = new SNode();
//	DNode* head2 = new DNode();
//	SNode* p1 = head1;
//	DNode* p2 = head2;
//	for (int i = 1; i < 10; ++i)
//	{
//		SNode* q1 = new SNode(i);
//		DNode* q2 = new DNode(i);
//		p1->next = q1;
//		p1 = q1;
//		p2->next = q2;
//		q2->pre = p2;
//		p2 = q2;
//	}
//	cout << "删除前：" << endl;
//	printList(head1);
//	printList(head2);
//
//	head1 = DeleteSList(head1, 4);
//	head2 = DeleteDList(head2, 4);
//	cout << "删除后：" << endl;
//	printList(head1);
//	printList(head2);
//
//	return 0;
//}