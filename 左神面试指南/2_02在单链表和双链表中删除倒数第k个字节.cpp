//#include <iostream>
//#include <list>
//using namespace std;
//
//
////
////����Ŀ��
////�ֱ�ʵ������������һ������ɾ���������е�����K���ڵ㣬��һ������ɾ��˫�����е�����K���ڵ㡣
////��Ҫ��
////���������ΪN��ʱ�临�ӶȴﵽO��N��������ռ临�ӶȴﵽO��1����
////����⡿
////��ͷ��������ÿ�ƶ�һ�Σ�K--��ֱ���ƶ�������β������ʱ
////k>0,˵��k̫��������ɾ��
////k==0�������ȼ���k�� ɾ��ͷ��㼴��
////k<0,�ٴ���ͷ��������ÿ�ƶ�һ�Σ�k++,
////��k==0ʱ����ʱ���ΪҪɾ������ǰ��㣬ʹ��ָ����һ����㼴��
////˫������һ����ֻ������Ҫע��ǰ���ͺ�
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
//	if (k > 0)//k��������ĳ��ȣ�����ɾ��
//		return head;
//	else if (k == 0)//k==����ĳ��ȣ�ɾ��ͷ��㼴��
//		return head->next;
//	p = head;
//	while (k != 0)//�ҵ�ɾ������ǰ���
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
//	if (k > 0)//k��������ĳ��ȣ�����ɾ��
//		return head;
//	else if (k == 0)//k==����ĳ��ȣ�ɾ��ͷ��㼴��
//		return head->next;
//	p = head;
//	while (k != 0)//�ҵ�ɾ������ǰ���
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
//	cout << "ɾ��ǰ��" << endl;
//	printList(head1);
//	printList(head2);
//
//	head1 = DeleteSList(head1, 4);
//	head2 = DeleteDList(head2, 4);
//	cout << "ɾ����" << endl;
//	printList(head1);
//	printList(head2);
//
//	return 0;
//}