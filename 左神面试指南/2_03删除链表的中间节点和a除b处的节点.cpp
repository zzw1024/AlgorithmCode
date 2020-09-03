//#include <iostream>
//
//using namespace std;
//
////【题目】
////给定链表的头节点head，实现删除链表的中间节点的函数。
////例如：
////不删除任何节点；
////1->2，删除节点1；
////1->2->3，删除节点2；
////1->2->3->4，删除节点2；
////1->2->3->4->5，删除节点3；
////进阶：
////给定链表的头节点head、整数a和b，实现删除位于a / b处节点的函数。
////例如：
////链表：1->2->3->4->5，假设a / b的值为r。
////如果r等于0，不删除任何节点；
////如果r在区间（0，1 / 5]上，删除节点1；
////如果r在区间（1 / 5，2 / 5]上，删除节点2；
////如果r在区间（2 / 5，3 / 5]上，删除节点3；
////如果r在区间（3 / 5，4 / 5]上，删除节点4；
////如果r在区间（4 / 5，1]上，删除节点5；
////如果r大于1，不删除任何节点。
////【题解】
////原题：
////使用快慢指针，当快指针到达链表尾部，则慢指针就是处于中间位置
////进阶：
////使用快慢指针求出链表长度，然后去确定a/b的位置
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(nullptr) {}
//};
//
//Node* deleteMid(Node* head)
//{
//	if (head == nullptr || head->next == nullptr)
//		return head;
//	if (head->next->next == nullptr)
//		return head->next;
//	Node* p = head;
//	Node* q = head->next->next;
//	while (q && q->next)
//	{
//		p = p->next;
//		q = q->next->next;
//	}
//	p->next = p->next->next;
//	return head;
//}
//
//Node* deleteA_B(Node* head, int a, int b)
//{
//	
//	if (head == nullptr || head->next == nullptr)
//		return head;
//
//	//使用双向链表求出链表长度
//	int n = 0;
//	Node* p = head;
//	Node* q = head;
//	while (q->next && q->next->next)
//	{
//		n++;
//		p = p->next;
//		q = q->next->next;
//	}
//	if (q->next == nullptr)
//		n = 2 * n;
//	else
//		n = 2 * n + 1;
//	int k = (double)a / (double)b * double(n) + 0.5;//向上取整
//	p = head;
//	while (--k)
//	{
//		p = p->next;
//	}
//	p->next = p->next->next;
//	return head;
//}
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
//
//int main()
//{
//	Node* head = new Node();
//	Node* p = head;
//	for (int i = 1; i < 6; ++i)
//	{
//		Node* q = new Node(i);
//		p->next = q;
//		p = q;
//	}
//	//p = head;
//	//printList(p);
//	//p = head;
//	//p = deleteMid(p);
//	//printList(p);
//	//p = head;
//	//p = deleteA_B(p, 1, 5);
//	//printList(p);
//	p = head;
//	p = deleteA_B(p, 2, 5);
//	printList(p);
//
//	return 0;
//}
