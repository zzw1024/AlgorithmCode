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
//	root->l = new Node(13);
//	root->r = new Node(12);
//	root->l->l = new Node(0);
//	root->l->r = new Node(3);
//	root->r = new Node(12);
//	root->r->l = new Node(10);
//	root->r->r = new Node(1);
//	root->r->r->r = new Node(16);
//	return root;
//}
//
//void inOrder(Node* root, vector<int>&inRes,vector<Node*>&Res)
//{
//	if (root == nullptr)
//		return;
//	inOrder(root->l, inRes, Res);
//	inRes.push_back(root->val);
//	Res.push_back(root);
//	inOrder(root->r, inRes, Res);
//}
//int main()
//{
//	Node* root = createTree();
//	vector<int>inRes, tempV;
//	vector<Node*>Res;
//	inOrder(root, inRes, Res);
//	Node* errs[2] = { nullptr };
//	tempV = inRes;
//	sort(inRes.begin(), inRes.end());
//	for (int i = 0; i < inRes.size(); ++i)
//	{
//		if (inRes[i] != tempV[i])
//			if (errs[0] == nullptr)
//				errs[0] = Res[i];
//			else
//				errs[1] = Res[i];
//	//}
//	return 0;
//}