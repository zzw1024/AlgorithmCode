////#include <iostream>
////#include <vector>
////#include <queue>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int v;
////	Node *l, *r;
////	Node(int a = -1) :v(a), l(nullptr), r(nullptr) {}
////};
////int n;
////vector<int>inOrder, posOrder, zigOrder;
////Node* reCreatTree(int inL, int inR, int posL, int posR)
////{
////	if (posL > posR)
////		return nullptr;
////	Node* root = new Node(posOrder[posR]);
////	int k = inL;
////	while (k<=inR && inOrder[k] != posOrder[posR])++k;//找到根节点
////	int numL = k - inL;//左子树节点个数
////	root->l = reCreatTree(inL, k - 1, posL, posL + numL - 1);
////	root->r = reCreatTree(k + 1, inR, posL + numL, posR - 1);
////	return root;
////}
////void zigOrderTravel(Node* root)
////{
////	if (root == nullptr)
////		return;
////	queue<Node*>q;
////	q.push(root);
////	zigOrder.push_back(root->v);
////	bool flag = false;
////	while (!q.empty())
////	{
////		queue<Node*>temp;
////		vector<int>tt;
////		while (!q.empty())
////		{
////			Node* p = q.front();
////			q.pop();
////			if (p->l != nullptr)
////			{
////				temp.push(p->l);
////				tt.push_back(p->l->v);
////			}
////			if (p->r != nullptr)
////			{
////				temp.push(p->r);
////				tt.push_back(p->r->v);
////			}
////		}
////		if (flag)
////			reverse(tt.begin(), tt.end());
////		zigOrder.insert(zigOrder.end(), tt.begin(), tt.end());
////		flag = !flag;
////		q = temp;
////	}
////}
////int main()
////{
////	cin >> n;
////	inOrder.resize(n);
////	posOrder.resize(n);
////	for (int i = 0; i < n; ++i)
////		cin >> inOrder[i];
////	for (int i = 0; i < n; ++i)
////		cin >> posOrder[i];
////	Node* root = reCreatTree(0, n - 1, 0, n - 1);
////	zigOrderTravel(root);
////	for (int i = 0; i < zigOrder.size(); ++i)
////		cout << (i > 0 ? " " : "") << zigOrder[i];
////	return 0;
////}
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int v = 0) :val(v), l(nullptr), r(nullptr) {}
//};
//int n;
//vector<int>in,post, res;
//vector<vector<int>>levelRes;
//Node *createTree(int inL, int inR, int postL, int postR)
//{
//	if (inL > inR)
//		return nullptr;
//	Node *root = new Node(post[postR]);
//	int k = inL;
//	while (inL <= inR && in[k] != post[postR])k++;
//	int m = k - inL;
//	root->l = createTree(inL, k - 1, postL, postL + m - 1);
//	root->r = createTree(k + 1, inR, postL + m, postR - 1);
//	return root;
//}
//void DFS(Node *root, int level)
//{
//	if (root == nullptr)
//		return;
//	levelRes[level].push_back(root->val);
//	DFS(root->l, level + 1);
//	DFS(root->r, level + 1);
//}
//int main()
//{
//	cin >> n;
//	in.resize(n);
//	post.resize(n);
//	levelRes.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> in[i];
//	for (int i = 0; i < n; ++i)
//		cin >> post[i];
//	Node *root = createTree(0, n - 1, 0, n - 1);
//	DFS(root, 0);
//	cout << root->val;
//	for (int i = 1; i < levelRes.size() && levelRes[i].size() > 0; ++i)
//		if (i % 2 == 0)
//			for (int j = levelRes[i].size() - 1; j >= 0; --j)
//				cout << " " << levelRes[i][j];
//		else
//			for (auto a : levelRes[i])
//				cout << " " << a;
//	return 0;
//}
//
