//#include <iostream>
//
//using namespace std;
//
////����Ŀ��
////���������ͷ�ڵ�head��ʵ��ɾ��������м�ڵ�ĺ�����
////���磺
////��ɾ���κνڵ㣻
////1->2��ɾ���ڵ�1��
////1->2->3��ɾ���ڵ�2��
////1->2->3->4��ɾ���ڵ�2��
////1->2->3->4->5��ɾ���ڵ�3��
////���ף�
////���������ͷ�ڵ�head������a��b��ʵ��ɾ��λ��a / b���ڵ�ĺ�����
////���磺
////����1->2->3->4->5������a / b��ֵΪr��
////���r����0����ɾ���κνڵ㣻
////���r�����䣨0��1 / 5]�ϣ�ɾ���ڵ�1��
////���r�����䣨1 / 5��2 / 5]�ϣ�ɾ���ڵ�2��
////���r�����䣨2 / 5��3 / 5]�ϣ�ɾ���ڵ�3��
////���r�����䣨3 / 5��4 / 5]�ϣ�ɾ���ڵ�4��
////���r�����䣨4 / 5��1]�ϣ�ɾ���ڵ�5��
////���r����1����ɾ���κνڵ㡣
////����⡿
////ԭ�⣺
////ʹ�ÿ���ָ�룬����ָ�뵽������β��������ָ����Ǵ����м�λ��
////���ף�
////ʹ�ÿ���ָ����������ȣ�Ȼ��ȥȷ��a/b��λ��
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
//	//ʹ��˫���������������
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
//	int k = (double)a / (double)b * double(n) + 0.5;//����ȡ��
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
