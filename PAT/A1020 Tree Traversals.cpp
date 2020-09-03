////#include <iostream>
////#include <queue>
////using namespace std;
//////已知后序遍历和中序遍历输出层序遍历
////int *pos, *ord;//存放后序和中序遍历数据
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
////};
////Node*  createTree(int posL,int posR, int ordL, int ordR)
////{
////	if (posL > posR)
////		return nullptr;
////	Node *root = new Node();
////	root->val = pos[posR];//根节点值
////	int k;
////	for (k = ordL; k <= ordR; ++k)
////	{
////		if (ord[k] == pos[posR])//找到原树的根
////			break;
////	}
////	int numL = k - ordL;//左子树节点数量
////	//递归构造左子树
////	root->l = createTree(posL, posL + numL - 1, ordL, k - 1);
////	//递归构造右子树
////	root->r = createTree(posL + numL, posR - 1, k + 1, ordR);//取出根节点
////	return root;
////}
////void getResBFS(Node* root)
////{
////	queue<Node*>q;
////	Node* p = nullptr;
////	q.push(root);
////	cout << root->val;
////	while (!q.empty())
////	{
////		p = q.front();
////		if (p != root)
////			cout << " " << p->val;
////		q.pop();
////		if (p->l != nullptr)
////			q.push(p->l);
////		if (p->r != nullptr)
////			q.push(p->r);
////	}
////	cout << endl;
////}
////
////int main()
////{
////	int N;
////	cin >> N;
////	pos = new int[N];
////	ord = new int[N];
////	for (int i = 0; i < N; ++i)
////		cin >> pos[i];
////	for (int i = 0; i < N; ++i)
////		cin >> ord[i];
////	Node* root = createTree(0, N - 1, 0, N - 1);
////	getResBFS(root);
////	return 0;	
////}
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct Node
//{
//	int v;
//	Node *l, *r;
//	Node(int a = -1) :v(a), l(nullptr), r(nullptr) {}
//};
//vector<int>pos, in, level;
//int n;
//Node* reCreateTree(int inL, int inR, int posL, int posR)
//{
//	if (inL > inR)
//		return nullptr;
//	Node* root = new Node(pos[posR]);
//	int k, m;
//	for (int i = inL; i <= inR; ++i)
//	{
//		if (in[i] == pos[posR])
//		{
//			k = i;
//			break;
//		}
//	}
//	m = k - inL;
//	root->l = reCreateTree(inL, k - 1, posL, posL + m - 1);
//	root->r = reCreateTree(k + 1, inR, posL + m, posR - 1);
//	return root;
//}
//void levelOrder(Node* root)
//{
//	if (root == nullptr)
//		return;
//	queue<Node*>q;
//	q.push(root);
//	while (!q.empty())
//	{
//		Node* p = q.front();
//		q.pop();
//		level.push_back(p->v);
//		if (p->l != nullptr)
//			q.push(p->l);
//		if (p->r != nullptr)
//			q.push(p->r);
//	}
//}
//int main()
//{
//	cin >> n;
//	pos.resize(n);
//	in.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> pos[i];
//	for (int i = 0; i < n; ++i)
//		cin >> in[i];
//	Node* root = reCreateTree(0, n - 1, 0, n - 1);
//	levelOrder(root);
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << level[i];
//	return 0;
//}
