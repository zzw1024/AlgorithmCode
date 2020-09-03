//#include <iostream>
//#include <stack>
//using namespace std;
//
////【题目】
////给定一个单链表的头节点head，实现一个调整单链表的函数，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。
////例如：
////链表：1->2->3->4->5->6->7->8->null，K = 3。
////调整后为：3->2->1->6->5->4->7->8->null。其中7、8不调整，因为不够一组。
////【解题思路】
////方法一：
////使用栈，每K个节点依次入栈，并依次删除
////然后栈弹出尾插法插入节点
////方法二：
////直接在链表中使用头插法，进行反转
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(nullptr) {}
//};
//void printList(Node* head)
//{
//	Node *p = head->next;
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	cout << endl;
//}
//
//void byStack(Node* head, int k)
//{
//	Node* p = head->next, *pre = head;
//	stack<Node*>s;//保留节点地址，就不用删除和新建节点步骤
//	while (p)
//	{
//		s.push(p);
//		p = p->next;
//		if (s.size() == k)
//		{
//			pre->next = p;
//			while (!s.empty())
//			{
//				s.top()->next = pre->next;//断开循环
//				pre->next = s.top();
//				pre = pre->next;
//				s.pop();
//			}
//		}
//	}
//	printList(head);
//}
//
//void notStack(Node* head, int k)
//{
//	Node* p = head->next, *pre = head, *q, *tmp = nullptr;
//	int s = 0;
//	while (p)
//	{
//		if (s == 0)
//		{
//			tmp = pre->next;//每次循环更新的头结点
//			pre->next = nullptr;//断开循环
//		}
//		q = p->next;
//		p->next = pre->next;
//		pre->next = p;
//		p = q;
//		s++;
//		if (s == k)
//		{
//			s = 0;
//			pre = tmp;
//			pre->next = p;
//		}
//	}
//	tmp->next = nullptr;
//	p = pre->next;
//	pre->next = nullptr;//断开循环
//	while (p)//将后面不足k个节点还原
//	{
//		q = p->next;
//		p->next = pre->next;
//		pre->next = p;
//		p = q;
//	}	
//	printList(head);
//}
//
//int main()
//{
//	Node *head = new Node(-1);
//	Node* p = head;
//	for (int i = 1; i <= 8; ++i)
//	{
//		Node*q = new Node(i);
//		p->next = q;
//		p = q;
//	}
//	printList(head);
//	//byStack(head, 3);
//	notStack(head, 3);
//	return 0;
//}