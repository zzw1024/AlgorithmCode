//////#include <iostream>
//////#include <vector>
//////using namespace std;
//////int n, a;
//////vector<int>preOrder, postOrder, inOrder;
//////bool flag = true;//表示树的形态不唯一
//////void getInOrder(int root, int left, int right)
//////{
//////	if (left >= right)
//////	{
//////		if (left == right)//只有一个节点
//////			inOrder.push_back(preOrder[root]);
//////		return;
//////	}
//////	int i = left;
//////	while (i < right && preOrder[root + 1] != postOrder[i])//查找前序遍历中下一个节点在后序中的位置
//////		++i;//root+1指的是根节点的下一个子节点
//////	if (i == right - 1)//先根序列中根节点的下一结点在后根序列中的位置正好等于right-1
//////		flag = false;//树的形态不唯一
//////	getInOrder(root + 1, left, i);//先左
//////	inOrder.push_back(preOrder[root]);//中
//////	getInOrder(root + i - left + 2, i + 1, right - 1);//后右
//////}
//////int main()
//////{
//////	cin >> n;
//////	for (int i = 0; i < n; ++i)
//////	{
//////		cin >> a;
//////		preOrder.push_back(a);
//////	}
//////	for (int i = 0; i < n; ++i)
//////	{
//////		cin >> a;
//////		postOrder.push_back(a);
//////	}
//////	getInOrder(0, 0, n - 1);
//////	cout << (flag ? "Yes" : "No") << endl;
//////	for (int i = 0; i < n; ++i)
//////		cout << (i > 0 ? " " : "") << inOrder[i];
//////	cout << endl;
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////using namespace std;
////int n;
////bool flag = true;
////vector<int>post, pre, in;
////void getInOrder(int root, int L, int R)
////{
////	if (L >= R)
////	{
////		if (L == R)
////			in.push_back(pre[root]);
////		return;
////	}
////	int i = L;
////	while (i < R && pre[root + 1] != post[i])++i;
////	if (i == R - 1)flag = false;
////	getInOrder(root + 1, L, i);
////	in.push_back(pre[root]);
////	getInOrder(root + i - L + 2, i + 1, R - 1);
////	
////}
////int main()
////{
////	cin >> n;
////	post.resize(n), pre.resize(n);
////	for (int i = 0; i < n; ++i)
////		cin >> pre[i];
////	for (int i = 0; i < n; ++i)
////		cin >> post[i];
////	getInOrder(0, 0, n - 1);
////	cout << (flag ? "Yes" : "No") << endl;
////	for (int i = 0; i < n; ++i)
////		cout << (i == 0 ? "" : " ") << in[i];
////	cout << endl;
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n;
//bool isOneTree = true;
//vector<int>pre, post, in;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
//};
//Node *createTree(int preL, int preR, int postL, int postR)//以pre为基准
//{
//	if (preL > preR)
//		return nullptr;
//
//	Node *root = new Node(pre[preL]);
//
//	if (preL == preR)
//		return root;//就一个点，无法找右子树,那就返回
//
//	int rightRoot = post[postR - 1];//记住，这个位置是右子树的根节点
//	int i = preL;
//	while (pre[i] != rightRoot && i <= preR)++i;
//	int leftN = i - preL - 1;//得到左子树的大小
//	int rightN = preR - i + 1;//得到右子树的大小
//	if (leftN == 0 || rightN == 0)
//		isOneTree = false;//出现了缺孩子现象，既可以给左孩子，又可以给右孩子，不唯一
//	root->l = createTree(preL + 1, i - 1, postL, postL + leftN - 1);
//	root->r = createTree(i, preR, postR - rightN, postR - 1);	
//	return root;
//}
//void inOrder(Node *root)
//{
//	if (root == nullptr)
//		return;
//	inOrder(root->l);
//	in.push_back(root->val);
//	inOrder(root->r);
//}
//int main()
//{
//	cin >> n;
//	pre.resize(n);
//	post.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> pre[i];
//	for (int i = 0; i < n; ++i)
//		cin >> post[i];
//	Node *root = createTree(0, n - 1, 0, n - 1);
//	inOrder(root);
//	if (isOneTree)
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//	for(int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << in[i];
//	cout << endl;
//	return 0;
//}
//
//
//

