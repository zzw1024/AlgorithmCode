//////这道题就是已知前序和中序遍历，得到后序遍历
//////push为前序遍历，pop为中序遍历
////#include <iostream>
////#include <vector>
////#include <stack>
////#include <string>
////using namespace std;
////int N;
////vector<int>preOrder, inOrder, posOrder;
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {};
////};
////Node* createTree(int preL, int preR, int inL, int inR)
////{
////	if (preL > preR)
////		return nullptr;
////	Node* root = new Node(preOrder[preL]);
////	int i;
////	for (i = inL; i <= inR; ++i)//找到根节点
////		if (inOrder[i] == preOrder[preL])		
////			break;
////	int num = i - inL;
////	root->l = createTree(preL + 1, preL + num, inL, i - 1);
////	root->r = createTree(preL + num + 1, preR, i + 1, inR);
////	return root;
////}
////void posOrderTree(Node *root)
////{
////	if (root == nullptr)
////		return;
////	posOrderTree(root->l);
////	posOrderTree(root->r);
////	posOrder.push_back(root->val);
////}
////int main()
////{
////
////	cin >> N;
////	string str;
////	stack<int>s;
////	int a;
////	for (int i = 0; i < 2*N; ++i)
////	{
////		cin >> str;
////		if (str == "Push")
////		{
////			cin >> a;
////			s.push(a);
////			preOrder.push_back(a);
////		}
////		else
////		{
////			inOrder.push_back(s.top());
////			s.pop();
////		}
////	}
////	Node* root = createTree(0, N - 1, 0, N - 1);
////	posOrderTree(root);
////	for (int i = 0; i < N; ++i)
////		cout << posOrder[i] << (i == N - 1 ? "" : " ");
////	return 0;
////}
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <string>
//using namespace std;
//int n;
//vector<int>pre, in, post;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int v = 0) :val(v), l(nullptr), r(nullptr) {}
//};
//Node *createTree(int inL, int inR, int preL, int preR)
//{
//	if (inL > inR)
//		return nullptr;
//	Node *root = new Node(pre[preL]);
//	int k = inL, m;
//	for (; k <= inR; ++k)
//		if (in[k] == pre[preL])
//			break;
//	m = k - inL;
//	root->l = createTree(inL, k - 1, preL + 1, preL + m);
//	root->r = createTree(k + 1, inR, preL + m + 1, preR);
//	return root;
//}
//void postOrder(Node *root)
//{
//	if (root == nullptr)
//		return;
//	postOrder(root->l);
//	postOrder(root->r);
//	post.push_back(root->val);
//}
//int main()
//{
//	cin >> n;
//	stack<int>s;
//	for (int i = 0; i < 2 * n; ++i)
//	{
//		string str;
//		int a;
//		cin >> str;
//		if (str == "Pop")
//		{
//			in.push_back(s.top());
//			s.pop();
//		}
//		else
//		{
//			cin >> a;
//			pre.push_back(a);
//			s.push(a);
//		}
//	}
//	Node *root = createTree(0, n - 1, 0, n - 1);
//	postOrder(root);
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << post[i];
//	return 0;
//}