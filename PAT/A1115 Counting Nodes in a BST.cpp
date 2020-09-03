////#include <iostream>
////#include <queue>
////#include <vector>
////using namespace std;
////struct Node
////{
////	int v;
////	Node *l, *r;
////	Node(int a = -1) :v(a), l(nullptr), r(nullptr) {}
////};
////Node* root = nullptr;
////int n, level = -1, a;
////vector<int>res;
////void creatTree(Node*& root, int x)
////{
////	if (root == nullptr)
////	{
////		root = new Node(x);
////		return;
////	}
////	if (x <= root->v)
////		creatTree(root->l, x);
////	else
////		creatTree(root->r, x);
////}
////void BFS(Node* root)
////{
////	queue<Node*>q;
////	q.push(root);
////	while (!q.empty())
////	{
////		int num = 0;
////		queue<Node*>temp;
////		while (!q.empty())
////		{
////			Node* p = q.front();
////			q.pop();
////			num++;
////			if (p->l != nullptr)
////				temp.push(p->l);
////			if (p->r != nullptr)
////				temp.push(p->r);
////		}
////		q = temp;
////		res.push_back(num);
////	}
////}
////int main()
////{
////
////	cin >> n;
////	while (n--)
////	{
////		cin >> a;
////		creatTree(root, a);
////	}
////	BFS(root);
////	cout << res[res.size() - 1] << " + " << res[res.size() - 2] << " = " << res[res.size() - 1] + res[res.size() - 2] << endl;
////	return 0;
////}
//#include <iostream>
//#include <vector>
//using namespace std;
//struct Node
//{
//	int val;
//	Node *r, *l;
//	Node(int v = 0) :val(v), r(nullptr), l(nullptr) {}
//};
//int n, maxLevel = -1, levelNum[1005] = { 0 };
//void insert(Node *&root, int x)
//{
//	if (root == nullptr)
//	{
//		root = new Node(x);
//		return;
//	}
//	if (x <= root->val)
//		insert(root->l, x);
//	else
//		insert(root->r, x);
//}
//void DFS(const Node *root, int level)
//{
//	if (root == nullptr)
//		return;
//	if (level > maxLevel)
//		maxLevel = level;
//	levelNum[level]++;
//	DFS(root->l, level + 1);
//	DFS(root->r, level + 1);
//}
//int main()
//{
//	cin >> n;	
//	Node *root = nullptr;
//	while (n--)
//	{
//		int a;
//		cin >> a;
//		insert(root, a);
//	}
//	DFS(root, 1);
//	printf("%d + %d = %d\n", levelNum[maxLevel], levelNum[maxLevel - 1], levelNum[maxLevel] + levelNum[maxLevel - 1]);
//	return 0;
//}