////#include <iostream>
////#include <vector>
////#include <string>
////using namespace std;
////struct node
////{
////	string str;
////	int l, r;
////}node[50];
////int n;
////string dfs(int root)
////{
////	if (node[root].l == -1 && node[root].r == -1)
////		return node[root].str;
////	if (node[root].l == -1 && node[root].r != -1)
////		return "(" + node[root].str + dfs(node[root].r)+")";
////	if (node[root].l != -1 && node[root].r != -1)
////		return "(" + dfs(node[root].l) + node[root].str + dfs(node[root].r) + ")";
////}
////int main()
////{
////	cin >> n;
////	int isroot[50] = { 0 }, root = 1;
////	for (int i = 1; i <= n; ++i)
////	{
////		cin >> node[i].str >> node[i].l >> node[i].r;
////		isroot[node[i].l == -1 ? 0 : node[i].l] = 1;
////		isroot[node[i].r == -1 ? 0 : node[i].r] = 1;
////	}
////	while (isroot[root] == 1)root++;//找出根节点，即根节点不是任何节点的孩子节点
////	string res = dfs(root);
////	if (res[0] == '(')res = res.substr(1, res.length() - 2);//去除最外面的一层括号
////	cout << res << endl;
////	return 0;
////}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//struct Node
//{
//	string val;
//	int l, r;
//};
//int n, root;
//vector<Node>v;
//string DFS(int root)
//{
//	if (v[root].l == -1 && v[root].r == -1)
//		return v[root].val;
//	else if (v[root].l == -1 && v[root].r != -1)
//		return "(" + v[root].val + DFS(v[root].r) + ")";
//	else if (v[root].l != -1 && v[root].r == -1)
//		return "(" + DFS(v[root].l) + v[root].val + ")";
//	else
//		return  "(" + DFS(v[root].l) + v[root].val + DFS(v[root].r) + ")";
//}
//int main()
//{
//	cin >> n;
//	v.resize(n + 1);
//	vector<bool>notRoot(n + 1, false);
//	char a;
//	int l, r;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> v[i].val >> v[i].l >> v[i].r;
//		notRoot[v[i].l == -1 ? 0 : v[i].l] = true;
//		notRoot[v[i].r == -1 ? 0 : v[i].r] = true;
//	}
//	for (int i = 1; i <= n; ++i)
//		if (notRoot[i] == false)
//			root = i;
//	string res = DFS(root);
//	if (res[0] == '(')
//	{
//		res.erase(0, 1);
//		res.erase(res.length() - 1, 1);
//	}
//	cout << res << endl;
//	return 0;
//}
//
//
