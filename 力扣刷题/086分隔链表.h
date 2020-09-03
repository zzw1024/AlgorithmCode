#include "_000�⺯��.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//�о�������������ܻ���򵥵㣬���ڴ����,
//��ȷ���ڴ���˵�
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* p1 = new ListNode(-1);//�������С��x����
		ListNode* p2 = new ListNode(-1);//���������������
		ListNode* q1 = p1;
		ListNode* q2 = p2;
		while (head) {//��ͷ���
			ListNode* q = new ListNode(0);
			q->val = head->val;
			if (head->val < x) {
				q1->next = q;
				q1 = q;
			}
			else {
				q2->next = q;
				q2 = q;
			}
			head = head->next;
		}
		q1->next = p2->next;//���Ϊһ������
		return p1->next;//����Ҫͷ���
	}
};

//�ò��뷨����ԭ�����ϲ���
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* p = new ListNode(-1);
		p->next = head;
		head = p;//��һ��ͷ���
		ListNode* pro, *cur;
		pro = p;//Ҫ�����λ��
		cur = p;//�ƶ���λ��
		p = p->next;
		while (p) {
			if (p->val < x) {
				ListNode* q = new ListNode(0);
				q->val = p->val;
				cur->next = p->next;//ɾ������				
				p = cur->next;
				q->next = pro->next;//����
				pro->next = q;
				if (cur == pro)
					cur = cur->next;
				pro = q;
			}
			else {
				p = p->next;
				cur = cur->next;
			}
		}
		return head->next;
	}
};

void T086() {
	Solution s;
	vector<int>v;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	v = { 1,4,3,2,5,2 };
	for (auto a : v) {
		ListNode *q = new ListNode(0);
		q->val = a;
		p->next = q;
		p = q;
	}
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	p = s.partition(head->next,3);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}