////分析：这道题考察AVL树和层序遍历以及完全二叉树
////判断是不是完全⼆叉树，就看在出现了⼀个孩⼦为空的结点之后是否还会出现孩⼦结点不为空的结
////点，如果出现了就不是完全⼆叉树。
////AVL树⼀共有四种情况，这⾥我把发现树不平衡的那个结点叫做A结点，A发现树不平衡的情况有四
////种：
////新来的结点插⼊到A的左⼦树的左⼦树
////新来的结点插⼊到A的左⼦树的右⼦树
////新来的结点插⼊到A的右⼦树的左⼦树
////新来的结点插⼊到A的右⼦树的右⼦树
////发现不平衡时就需要处理，第1种情况只要简单的右旋，第4种情况只需左旋⼀下，
////第2种情况需要先对A的左⼦树左旋⼀下，然后对A右旋，同理第3种情况需要对A的右⼦树右旋⼀下，然后对A左旋
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
////int n, a;
////vector<int>res;
////int getHeight(Node* root)
////{
////	if (root == nullptr)
////		return 0;
////	return max(getHeight(root->l), getHeight(root->r))+1;
////}
////Node* rotateRight(Node* root)//右旋
////{
////	Node*p = root->l;
////	root->l = p->r;
////	p->r = root;
////	return p;//新的根节点
////}
////Node* rotateLeft(Node* root)//左旋
////{
////	Node*p = root->r;
////	root->r = p->l;
////	p->l = root;
////	return p;//新的根节点
////}
////Node* rotateLeftRight(Node* root)//左右旋
////{
////	root->l = rotateLeft(root->l);//先左旋
////	return rotateRight(root);//再右旋
////}
////Node* rotateRightLeft(Node* root)//右左旋
////{
////	root->r = rotateRight(root->r);//先右旋
////	return rotateLeft(root);//再左旋
////}
////Node* Insert(Node* root, int x)
////{
////	if (root == nullptr)
////	{
////		root = new Node(x);
////		return root;
////	}
////	if (x < root->v)
////	{
////		root->l = Insert(root->l, x);
////		if (getHeight(root->l) - getHeight(root->r) >= 2)
////			root = x < root->l->v ? rotateRight(root) : rotateLeftRight(root);
////	}
////	else
////	{
////		root->r = Insert(root->r, x);
////		if (getHeight(root->r) - getHeight(root->l) >= 2)
////			root = x > root->r->v ? rotateLeft(root) : rotateRightLeft(root);
////	}
////	return root;
////}
////bool LevelOrder(Node* root)
////{
////	bool flag = true;//是不是完全二叉树
////	if (root == nullptr)
////		return flag;
////	queue<Node*>q, temp;
////	q.push(root);
////	while (!q.empty())
////	{
////		Node*p = q.front();
////		q.pop();
////		temp.push(p);
////		res.push_back(p->v);
////		if (p->l != nullptr)
////			q.push(p->l);
////		else if (temp.size() + q.size() != n)//中间出现空节点，不是完全二叉树
////			flag = false;
////		if (p->r != nullptr)
////			q.push(p->r);
////		else if (temp.size() + q.size() != n)//中间出现空节点，不是完全二叉树
////			flag = false;
////	}
////	return flag;
////}
////int main()
////{
////	cin >> n;
////	Node* root = nullptr;
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> a;
////		root = Insert(root, a);
////	}
////	bool flag = LevelOrder(root);
////	for (int i = 0; i < res.size(); ++i)
////		cout << (i > 0 ? " " : "") << res[i];
////	if (flag)
////		cout << endl << "YES" << endl;
////	else
////		cout << endl << "NO" << endl;
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int v = 0) :val(v), l(nullptr), r(nullptr) {}
//};
//int n;
//Node *root;
//vector<int>level;
//int getHeight(Node *root)
//{
//	if (root == nullptr)
//		return 0;
//	return max(getHeight(root->l), getHeight(root->r)) + 1;
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
//Node *insert(Node *root, int val)
//{
//	if (root == nullptr)
//		root = new Node(val);
//	else if (val < root->val)
//	{
//		root->l = insert(root->l, val);
//		if (getHeight(root->l) - getHeight(root->r) == 2)
//			root = val < root->l->val ? rotateRight(root) : rotateLeftRight(root);
//	}
//	else
//	{
//		root->r = insert(root->r, val);
//		if (getHeight(root->r) - getHeight(root->l) == 2)
//			root = val >= root->r->val ? rotateLeft(root) : rotateRightLeft(root);
//	}
//	return root;
//}
//bool BFS(Node *root)
//{
//	if (root == nullptr)
//		return 0;
//	queue<Node*>q;
//	q.push(root);
//	int nums = 0;
//	bool flag = true;
//	while (!q.empty())
//	{
//		Node *p = q.front();
//		q.pop();
//		nums++;
//		level.push_back(p->val);
//		if (p->l != nullptr)
//			q.push(p->l);
//		else
//		{
//			if (nums + q.size() != n)
//				flag = false;
//		}
//		if (p->r != nullptr)
//			q.push(p->r);
//		else
//		{
//			if (nums + q.size() != n)
//				flag = false;
//		}
//	}
//	return flag;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> a;
//		root = insert(root, a);
//	}
//	bool flag = BFS(root);
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << level[i];
//	cout << endl << (flag ? "YES" : "NO") << endl;
//	return 0;	
//}