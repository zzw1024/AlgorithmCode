#include "000�⺯��.h"



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//�Լ��ⷨ���Ƚϱ���Ϊ���㷨����������Ԫ�غϲ�������
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() < 1)return NULL;
	vector<int>Nums;
	ListNode* Res = new ListNode(0);
	ListNode* q = Res;

	for (auto l : lists) {
		ListNode*p = l->next;//ȥ��ͷ���
		while (p) {
			Nums.push_back(p->val);
			p = p->next;
		}
	}
	
	sort(Nums.begin(),Nums.end());
	for (auto n : Nums) {
		ListNode* t = new ListNode(0);
		t->val = n;
		q->next = t;
		q = t;
	}
	return Res->next;

}
//���õݹ�˼�룬���������ϲ�����//�ݹ��Ϊ��ʱ
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* rtn = new ListNode(INT_MIN);
		for (auto node : lists) {
			rtn = merge(rtn, node);
		}
		return rtn->next;
	}
	ListNode* merge(ListNode * l1, ListNode* l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		if (l1->val < l2->val)
		{
			l1->next = merge(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = merge(l1, l2->next);
			return l2;
		}
	}
};

//�õ����η� Divide and Conquer Approach������˵���ǲ�ͣ�Ķ԰뻮�֣�
//����k�������Ȼ���Ϊ�ϲ�����k / 2������������ٲ�ͣ�����»��֣�
//ֱ�����ֳ�ֻ��һ����������������񣬿�ʼ�ϲ����ٸ�������˵����ϲ�6������
//��ô���շ��η����������ȷֱ�ϲ�0��3��1��4��2��5��������һ��ֻ��ϲ�3������
//�����ٺϲ�1��3������2�ϲ��Ϳ����ˡ������е�k��ͨ��(n + 1) / 2 ����ģ�
//����ΪɶҪ��1�أ�����Ϊ�˵�nΪ������ʱ��k��ʼ�մӺ��ο�ʼ�����統n = 5ʱ��
//��ô��ʱk = 3����0��3�ϲ���1��4�ϲ������м��2�ճ�������n��ż����ʱ�򣬼�1Ҳ������Ӱ�죬
//���統n = 4ʱ����ʱk = 2����ô0��2�ϲ���1��3�ϲ�������������⣬�μ��������£�

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return NULL;
		int n = lists.size();
		while (n > 1) {
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; ++i) {
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1), *cur = dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1) cur->next = l1;
		if (l2) cur->next = l2;
		return dummy->next;
	}
};

//������������һ�ֽⷨ�����ֽⷨ��������С���������ݽṹ��
//�������Ȱ�k���������Ԫ�ض�������С���У����ǻ��Զ��ź���
//Ȼ������ÿ��ȡ����С���Ǹ�Ԫ�ؼ����������ս���������У�
//Ȼ���ȡ��Ԫ�ص���һ��Ԫ���ټ�����У��´��ԴӶ���ȡ����С��Ԫ������ͬ�Ĳ�����
//�Դ����ƣ�ֱ������û��Ԫ���ˣ���ʱk������Ҳ�ϲ�Ϊ��һ�����������׽ڵ㼴�ɣ��������£�
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto cmp = [](ListNode*& a, ListNode*& b) {
			return a->val > b->val;
		};
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
		for (auto node : lists) {
			if (node) q.push(node);
		}
		ListNode *dummy = new ListNode(-1), *cur = dummy;
		while (!q.empty()) {
			auto t = q.top(); q.pop();
			cur->next = t;
			cur = cur->next;
			if (cur->next) q.push(cur->next);
		}
		return dummy->next;
	}
};
//�����еĽ��ֵ���ֵ����ֵ����Сֵ����¼������
//Ȼ���¼ÿ�����ֵ���ֵĴ������������Ǵ���Сֵ���������ֵ��ʱ��
//�ͻᰴ˳�򾭹����еĽ��ֵ����������ֵĴ������������Ӧ�����Ľ�㡣
//�������ֽⷨ�и��ر���Ҫע��ĵط����Ǿ��Ǻϲ���������㶼�����½����ģ�
//����ĳЩ����£����ǲ����½���㣬��ֻ�ܽ��������������ӽ��Ļ�����ô�˽ⷨ�Ͳ���ʹ�ã�
//�����ڱ��Ⲣû���������ƣ�����������OJ���μ��������£�
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *dummy = new ListNode(-1), *cur = dummy;
		unordered_map<int, int> m;
		int mx = INT_MIN, mn = INT_MAX;
		for (auto node : lists) {
			ListNode *t = node;
			while (t) {
				mx = max(mx, t->val);
				mn = min(mn, t->val);
				++m[t->val];
				t = t->next;
			}
		}
		for (int i = mn; i <= mx; ++i) {
			if (!m.count(i)) continue;
			for (int j = 0; j < m[i]; ++j) {
				cur->next = new ListNode(i);
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};

void T023() {
	vector<ListNode*>lists;
	srand((int)time(0));
	for (int i = 0; i < 3; ++i) {
		ListNode* head,*p;
		head = new ListNode(0);
		p = head;
		for (int j = 0; j < 5; ++j) {
			ListNode* t = new ListNode(0);
			t->val = rand() % 100;			
			p->next = t;
			p = t;
		}
		lists.push_back(head);
		head = head->next;
		while (head) {
			cout << head->val << '\t';
			head = head->next;
		}
		cout << endl;
	}
	ListNode* L1 = mergeKLists(lists);
	while (L1) {
		cout << L1->val << '\t';
		L1 = L1->next;
	}
	
	cout << endl;





}




