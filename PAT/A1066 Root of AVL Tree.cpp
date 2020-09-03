//////#include <iostream>
//////#include <algorithm>
//////using namespace std;
//////struct Node
//////{
//////	int val, h;
//////	Node *l, *r;
//////	Node(int a = 0) :val(a), h(1), l(nullptr), r(nullptr) {}
//////};
//////int N, num;
//////
//////int getH(Node* root)
//////{
//////	if (root == nullptr)
//////		return 0;
//////	return root->h;
//////}
//////
//////void updateH(Node*&root)
//////{
//////	root->h = max(getH(root->l), getH(root->r)) + 1;
//////}
//////
//////int getBalanceFactor(Node* root)
//////{
//////	return getH(root->l) - getH(root->r);
//////}
//////
////////左旋
//////void L(Node*&root)
//////{
//////	Node* temp = root->r;
//////	root->r = temp->l;
//////	temp->l = root;
//////	updateH(temp);
//////	updateH(root);
//////	root = temp;
//////}
////////右旋
//////void R(Node*&root)
//////{
//////	Node* temp = root->l;
//////	root->l = temp->r;
//////	temp->r = root;
//////	updateH(root);
//////	updateH(temp);
//////	root = temp;
//////}
//////void insert(Node*&root, int v)
//////{
//////	if (root == nullptr)
//////		root = new Node(v);
//////	else if (v < root->val)
//////	{
//////		insert(root->l, v);
//////		updateH(root);
//////		if (getBalanceFactor(root) == 2)
//////		{
//////			if (getBalanceFactor(root->l) == 1)//LL型
//////				R(root);
//////			else if(getBalanceFactor(root->l) == -1)//LR型
//////			{
//////				L(root->l);
//////				R(root);
//////			}
//////		}
//////	}
//////	else
//////	{
//////		insert(root->r, v);
//////		updateH(root);
//////		if (getBalanceFactor(root) == -2)
//////		{
//////			if (getBalanceFactor(root->r) == -1)//RR型
//////				L(root);
//////			else if (getBalanceFactor(root->r) == 1)//RL型
//////			{
//////				R(root->r);
//////				L(root);
//////			}
//////
//////		}
//////	}
//////}
//////
//////int main()
//////{
//////	cin >> N;
//////	Node* root = nullptr;
//////	for (int i = 0; i < N; ++i)
//////	{
//////		cin >> num;
//////		insert(root, num);
//////	}
//////	cout << root->val << endl;
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
////};
////int getHeight(Node *root)
////{
////	if (root == nullptr)
////		return 0;
////	return max(getHeight(root->l), getHeight(root->r)) + 1;
////}
////Node *rotateLeft(Node *root)
////{
////	Node* temp = root->r;
////	root->r = temp->l;
////	temp->l = root;
////	return temp;
////}
////Node *rotateRight(Node *root)
////{
////	Node *temp = root->l;
////	root->l = temp->r;
////	temp->r = root;
////	return temp;
////}
////Node *rotateLeftRight(Node *root)
////{
////	root->l = rotateLeft(root->l);
////	return rotateRight(root);
////}
////Node *rotateRightLeft(Node *root)
////{
////	root->r = rotateRight(root->r);
////	return rotateLeft(root);
////}
////Node *insert(Node *root, int val)
////{
////	if (root == nullptr)
////		root = new Node(val);
////	else if (val < root->val)
////	{
////		root->l = insert(root->l, val);
////		if (getHeight(root->l) - getHeight(root->r) == 2)//右旋
////			root = val < root->l->val ? rotateRight(root) : rotateLeftRight(root);
////	}
////	else
////	{
////		root->r = insert(root->r, val);
////		if (getHeight(root->r) - getHeight(root->l) == 2)
////			root = val > root->r->val ? rotateLeft(root) : rotateRightLeft(root);
////	}
////	return root;
////}
////int main()
////{
////	int n, number;
////	cin >> n;
////	Node* root = nullptr;
////	while (n--)
////	{
////		cin >> number;
////		root = insert(root, number);
////	}
////	cout << root->val << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
//};
//int n;
//Node *root = nullptr;
//int getLevel(Node *root)
//{
//	if (root == nullptr)
//		return 0;
//	return max(getLevel(root->l), getLevel(root->r)) + 1;
//}
//Node *rotateLeft(Node *root)
//{
//	Node *p = root->r;
//	root->r = p->l;
//	p->l = root;
//	return p;
//}
//Node *rotateRight(Node *root)
//{
//	Node *p = root->l;
//	root->l = p->r;
//	p->r = root;
//	return p;
//}
//Node *rotateLeftRight(Node *root)
//{
//	root->l = rotateLeft(root->l);
//	return rotateRight(root);
//}
//Node *rotateRightLeft(Node *root)
//{
//	root->r = rotateRight(root->r);
//	return rotateLeft(root);
//}
//Node *insert(Node *root,int x)
//{
//	if (root == nullptr)
//		root = new Node(x);
//	else if (x < root->val)
//	{
//		root->l = insert(root->l, x);
//		if (getLevel(root->l) - getLevel(root->r) == 2)
//			root = x < root->l->val ? rotateRight(root) : rotateLeftRight(root);
//	}
//	else
//	{
//		root->r = insert(root->r, x);
//		if (getLevel(root->r) - getLevel(root->l) == 2)
//			root = x >= root->r->val ? rotateLeft(root) : rotateRightLeft(root);
//	}
//	return root;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int x;
//		cin >> x;
//		root = insert(root, x);
//	}
//	cout << root->val;
//	return 0;
//}
