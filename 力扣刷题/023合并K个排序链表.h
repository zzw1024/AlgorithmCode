#include "000库函数.h"



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己解法，比较笨，为用算法，即将所有元素合并再排序
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() < 1)return NULL;
	vector<int>Nums;
	ListNode* Res = new ListNode(0);
	ListNode* q = Res;

	for (auto l : lists) {
		ListNode*p = l->next;//去除头结点
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
//才用递归思想，进行两两合并排序//递归较为耗时
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

//用到分治法 Divide and Conquer Approach。简单来说就是不停的对半划分，
//比如k个链表先划分为合并两个k / 2个链表的任务，再不停的往下划分，
//直到划分成只有一个或两个链表的任务，开始合并。举个例子来说比如合并6个链表，
//那么按照分治法，我们首先分别合并0和3，1和4，2和5。这样下一次只需合并3个链表，
//我们再合并1和3，最后和2合并就可以了。代码中的k是通过(n + 1) / 2 计算的，
//这里为啥要加1呢，这是为了当n为奇数的时候，k能始终从后半段开始，比如当n = 5时，
//那么此时k = 3，则0和3合并，1和4合并，最中间的2空出来。当n是偶数的时候，加1也不会有影响，
//比如当n = 4时，此时k = 2，那么0和2合并，1和3合并，完美解决问题，参见代码如下：

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

//我们再来看另一种解法，这种解法利用了最小堆这种数据结构，
//我们首先把k个链表的首元素都加入最小堆中，它们会自动排好序。
//然后我们每次取出最小的那个元素加入我们最终结果的链表中，
//然后把取出元素的下一个元素再加入堆中，下次仍从堆中取出最小的元素做相同的操作，
//以此类推，直到堆中没有元素了，此时k个链表也合并为了一个链表，返回首节点即可，代码如下：
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
//将所有的结点值出现的最大值和最小值都记录下来，
//然后记录每个结点值出现的次数，这样我们从最小值遍历到最大值的时候，
//就会按顺序经过所有的结点值，根据其出现的次数，建立相对应个数的结点。
//但是这种解法有个特别需要注意的地方，那就是合并后的链表结点都是重新建立的，
//若在某些情况下，我们不能新建结点，而只能交换或者重新链接结点的话，那么此解法就不能使用，
//但好在本题并没有这种限制，可以完美过OJ，参见代码如下：
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




