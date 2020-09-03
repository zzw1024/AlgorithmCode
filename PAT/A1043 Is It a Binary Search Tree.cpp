////#include <iostream>
////#include <vector>
////using namespace std;
//////通过前序遍历构造二叉树，然后进行判断
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a = -1) :val(a), l(nullptr), r(nullptr) {}
////};
////void insert(Node*& root, int val)
////{
////	if (root == nullptr)
////		root = new Node(val);
////	else if (val < root->val)
////		insert(root->l, val);
////	else
////		insert(root->r, val);
////}
////void preOrder(Node* root, vector<int>& pre)
////{
////	if (root == nullptr)return;
////	pre.push_back(root->val);
////	preOrder(root->l, pre);
////	preOrder(root->r, pre);
////}
////void preOrderMirror(Node* root, vector<int>& preM)
////{
////	if (root == nullptr)return;
////	preM.push_back(root->val);
////	preOrderMirror(root->r, preM);
////	preOrderMirror(root->l, preM);
////}
////void postOrder(Node* root, vector<int>& post)
////{
////	if (root == nullptr)return;
////	postOrder(root->l, post);
////	postOrder(root->r, post);
////	post.push_back(root->val);
////}
////void postOrderMirror(Node* root, vector<int>& postM)
////{
////	if (root == nullptr)return;
////	postOrderMirror(root->r, postM);
////	postOrderMirror(root->l, postM);
////	postM.push_back(root->val);
////}
////int main()
////{
////	int N;
////	cin >> N;
////	Node* root = nullptr;
////	vector<int>v(N), pre, preM, post, postM;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> v[i];
////		insert(root, v[i]);//按照BST进行树的创建
////	}
////	preOrder(root, pre);
////	preOrderMirror(root, preM);
////	postOrder(root, post);
////	postOrderMirror(root, postM);
////	if (v == pre)//非镜像
////	{
////		cout << "Yes" << endl;
////		for (int i = 0; i < post.size(); ++i)
////		{
////			cout << post[i];
////			if (i < (post.size() - 1))
////				cout << " ";
////		}
////	}
////	else if (v == preM)//镜像
////	{
////		cout << "Yes" << endl;
////		for (int i = 0; i < postM.size(); ++i)
////		{
////			cout << postM[i];
////			if (i < (postM.size() - 1))
////				cout << " ";
////		}
////	}
////	else
////		cout << "No" << endl;
////	return 0;	
////}
////
////
////#include<bits/stdc++.h>
////using namespace std;
////vector<int>post, pre(1005);
////bool mirror = false;//是否是镜像树
////void postOrder(int left, int right) {
////	if (left > right)
////		return;
////	int i = left + 1, j = right;//i指示右子树的第一个数在先根遍历序列中的索引，j指示左子树的最后一个数在先根遍历序列中的索引
////	if (!mirror) {
////		while (i <= right && pre[left] > pre[i])
////			++i;
////		while (j > left&&pre[left] <= pre[j])
////			--j;
////	}
////	else {
////		while (i <= right && pre[left] <= pre[i])
////			++i;
////		while (j > left&&pre[left] > pre[j])
////			--j;
////	}
////	if (i - j != 1) return;//i-j!=1，说明不能构成二叉查找树或镜像树，提前返回
////	postOrder(left + 1, i - 1);//处理左子树
////	postOrder(i, right);//处理右子树
////	post.push_back(pre[left]);//将根节点加入后根遍历序列中
////}
////int main() {
////	int N;
////	scanf("%d", &N);
////	for (int i = 0; i < N; ++i)
////		scanf("%d", &pre[i]);
////	if (N > 2 && pre[1] > pre[0])//判断是否是镜像树
////		mirror = true;
////	postOrder(0, N - 1);//得出后根遍历序列
////	if (post.size() == N) {//得出的后根遍历序列中元素个数与给定的元素总数相等，说明能构成二叉查找树或镜像树
////		printf("YES\n");
////		for (int i = 0; i < post.size(); ++i)
////			printf("%s%d", i > 0 ? " " : "", post[i]);
////	}
////	else//得出的后根遍历序列中元素个数与给定的元素总数相等，说明不能构成二叉查找树或镜像树
////		printf("NO");
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int>preV, preTreeV, preMirrorV, postOrder;
//int n;
//struct Node
//{
//	int v;
//	Node *l, *r;
//	Node(int a = 0) :v(a), l(nullptr), r(nullptr) {}
//};
//void createTree(Node *&root, int x)
//{
//	if (root == nullptr)
//		root = new Node(x);
//	else if (x < root->v)
//		createTree(root->l, x);
//	else
//		createTree(root->r, x);
//}
//void createMirrorTree(Node *&root, int x)
//{
//	if (root == nullptr)
//		root = new Node(x);
//	else if (x < root->v)
//		createMirrorTree(root->r, x);
//	else
//		createMirrorTree(root->l, x);
//}
//void getTreePreOrder(const Node *root)
//{
//	if (root == nullptr)
//		return;
//	preTreeV.push_back(root->v);
//	getTreePreOrder(root->l);
//	getTreePreOrder(root->r);
//}
//void getMirrorPreOrder(const Node *root)
//{
//	if (root == nullptr)
//		return;
//	preMirrorV.push_back(root->v);
//	getMirrorPreOrder(root->l);
//	getMirrorPreOrder(root->r);
//}
//void getPostOrder(const Node *root)
//{
//	if (root == nullptr)
//		return;
//	getPostOrder(root->l);
//	getPostOrder(root->r);
//	postOrder.push_back(root->v);
//}
//bool isEqu(const vector<int>&v1, vector<int>&v2)
//{
//	for (int i = 0; i < n; ++i)
//		if (v1[i] != v2[i])
//			return false;
//	return true;
//}
//int main()
//{
//	cin >> n;
//	preV.resize(n);
//	Node *BSTTree = nullptr, *MirrorTree = nullptr;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> preV[i];
//		createTree(BSTTree, preV[i]);
//		createMirrorTree(MirrorTree, preV[i]);
//	}
//	getTreePreOrder(BSTTree);
//	getMirrorPreOrder(MirrorTree);
//	if (isEqu(preV, preTreeV) == false && isEqu(preV, preMirrorV) == false)
//	{
//		cout << "NO" << endl;
//		return 0;
//	}
//	else if (isEqu(preV, preTreeV) == true)
//		getPostOrder(BSTTree);
//	else
//		getPostOrder(MirrorTree);
//	cout << "YES" << endl;
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << postOrder[i];
//	return 0;
//}