//#include <iostream>
//#include <vector>
//#include <queue>
//#include <hash_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int a = -1) :val(a), l(nullptr), r(nullptr) {}
//};
//Node* createTree()
//{
//	Node* root = new Node(6);
//	root->l = new Node(1);
//	root->r = new Node(12);
//	root->l->l = new Node(0);
//	root->l->r = new Node(3);
//	root->r = new Node(12);
//	root->r->l = new Node(10);
//	root->r->r = new Node(13);
//	root->r->l->l = new Node(4);
//	root->r->l->r = new Node(14);
//	root->r->l->l->l = new Node(2);
//	root->r->l->l->r = new Node(5);
//	root->r->l->r->l = new Node(11);
//	root->r->l->r->r = new Node(15);
//	root->r->r->l = new Node(20);
//	root->r->r->r = new Node(16);
//	return root;
//}
/////////////////solve01////////////
//bool isBSTNode(Node* h, Node* n)//h为根节点，n为判断节点
//{
//	if (h == nullptr)
//		return false;
//	if (h == n)
//		return true;
//	return isBSTNode(h->val > n->val ? h->l : h->r, n);//进行SBT树判断
//}
//int maxTopo(Node* h, Node* n)
//{
//	if (h != nullptr && n != nullptr && isBSTNode(h, n))
//		return maxTopo(h, n->l) + maxTopo(h, n->r) + 1;//树的大小
//	return 0;
//}
//int bstTopoSize1(Node* root)
//{
//	if (root == nullptr)
//		return 0;
//	int maxN = maxTopo(root, root);//计算拓扑图节点数的大小
//	maxN = max(maxN, bstTopoSize1(root->l));
//	maxN = max(maxN, bstTopoSize1(root->r));
//}
///////////////////solve02/////////////
//struct Record
//{
//	int l, r;
//	Record(int a = 0, int b = 0) :l(a), r(b) {}
//};
//int modifyMap(Node* n, int v, hash_map<Node*, Record>m, bool s)
//{
//	if (n == nullptr || m.find(n) == m.end())
//		return 0;
//	Record r = m[n];
//	if ((s&&n->val > v) || ((!s) && n->val < v))
//	{
//		m.erase(n);
//		return r.l + r.r + 1;
//	}
//	else
//	{
//		int minus = modifyMap(s ? n->r : n->l, v, m, s);
//		if (s)
//			r.r = r.r - minus;
//		else
//			r.l = r.l - minus;
//		m[n] = r;
//		return minus;
//	}
//}
//int posOrder(Node* root, hash_map<Node*, Record>map)
//{
//	if (root == nullptr)
//		return 0;
//	int ls = posOrder(root->l, map);
//	int rs = posOrder(root->r, map);
//	modifyMap(root->l, root->val, map, true);
//	modifyMap(root->r, root->val, map, false);
//	int lbst = map.find(root->l) == map.end() ? 0 : map[root->l].l + map[root->l].r + 1;
//	int rbst = map.find(root->r) == map.end() ? 0 : map[root->r].l + map[root->r].r + 1;
//	map[root] = Record{ lbst,rbst };
//	return max(lbst + rbst + 1, max(ls, rs));
//}
//int bstTopoSize2(Node* root)
//{
//	hash_map<Node*, Record>map;
//	return posOrder(root, map);
//}
//int main()
//{
//	Node* root = createTree();
//	cout << bstTopoSize2(root);
//	return 0;
//}
//
