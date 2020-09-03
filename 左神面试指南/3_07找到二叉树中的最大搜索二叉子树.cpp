//#include <iostream>
//#include <vector>
//#include <queue>
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
/////////////////
//int inOrder(Node* root, vector<int>&in)
//{
//	if (root == nullptr)
//		return 0;
//	int ln = inOrder(root->l, in);
//	in.push_back(root->val);
//	int rn = inOrder(root->r, in);
//	return ln + 1 + rn;
//}
//
//void solve01(Node* root)
//{
//	Node* res = new Node();
//	int maxN = -1;
//	queue<Node*>q;
//	q.push(root);
//	while (!q.empty())
//	{
//		Node* p = q.front();
//		q.pop();
//		vector<int>tempV, V;
//		int tempN = inOrder(p, V);//子树个数
//		tempV = V;
//		sort(V.begin(), V.end());
//		if (tempV == V && maxN < tempN)
//		{
//			maxN = tempN;
//			res = p;
//		}
//		if (p->l != nullptr)
//			q.push(p->l);
//		if (p->r != nullptr)
//			q.push(p->r);
//	}
//	cout << maxN << " " << res->val << endl;
//}
////////////////////////
//Node* posOrder(Node* root, int* record)
//{
//	if (root == nullptr)
//	{
//		record[0] = 0;
//		record[1] = INT32_MAX;
//		record[2] = INT32_MIN;
//		return nullptr;
//	}
//	int value = root->val;
//	Node* l = root->l;
//	Node* r = root->r;
//	Node* lBFS = posOrder(l, record);
//	int lSize = record[0];
//	int lMin = record[1];
//	int lMax = record[2];
//	Node* rBFS = posOrder(r, record);
//	int rSize = record[0];
//	int rMin = record[1];
//	int rMax = record[2];
//	record[1] = min(lMin, value);
//	record[2] = max(rMax, value);
//	if (l == lBFS && r == rBFS && lMax < value && value < rMin)//左边最大的小于右边最小的
//	{
//		record[0] = lSize + rSize + 1;//二叉树的大小
//		return root;
//	}
//	record[0] = max(lSize, rSize);
//	return lSize > rSize ? lBFS : rBFS;
//}
//
//void solve02(Node* root)
//{
//	int record[3] = { 0 };
//	Node* res = posOrder(root, record);
//	cout << record[0] << " " << res->val << endl;
//}
//
//int main()
//{
//	Node* root = createTree();
//	solve01(root);
//	solve02(root);
//	return 0;	
//}