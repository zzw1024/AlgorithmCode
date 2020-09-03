//#include <iostream>
//#include <queue>
//using namespace std;
//struct treeNode
//{
//	int v;
//	treeNode *l, *r;
//	treeNode(int a = -1) :v(a), l(nullptr), r(nullptr) {}
//};
//struct listNode
//{
//	int v;
//	listNode *pre, *next;
//	listNode(int a = -1) :v(a), pre(nullptr), next(nullptr) {}
//};
//treeNode* root = new treeNode(6);
//listNode* head = new listNode(-1);
//queue<int>qD;
//void creatTree()
//{
//	root->l = new treeNode(4);
//	root->r = new treeNode(7);
//	root->l->l = new treeNode(2);
//	root->l->r = new treeNode(5);
//	root->l->l->l = new treeNode(1);
//	root->l->l->r = new treeNode(3);
//	root->r->r = new treeNode(9);
//	root->r->l = new treeNode(8);
//}
//void getData(treeNode* rt)
//{
//	if (rt == nullptr)
//		return;
//	getData(rt->l);
//	qD.push(rt->v);
//	getData(rt->r);
//}
//void creatList()
//{
//	listNode* p = head;
//	while (!qD.empty())
//	{
//		listNode* q = new listNode(qD.front());
//		qD.pop();
//		p->next = q;
//		q->pre = p;
//		p = q;
//	}
//}
//void printD()
//{
//	listNode* p = head->next;
//	while (p != nullptr)
//	{
//		cout << p->v << " ";
//		p = p->next;
//	}
//}
//int main()
//{
//	creatTree();
//	getData(root);
//	creatList();
//	printD();
//	return 0;
//}