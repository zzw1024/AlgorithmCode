//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//struct Node
//{
//	int v;
//	Node *l, *r;
//	Node(int a = -1) :v(a), l(nullptr), r(nullptr) {}
//};
//Node *root, *newRoot;
//queue<string>q;
//void createTree(Node* &root)
//{
//	root = new Node(1);
//	root->l = new Node(2);
//	root->r = new Node(3);
//	root->l->l = new Node(4);
//	root->r->r = new Node(5);
//}
//void getString(Node* root)
//{
//	if (root == nullptr)
//	{
//		q.push("#");
//		return;
//	}
//	q.push(to_string(root->v));
//	getString(root->l);
//	getString(root->r);
//}
//
//Node* reCreateTree()
//{
//	string s = q.front();
//	q.pop();
//	if (q.empty())
//		return;
//	if (s == "#")
//		return nullptr;
//	Node *temp = new Node(atoi(s.c_str()));
//	temp->l = reCreateTree();
//	temp->r = reCreateTree();
//	return temp;
//}
//
//int main()
//{
//	createTree(root);
//	getString(root);
//	newRoot = reCreateTree();
//	return 0;
//}
