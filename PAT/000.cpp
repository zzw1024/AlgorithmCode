#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
struct SNode
{
	int val;
	SNode *next;
	SNode(int a = 0) :val(a), next(nullptr) {}
};
struct DNode
{
	int val;
	DNode *next, *last;
	DNode(int a = 0) :val(a), next(nullptr), last(nullptr) {}
};
SNode *reverseSingle(SNode *pHead)
{
	SNode *pre = nullptr;
	SNode *cur = pHead;
	while (cur != nullptr)
	{
		SNode *p = cur->next;
		cur->next = pre;
		pre = cur;
		cur = p;
	}
	return pre;
}

DNode *reverseDouble(DNode *pHead)
{
	DNode *pre = nullptr;
	DNode *cur = pHead;
	while (cur != nullptr)
	{
		DNode* p = cur->next;
		cur->next = pre;
		cur->last = p;
		pre = cur;
		cur = p;
	}
	return pre;
}

int main()
{
	SNode *L = new SNode(1);
	L->next = new SNode(2);
	L->next->next = new SNode(3);
	L->next->next->next = new SNode(4);
	L->next->next->next->next = new SNode(5);
	L->next->next->next->next->next = new SNode(6);
	L = reverseSingle(L);
	while (L)
	{
		cout << L->val << " ";
		L = L->next;
	}
	cout << endl;

	DNode *D = new DNode(1);
	D->next = new DNode(2);
	D->next->last = D;
	D->next->next = new DNode(3);
	D->next->next->last = D->next;
	D->next->next->next = new DNode(4);
	D->next->next->next->last = D->next->next;
	D->next->next->next->next = new DNode(5);
	D->next->next->next->next->last = D->next->next->next;
	D->next->next->next->next->next = new DNode(6);
	D->next->next->next->next->next->last = D->next->next->next->next;
	D = reverseDouble(D);
	while (D)
	{
		cout << D->val << " ";
		D = D->next;
	}
	cout << endl;
	return 0;	
}
struct Node
{
	int val;
	Node *l, *r;
	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
};
Node *find(Node* root, Node *p, Node *q)
{
	if (root == nullptr || p == root || q == root)return root;
	Node *left = find(root->l, p, q);
	Node *right = find(root->r, p, q);

	if (left == nullptr && right == nullptr)return nullptr;
	return left == nullptr ? right : left;
}

