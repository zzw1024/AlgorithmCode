#include "_000�⺯��.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//������ͷ������������
//���У��ĸ������ظ��ˣ��ͽ���ȫ��ɾ������
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//����һ��ͷ���
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p;
		int flag = 0;//��������ظ�����
		while (q && p) {
			q = q->next;
			while (q && q->next && q->val == q->next->val) {
				//һ���ļǵ��ͷ�ɾ��������
				ListNode *ptr = q;
				p->next = q->next;
				delete(ptr);
				ptr = NULL;
				q = p->next;
				flag = 1;
			}
			if (flag) {//ɾ�����һ���ظ��˵�����
				ListNode *ptr = q;
				p->next = q->next;
				delete(ptr);
				ptr = NULL;
				q = p;
				flag = 0;
			}
			else
				p = p->next;
		}
		return head->next;
	}
};

//���ͷ�ɾ���Ľڵ㣬�Ҳ����飬���ö಩��������д��
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//����һ��ͷ���
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p;
		while (p->next) {
			q = p->next;
			while (q->next && q->val == q->next->val)
				q = q->next;
			if (p->next != q)
				p->next = q->next;
			else
				p = p->next;
		}
		return head->next;
	}
};



//ʹ�õݹ飬��ʹ��while

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head) return head;
		if (head->next && head->val == head->next->val) {
			while (head->next && head->val == head->next->val) {
				head = head->next;
			}
			return deleteDuplicates(head->next);
		}
		head->next = deleteDuplicates(head->next);
		return head;
	}
};
void T082() {
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	vector<int>v = { 1,2,3,4,4, 5, 5};
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
	Solution s;
	p = s.deleteDuplicates(head->next);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}