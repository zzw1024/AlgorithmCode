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
//	if (nodes[root].l == -1)//��ס��ֻ����������Ϊ�գ�����������Ϊ�գ���Ȼ�Ͳ��Ǹ���ʽ
//		return "(" + nodes[root].val + DFS(nodes[root].r) + ")";
//	else
//		return "(" + DFS(nodes[root].l) + DFS(nodes[root].r) + nodes[root].val + ")";
//}
//int main()
//{
//	cin >> n;
//	vector<bool>isHead(n + 1, true);//�ҵ�ͷ�ڵ�
//	for (int i = 1; i <= n; ++i)
//	{
//		string a;
//		int b, c;
//		cin >> a >> b >> c;
//		nodes[i] = { a,b,c };
//		isHead[(b == -1 ? 0 : b)] = isHead[(c == -1 ? 0 : c)] = false;
//	}
//	for (int i = 1; i <= n && head == -1; ++i)//�ҵ�ͷ�ڵ�
//		if (isHead[i])head = i;
//	string res = DFS(head);
//	cout << res;
//	return 0;
//}
