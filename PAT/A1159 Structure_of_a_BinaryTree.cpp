//#include <iostream>
//#include <queue>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//struct Node
//{
//	int val;
//	Node *l, *r;
//	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
//};
//int n, m;
//bool isfullTree = true;
//vector<int>post, in, siblings(1010, -1), level(1010, -1);
//unordered_map<int, Node*>map;
//Node* creatTree(int inL, int inR, int postL, int postR)//重建二叉树
//{
//	if (inL > inR)
//		return nullptr;
//	Node *root = new Node(post[postR]);
//	map[root->val] = root;//记录节点对应的key值
//	int k = inL;
//	while (k <= inR && in[k] != post[postR])++k;
//	int nums = k - inL;
//	root->l = creatTree(inL, k - 1, postL, postL + nums - 1);
//	root->r = creatTree(k + 1, inR, postL + nums, postR - 1);
//	return root;
//}
//void DFS(Node *root, int L)
//{
//	if (root == nullptr)
//		return;
//	if ((root->l == nullptr && root->r) || (root->r == nullptr && root->l))
//		isfullTree = true;//不是完全二叉树
//	level[root->val] = L;//记录层数
//	if (root->l&& root->r)//记录姐妹节点
//	{
//		siblings[root->l->val] = root->r->val;
//		siblings[root->r->val] = root->l->val;
//	}
//	DFS(root->l, L + 1);
//	DFS(root->r, L + 1);
//}
//vector<int> getNumber(const string &str, bool isOneNumber)//获取数据
//{
//	vector<int>res;
//	int a = 0;
//	for (int i = 0; i < str.length(); ++i)
//	{
//		if (isdigit(str[i]))
//			a = a * 10 + str[i] - '0';
//		else if (a > 0)
//		{
//			res.push_back(a);
//			a = 0;
//			if (isOneNumber || res.size() == 2)//就输出一个字符就行
//				break;
//		}
//	}
//	if (!isOneNumber && res.size() < 2)//获取处于最后的数字
//		res.push_back(a);
//	return res;
//}
//int main()
//{
//	cin >> n;
//	post.resize(n);
//	in.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> post[i];
//	for (int i = 0; i < n; ++i)
//		cin >> in[i];
//	Node *root = creatTree(0, n - 1, 0, n - 1);
//	DFS(root, 1);//获取层数
//	cin >> m;
//	getchar();
//	while (m--)
//	{
//		string str;
//		getline(cin, str);
//		if (str.find("root", 0) != -1)//查询根节点
//		{
//			vector<int>res = getNumber(str, true);
//			if (root->val == res[0])
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else if (str.find("siblings", 0) != -1)//查询姐妹节点
//		{
//			vector<int>res = getNumber(str, false);			
//			if (siblings[res[0]] == res[1])
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else if (str.find("parent", 0) != -1)//查询父节点
//		{
//			vector<int>res = getNumber(str, false);
//			if ((map[res[0]]->l && map[res[0]]->l->val == res[1]) ||
//				(map[res[0]]->r && map[res[0]]->r->val == res[1]))
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else if (str.find("left", 0) != -1)//左节点
//		{
//			vector<int>res = getNumber(str, false);
//			if (map[res[1]]->l && map[res[1]]->l->val == res[0])
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else if (str.find("right", 0) != -1)//右节点
//		{
//			vector<int>res = getNumber(str, false);
//			if (map[res[1]]->r && map[res[1]]->r->val == res[0])
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else if (str.find("level", 0) != -1)//同样的深度
//		{
//			vector<int>res = getNumber(str, false);
//			if (level[res[0]]==level[res[1]])
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else if (str.find("full", 0) != -1)//是不是完整二叉树
//		{
//			if (isfullTree)
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<string>
//#include<cstring>
//#include<unordered_map>
//#include<unordered_set>
//using namespace std;
//const int maxn = 1005;
//const int INF = 0x3f3f3f3f;
//unordered_map<int, int> level, parents;
//struct node {
//	int data;
//	int layer;
//	node *lchild, *rchild;
//};
//vector<int> post, in;
//node* newNode(int data, int layer) {
//	node* root = new node;
//	root->data = data;
//	root->layer = layer;
//	level[data] = layer;
//	root->lchild = root->rchild = NULL;
//	return root;
//}
//bool flag = true;
//node* create(int parent, int postLeft, int postRight, int inLeft, int inRight, int layer) {
//	if (postLeft > postRight) return NULL;
//	node* root = newNode(post[postRight], layer);
//	parents[root->data] = parent;
//	int index = inLeft;
//	while (in[index] != root->data) index++;
//	int numLeft = index - inLeft;
//	root->lchild = create(root->data, postLeft, postLeft + numLeft - 1, inLeft, index - 1, layer + 1);
//	root->rchild = create(root->data, postLeft + numLeft, postRight - 1, index + 1, inRight, layer + 1);
//	//如果有叶子，就必须有两片叶子
//	if ((root->lchild || root->rchild) && (!root->lchild || !root->rchild)) flag = false;
//	return root;
//}
//int main() {
//	int n, m;
//	unordered_map<int, int> ppos, ipos;
//	scanf("%d", &n);
//	post.resize(n);
//	in.resize(n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &post[i]);
//		ppos[post[i]] = i;
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &in[i]);
//		ipos[in[i]] = i;
//	}
//	node* root = create(n - 1, 0, n - 1, 0, n - 1, 0);
//	scanf("%d\n", &m);
//	string ask;
//	for (int i = 0; i < m; i++) {
//		getline(cin, ask);
//		int num1 = 0, num2 = 0;
//		if (ask.find("root") != string::npos) {
//			sscanf(ask.c_str(), "%d is the root", &num1);
//			if (ppos[num1] == n - 1) puts("Yes");
//			else puts("No");
//		}
//		else if (ask.find("siblings") != string::npos) {
//			sscanf(ask.c_str(), "%d and %d are siblings", &num1, &num2);
//			if (level[num1] == level[num2] && parents[num1] == parents[num2]) puts("Yes");
//			else puts("No");
//		}
//		else if (ask.find("parent") != string::npos) {
//			sscanf(ask.c_str(), "%d is the parent of %d", &num1, &num2);
//			if (parents[num2] == num1) puts("Yes");
//			else puts("No");
//		}
//		else if (ask.find("left") != string::npos) {
//			sscanf(ask.c_str(), "%d is the left child of %d", &num1, &num2);
//			if (parents[num1] == num2 && ipos[num1] < ipos[num2]) puts("Yes");
//			else puts("No");
//		}
//		else if (ask.find("right") != string::npos) {
//			sscanf(ask.c_str(), "%d is the right child of %d", &num1, &num2);
//			if (parents[num1] == num2 && ipos[num1] > ipos[num2]) puts("Yes");
//			else puts("No");
//		}
//		else if (ask.find("same") != string::npos) {
//			sscanf(ask.c_str(), "%d and %d are on the same level", &num1, &num2);
//			if (level[num1] == level[num2]) puts("Yes");
//			else puts("No");
//		}
//		else if (ask.find("full") != string::npos) {
//			if (flag) puts("Yes");
//			else puts("No");
//		}
//	}
//	return 0;
//}