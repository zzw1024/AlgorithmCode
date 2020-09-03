#include "_000�⺯��.h"


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //�о�Ӧ����˫��ָ�������
 //����ͷ���
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !k)return head;
		ListNode* s = head->next;//ץסͷ
		ListNode* e  = head->next;//ץסͷβ
		int size = 1;//����������
		while (e->next) {
			e = e->next;
			++size;
		}
		k = k % size;//�����ظ�������
		if (!k)return head;
		k = size - k;//�ƶ���������ʾβָ�������ƶ�k��
		e->next = head->next;//�γ�һ�������б�
		while (k--) {
			s = s->next;//���������ƣ�ͷָ��������
			e = e->next;
		}
		head->next =  s;//ȷ��ͷ���
		e->next = NULL;//ȷ��β���
		return head;
	}
};

//������ͷ��㡾��Ŀ������������ͷ�ڵ㡿
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !k)return head;
		ListNode* s = head;//ץסͷ
		ListNode* e = head;//ץסͷβ
		int size = 1;//����������
		while (e->next) {
			e = e->next;
			++size;
		}
		k = k % size;//�����ظ�������
		if (!k)return head;
		k = size - k;//�ƶ���������ʾβָ�������ƶ�k��
		e->next = head;//�γ�һ�������б�
		while (k--) {
			s = s->next;//���������ƣ�ͷָ��������
			e = e->next;
		}
		head = s;//ȷ��ͷ���
		e->next = NULL;//ȷ��β���
		return head;
	}
};

 //ֱ���ڵ������ϲ���

 class Solution {
 public:
	 ListNode* rotateRight(ListNode* head, int k) {
		 if (!head || !k)return head;
		 ListNode* e = head->next;//ץסͷβ
		 int size = 1;//����������
		 while (e->next) {
			 e = e->next;
			 ++size;
		 }
		 k = k % size;//�����ظ�������
		 if (!k)return head;
		 k = size - k;//�ƶ���������ʾβָ�������ƶ�k��
		 e->next = head->next;
		 while (k--) head = head->next;//���������ƣ�ͷָ��������		 
		 e = head;
		 head->next = e->next;
		 e->next = NULL;
		 return head;
	 }
 };
void T061() {
	Solution s;
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	for (int i = 1; i <= 5; ++i) {
		ListNode* q = new ListNode(i);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	head = s.rotateRight(head,1);
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl << "****************" << endl;


	p = head;
	for (int i = 0; i <= 2; ++i) {
		ListNode* q = new ListNode(i);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	head = s.rotateRight(head, 4);
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl << "****************" << endl;
}