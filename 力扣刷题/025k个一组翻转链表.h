#include "000�⺯��.h"



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/************************�Լ����****************************/
 //����ͷ��㣬�����е����ݰ���k��k���ط�ת,ʹ��ջ��ջ��ԭ��
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1 || !head || !(head->next))return head;
		ListNode* Res = new ListNode(0);
		ListNode* r = Res;
		ListNode* p = head;
		stack<int> S;
		while (p) {
			S.push(p->val);			
			p = p->next;			
			if (S.size() == k) {
				while (!S.empty()) { //����β�巨
					ListNode* q = new ListNode(0);
					q->val = S.top();
					r->next = q;
					r = q;
					S.pop();
				}				
			}
		}
		if (S.size()) {
			while (!S.empty()) {			//����ͷ�巨
					ListNode* q = new ListNode(0);
					q->val = S.top();
					q->next = r->next;
					r->next = q;					
					S.pop();				
			}
		}
		return Res->next;

	}
	
};




/*******************************���ʹ�***************************/
//�������������ÿk��Ϊһ������ת����ʵ�����ǰ�ԭ����ֳ�����С�Σ�
//Ȼ��ֱ������з�ת����ô�϶��ܹ���Ҫ����������һ���������ֶεģ�
//һ����������ת�ģ����Ǿ�����Ŀ�и����������������ڸ�������1->2->3->4->5��
//һ���ڴ�����������ʱ�����Ǵ��ʱ�򶼻��ڿ�ͷ�ټ�һ��dummy node����Ϊ��ת����ʱͷ�����ܻ�仯
//Ϊ�˼�¼��ǰ���µ�ͷ����λ�ö������dummy node����ô���Ǽ���dummy node��������Ϊ
//- 1->1->2->3->4->5�����kΪ3�Ļ������ǵ�Ŀ���ǽ�1, 2, 3��תһ�£���ô������ҪһЩָ��
//��pre��next�ֱ�ָ��Ҫ��ת�������ǰ���λ�ã�Ȼ��ת��pre��λ�ø��µ������µ�λ�ã�



//���ƴ���
//- 1->1->2->3->4->5
//|        |  |
//pre      cur next
//
//- 1->3->2->1->4->5
//|     |  |
//cur   pre next
//���ƴ���


//�Դ����ƣ�ֻҪcur�߹�k���ڵ㣬��ônext����cur->next��
//�Ϳ��Ե��÷�ת���������оֲ���ת�ˣ�ע�ⷭת֮���µ�cur��pre��λ�ö���ͬ�ˣ�
//��ô��ת֮��curӦ�ø���Ϊpre->next�����������Ҫ��ת�Ļ���cur����Ϊcur->next��



//�ⷨһ��//��ʱ�����Լ��Ľ��

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1) return head;
		ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
		dummy->next = head;//���ͷ���
		for (int i = 1; cur; ++i) {
			if (i % k == 0) {
				pre = reverseOneGroup(pre, cur->next);
				cur = pre->next;
			}
			else {
				cur = cur->next;
			}
		}
		return dummy->next;
	}
	ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
		ListNode *last = pre->next, *cur = last->next;
		while (cur != next) {
			last->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = last->next;
		}
		return last;
	}
};



//����Ҳ������һ����������ɣ��������ȱ�����������ͳ�Ƴ�����ĳ��ȣ�
//Ȼ��������ȴ��ڵ���k�����ǿ�ʼ�����ڵ㣬��k = 2ʱ��ÿ������ֻ��Ҫ����һ�Σ�
//��k = 3ʱ��ÿ����Ҫ����2�ˣ�����i��1��ʼѭ����ע�⽻��һ�κ����preָ�룬Ȼ��num�Լ�k
//ֱ��num < kʱѭ���������μ��������£�



//�ⷨ����ʱ�������������


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
		dummy->next = head;
		int num = 0;
		while (cur = cur->next) ++num;
		while (num >= k) {
			cur = pre->next;
			for (int i = 1; i < k; ++i) {
				ListNode *t = cur->next;
				cur->next = t->next;
				t->next = pre->next;
				pre->next = t;
			}
			pre = cur;
			num -= k;
		}
		return dummy->next;
	}
};



//����Ҳ����ʹ�õݹ�������������head��¼ÿ�εĿ�ʼλ�ã�cur��¼����λ�õ���һ���ڵ㣬
//Ȼ�����ǵ���reverse����������η�ת��Ȼ��õ�һ��new_head��ԭ����head�ͱ����ĩβ��
//��ʱ�������ϵݹ������һ�εõ����½ڵ㣬����new_head���ɣ��μ��������£�


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *cur = head;
		for (int i = 0; i < k; ++i) {
			if (!cur) return head;
			cur = cur->next;
		}
		ListNode *new_head = reverse(head, cur);
		head->next = reverseKGroup(cur, k);
		return new_head;
	}
	ListNode* reverse(ListNode* head, ListNode* tail) {
		ListNode *pre = tail;
		while (head != tail) {
			ListNode *t = head->next;
			head->next = pre;
			pre = head;
			head = t;
		}
		return pre;
	}
};
		

void T025() {
	ListNode* N = new ListNode(0);
	ListNode* p = N;
	for (int i = 0; i < 5; ++i) {
		ListNode* q = new ListNode(0);
		q->val = i + 1;
		p->next = q;
		p = q;
	}
	p = N->next;
	cout << "ԭ��";
	while (p) {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
	Solution S;
	p = S.reverseKGroup(N->next,3);
	cout << "ת��";
	while (p) {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
	

}