//////#include <iostream>
//////#include <vector>
//////#include <cmath>
//////#include <algorithm>
//////using namespace std;
//////struct Node
//////{
//////	int val;
//////	Node *l, *r;
//////	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
//////};
//////Node* createTree(int inL, int inR, int preL, int preR, vector<int>&inOrder, vector<int>&preOrder)
//////{//根据前序和中序遍历构造二叉树
//////	if (preL > preR)
//////		return nullptr;
//////	int value = preOrder[preL];
//////	Node* root = new Node(value);
//////	int i = inL;
//////	while (i <= inR && inOrder[i] != value)++i;
//////	int nums = i - inL;
//////	root->l = createTree(inL, i - 1, preL + 1, preL + nums, inOrder, preOrder);
//////	root->r = createTree(i + 1, inR, preL + nums + 1, preR, inOrder, preOrder);
//////	return root;
//////}
//////bool judge1(Node* root)//判断红节点的孩子是否都是黑节点
//////{
//////	if (root == nullptr)
//////		return true;
//////	if (root->val < 0 && ((root->l != nullptr && root->l->val < 0) || (root->r != nullptr && root->r->val < 0)))//红节点存在红节点的孩子
//////		return false;
//////	return 	judge1(root->l) && judge1(root->r);
//////}
//////int getNum(Node* root)
//////{
//////	if (root == nullptr)
//////		return 0;
//////	int l = getNum(root->l);
//////	int r = getNum(root->r);
//////	return root->val > 0 ? max(l, r) + 1 : max(l, r);//计算黑节点的个数
//////}
//////bool judge2(Node* root)
//////{
//////	if (root == nullptr)
//////		return true;
//////	int l = getNum(root->l);
//////	int r = getNum(root->r);
//////	if (l != r)
//////		return false;
//////	return judge2(root->l) && judge2(root->r);
//////}
//////int main()
//////{
//////	int n, k;
//////	cin >> k;
//////	while (k--)
//////	{
//////		cin >> n;
//////		vector<int>preOrder(n), inOrder;
//////		for (int i = 0; i < n; ++i)
//////			cin >> preOrder[i];
//////		inOrder = preOrder;
//////		sort(inOrder.begin(), inOrder.end(), [](int a, int b) {return abs(a) < abs(b); });
//////		Node* root = createTree(0, n - 1, 0, n - 1, inOrder, preOrder);
//////		if (root != nullptr&& root->val < 0  || !judge1(root) || !judge2(root))//根节点必须是红节点
//////			cout << "No" << endl;
//////		else
//////			cout << "Yes" << endl;
//////	}
//////	return 0;
//////}
////#include <iostream>
////#include <vector>
////#include <cmath>
////#include <queue>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int v = 0) :val(v), l(nullptr), r(nullptr) {}
////};
////int n, m;
////bool flag;
////vector<int>pre, in;
////Node *createTree(int inL, int inR, int preL, int preR)
////{
////	if (inL > inR)
////		return nullptr;
////	Node *root = new Node(pre[preL]);
////	int k = inL;
////	while (k <= inR && in[k] != pre[preL])k++;
////	int m = k - inL;
////	root->l = createTree(inL, k - 1, preL + 1, preL + m);
////	root->r = createTree(k + 1, inR, preL + m + 1, preR);
////	return root;
////}
////bool isBlackChild(Node *root)
////{
////	if (root == nullptr)
////		return true;
////	if (root->val < 0 && (root->l != nullptr && root->l->val < 0 || root->r != nullptr && root->r->val < 0))
////		return false;
////	return isBlackChild(root->l) && isBlackChild(root->r);
////}
////int getBlackNode(Node *root)
////{
////	if (root == nullptr)
////		return 0;
////	int ln = getBlackNode(root->l);
////	int rn = getBlackNode(root->r);
////	return root->val > 0 ? max(ln, rn) + 1 : max(ln, rn);
////}
////bool equBlackNode(Node *root)
////{
////	if (root == nullptr)
////		return true;
////	if (getBlackNode(root->l) != getBlackNode(root->r))
////		return false;
////	return equBlackNode(root->l) && equBlackNode(root->r);
////}
////int main()
////{
////	cin >> n;
////	while (n--)
////	{
////		cin >> m;
////		pre.resize(m);
////		for (int i = 0; i < m; ++i)
////			cin >> pre[i];
////		in = pre;
////		sort(in.begin(), in.end(), [](int a, int b) {return abs(a) < abs(b); });
////		Node *root = createTree(0, m - 1, 0, m - 1);	
////		if (root!=nullptr && root->val<0 || !equBlackNode(root)||!isBlackChild(root))
////			cout << "No"  << endl;
////		else
////			cout << "Yes" << endl;
////	}
////	return 0;
////}
//
////
////#include <iostream>
////#include <vector>
////#include <cmath>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a) :val(a), l(nullptr), r(nullptr) {}
////};
////int n, m;
////int getHigh(Node *root)//是指黑节点个数哦
////{
////	if (root == nullptr)
////		return 0;
////	int ln = getHigh(root->l);
////	int rn = getHigh(root->r);
////	return root->val > 0 ? max(ln, rn) + 1 : max(ln, rn);//计算黑节点个数
////}
////Node *Insert(Node *root, int x)
////{
////	if (root == nullptr)
////		root = new Node(x);
////	else if (abs(x) < abs(root->val))
////		root->l = Insert(root->l, x);
////	else
////		root->r = Insert(root->r, x);
////	return root;
////}
////bool redNode(Node *root)
////{
////	if (root == nullptr)
////		return true;
////	if (root->val < 0)//红节点孩子一定要是黑节点
////		if (root->l != nullptr && root->l->val < 0 ||
////			root->r != nullptr && root->r->val < 0)
////			return false;
////	return redNode(root->l) && redNode(root->r);
////}
////bool balanceTree(Node *root)
////{
////	if (root == nullptr)		return true;
////	if (getHigh(root->l) != getHigh(root->r))return false;//黑节点个数不同
////	return balanceTree(root->l) && balanceTree(root->r);
////}
////int main()
////{
////	int n, m;
////	cin >> n;
////	while (n--)
////	{
////		cin >> m;
////		vector<int>v(m);
////		Node *root = nullptr;
////		for (int i = 0; i < m; ++i)
////		{
////			cin >> v[i];
////			root = Insert(root, v[i]);
////		}
////		if (v[0] >= 0 && balanceTree(root) && redNode(root))
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////}
////
////#include <iostream>
////#include <vector>
////#include <cmath>
////#include <queue>
////#include <deque>
////#include <unordered_map>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a) :val(a), l(nullptr), r(nullptr) {}
////};
////int n, m;
////bool isRedBlackTree = true;
////unordered_map<int, bool>isFu;
////unordered_map<Node*, int>balckNums;
////Node *Insert(Node *root, int x)
////{
////	if (root == nullptr)
////	{
////		root = new Node(x);
////		balckNums[root] = isFu[x] == true ? 0 : 1;//计算黑节点个数
////	}
////	else if (x <= root->val)
////		root->l = Insert(root->l, x);
////	else
////		root->r = Insert(root->r, x);
////	return root;
////}
////int main()
////{
////	cin >> n;
////	while (n--)
////	{
////		cin >> m;
////		vector<int>v(m);
////		isRedBlackTree = true;
////		isFu.clear();
////		Node *root = nullptr;
////		for (int i = 0; i < m; ++i)
////		{
////			int x;
////			cin >> x;
////			if (x < 0)
////				isFu[abs(x)] = true;
////			v[i] = abs(x);
////			root = Insert(root, v[i]);
////		}
////		if (isFu[v[0]] == true)//根节点一定是黑的
////			isRedBlackTree = false;
////		queue<Node *>q;
////		deque<Node *>temp;
////		q.push(root);
////		while (!q.empty() && isRedBlackTree)
////		{
////			Node *p = q.front();
////			if(isFu[p->val]==true)
////				if (p->l != nullptr && isFu[p->l->val] == true ||
////					p->r != nullptr && isFu[p->r->val] == true)
////					isRedBlackTree = false;
////			temp.push_back(p);
////			q.pop();
////			if (p->l)q.push(p->l);
////			if (p->r)q.push(p->r);
////		}
////		while (!temp.empty() && isRedBlackTree)
////		{
////			Node *p = temp.back();
////			temp.pop_back();
////			int lN = p->l == nullptr ? 0 : balckNums[p->l];//计算黑节点个数
////			int rN = p->r == nullptr ? 0 : balckNums[p->r]; // 计算黑节点个数
////			if (lN != rN)
////				isRedBlackTree = false;
////			balckNums[p] += lN + rN;
////		}
////		if (isRedBlackTree)
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////}
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int n, m;
//bool isRedBlackTree;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
//};
//Node *Insert(Node *root,int x)
//{
//	if (root == nullptr)
//		root = new Node(x);
//	else if (abs(x) < abs(root->val))
//		root->l = Insert(root->l, x);
//	else
//		root->r = Insert(root->r, x);
//	return root;
//}
//int getBlackNode(Node *root)
//{
//	if (root == nullptr)
//		return 0;
//	int nums = max(getBlackNode(root->l), getBlackNode(root->r));
//	return root->val < 0 ? nums : nums + 1;
//}
//void DFS(Node *root)
//{
//	if (root == nullptr || isRedBlackTree == false)
//		return;
//	if (getBlackNode(root->l) != getBlackNode(root->r))
//		isRedBlackTree = false;
//	if (root->val < 0)
//		if (root->l != nullptr && root->l->val < 0 ||
//			root->r != nullptr && root->r->val < 0)
//			isRedBlackTree = false;
//	DFS(root->l);
//	DFS(root->r);
//}
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		cin >> m;
//		vector<int>v(m);
//		Node *root = nullptr;
//		isRedBlackTree = true;
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> v[i];
//			root = Insert(root, v[i]);
//		}
//		DFS(root);
//		if (v[0] >= 0 && isRedBlackTree)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}