//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int n, head = -1;
//struct Node
//{
//	string val;
//	int l, r;
//}nodes[25];
//string DFS(int root)
//{
//	if (root == -1)	return "";
//	if (nodes[root].l == -1)//记住，只允许左子树为空，不能右子树为空，不然就不是个算式
//		return "(" + nodes[root].val + DFS(nodes[root].r) + ")";
//	else
//		return "(" + DFS(nodes[root].l) + DFS(nodes[root].r) + nodes[root].val + ")";
//}
//int main()
//{
//	cin >> n;
//	vector<bool>isHead(n + 1, true);//找到头节点
//	for (int i = 1; i <= n; ++i)
//	{
//		string a;
//		int b, c;
//		cin >> a >> b >> c;
//		nodes[i] = { a,b,c };
//		isHead[(b == -1 ? 0 : b)] = isHead[(c == -1 ? 0 : c)] = false;
//	}
//	for (int i = 1; i <= n && head == -1; ++i)//找到头节点
//		if (isHead[i])head = i;
//	string res = DFS(head);
//	cout << res;
//	return 0;
//}
