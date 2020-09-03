//////原来的 是左到右，现在右到左就行
////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////struct Node
////{
////	int l, r;
////};
////int N, root[15] = { 0 };
////Node tree[15];
////vector<int>lev, in;
////void levelOrde(int t)
////{
////	if (t == -1)
////		return;
////	queue<int>q;
////	q.push(t);
////	while (!q.empty())
////	{
////		t = q.front();
////		q.pop();
////		lev.push_back(t);
////		if (tree[t].r != -1)//先进右
////			q.push(tree[t].r);
////		if (tree[t].l != -1)
////			q.push(tree[t].l);
////	}
////}
////void inOrder(int t)
////{
////	if (t == -1)
////		return;
////	inOrder(tree[t].r);
////	in.push_back(t);
////	inOrder(tree[t].l);
////}
////int main()
////{
////	cin >> N;
////	char l, r;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> l >> r;
////		if (l != '-')
////		{
////			tree[i].l = l - '0';
////			root[l - '0'] = -1;//去除为根的可能性
////		}
////		else
////			tree[i].l = -1;
////		if (r != '-')
////		{
////			tree[i].r = r - '0';
////			root[r - '0'] = -1;//去除为根的可能性
////		}
////		else
////			tree[i].r = -1;
////	}
////	for (int i = 0; i < N; ++i)
////	{
////		if (root[i] == 0)
////		{
////			r = i;
////			break;//找到了根节点
////		}
////	}
////	levelOrde(r);
////	inOrder(r);
////	for (int i = 0; i < N; ++i)
////		cout << lev[i] << (i == N - 1 ? "" : " ");
////	cout << endl;
////	for (int i = 0; i < N; ++i)
////		cout << in[i] << (i == N - 1 ? "" : " ");
////	return 0;
////}
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int n;
//vector<pair<int, int>>v;
//vector<int>level, in;
//void levelOrder(int root)
//{
//	if (root == -1)
//		return;
//	queue<int>q;
//	q.push(root);
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		level.push_back(p);
//		if (v[p].first != -1)
//			q.push(v[p].first);
//		if (v[p].second != -1)
//			q.push(v[p].second);
//	}
//}
//void inOrder(int root)
//{
//	if (root == -1)
//		return;
//	inOrder(v[root].first);
//	in.push_back(root);
//	inOrder(v[root].second);
//}
//int main()
//{
//	cin >> n;
//	bool notHead[15] = { false };
//	for (int i = 0; i < n; ++i)
//	{
//		char a, b;
//		cin >> a >> b;
//		v.push_back(make_pair((b == '-' ? -1 : b - '0'), (a == '-' ? -1 : a - '0')));//反着存
//		if (a != '-')
//			notHead[a - '0'] = true;
//		if (b != '-')
//			notHead[b - '0'] = true;
//	}
//	int root;
//	for (int i = 0; i < n; ++i)
//		if (notHead[i] == false)
//			root = i;
//	levelOrder(root);
//	inOrder(root);
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << level[i];
//	cout << endl;
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << in[i];
//	return 0;
//}