//#include <iostream>
//
//using namespace std;
//
////Problem��
////	�����������ཻ��һϵ������
////	����Ŀ�� �ڱ����У�����������л���Ҳ�����޻�����������
////	�������ͷ�ڵ� head1��head2����������������ཻ��Ҳ����
////	���ཻ����ʵ��һ�������� ������������ཻ���뷵���ཻ��
////	��һ���ڵ㣻������ཻ������null ���ɡ� 
////	Ҫ���������1	�ĳ���ΪN������2�ĳ���ΪM��ʱ�临�Ӷ���ﵽ O(N + M)������
////	�ռ临�Ӷ���ﵽO(1)
////
////Solution��
////	�����жϵ������Ƿ��л�����ʹ�ÿ���ָ�뼴��֪������ָ���ཻ�����л�
////	�����ж�˫�����Ƿ��ཻ�����жϱ�����������ָ��ĵ�ַ�Ƿ���ͬ����ͬ���й�������
////	Ȼ���ڴ�ͷ���������������ȱ������Ĳ��֣�Ȼ��һ���������ָ����ͬʱ����Ϊ�ཻ�Ĳ�λ��
//
//
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(NULL) {}
//};
//
//void FindNode(Node* head1, Node* head2)
//{
//	if (head1->next == NULL || head2->next == NULL)
//		return;
//	Node *p1, *p2;
//	p1 = head1->next;
//	p2 = head2->next;
//	int size1, size2;//����������
//	size1 = size2 = 1;
//	while (p1->next || p2->next)
//	{
//		if (p1->next)
//		{
//			p1 = p1->next;
//			size1++;
//		}
//		if (p2->next)
//		{
//			p2 = p2->next;
//			size2++;
//		}
//	}
//	if (p1 != p2)
//	{
//		cout << "List1 and List2 have no commmon part!" << endl;
//		return;
//	}
//	cout << "List1 and List2 have commmon part!" << endl;
//	//���±������ҵ�����
//	p1 = head1->next;
//	p2 = head2->next;
//	for (int i = 0; i < (size1 > size2 ? size1 - size2 : size2 - size1); ++i)//�����ȱ���
//	{
//		if (size1 > size2)
//			p1 = p1->next;
//		else
//			p2 = p2->next;
//	}
//	while (p1 != p2)
//	{
//		p1 = p1->next;
//		p2 = p2->next;
//	}
//	cout << "�ཻ��λΪ��addr��" << p1 << "  val:" << p1->val << endl;
//
//}
//
//void Test()
//{
//	int a[] = { 1,2,3,4,5,6 };
//	int b[] = { 4,5,6 };
//	int c[] = { 7,8,9,10 };
//	Node* head1 = new Node(-1);
//	Node* head2 = new Node(-1);
//	Node* p1 = head1;
//	Node* p2 = head2;
//
//	for (auto n : a)
//	{
//		Node* q = new Node(n);
//		p1->next = q;
//		p1 = q;
//	}
//	p1->next = NULL;
//	for (auto n : b)
//	{
//		Node* q = new Node(n);
//		p2->next = q;
//		p2 = q;
//	}
//	p2->next = NULL;
//
//	cout << "�ཻ֮ǰ�жϣ�" << endl;
//	FindNode(head1, head2);
//	cout << "***********************" << endl;
//	for (auto n : c)
//	{
//		Node* q = new Node(n);
//		p1->next = q;
//		p1 = q;
//		p2->next = q;
//		p2 = q;
//	}
//	p1->next = NULL;
//	p2->next = NULL;
//
//	cout << "�ཻ֮���жϣ�" << endl;
//	FindNode(head1, head2);
//	cout << "***********************" << endl;
//}
//
