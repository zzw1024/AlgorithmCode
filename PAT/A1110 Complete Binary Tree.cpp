////#include <iostream>
////#include <vector>
////#include <queue>
////#include <string>
////using namespace std;
////struct Node
////{
////	int l, r;
////}node;
////int n;
////int main()
////{
////	cin >> n;
////	vector<Node>tree;
////	vector<bool>isRoot(n, true);
////	for (int i = 0; i < n; ++i)
////	{
////		string s1, s2;
////		cin >> s1 >> s2;
////		if (s1 == "-")
////			node.l = -1;
////		else
////		{
////			node.l = atoi(s1.c_str());
////			isRoot[node.l] = false;
////		}
////		if (s2 == "-")
////			node.r = -1;
////		else
////		{
////			node.r = atoi(s2.c_str());
////			isRoot[node.r] = false;
////		}
////		tree.push_back(node);
////	}
////	int root = -1;//根
////	for (int i = 0; i < n && root==-1; ++i)
////		if (isRoot[i])
////			root = i;
////	queue<int>q, temp;
////	q.push(root);
////	while (!q.empty())//进行层序遍历
////	{
////		int p = q.front();
////		q.pop();
////		temp.push(p);//保存弹出的数据
////		if (tree[p].l != -1)
////			q.push(tree[p].l);
////		else
////			break;//出现空子节点，则打破了完全二叉树的规则
////		if (tree[p].r != -1)
////			q.push(tree[p].r);
////		else
////			break;//出现空子节点，则打破了完全二叉树的规则
////	}
////	if (temp.size() + q.size() == n)//满足完全二叉树的要求
////		cout << "YES " << q.back() << endl;//最后压入的就是最后一个节点
////	else
////		cout << "NO " << root << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//using namespace std;
//int n, nums = 0, p, head;
//bool notHead[25] = { false };
//vector<pair<int, int>>v(25);
//void BFS(int root)
//{
//	bool flag = true;
//	queue<int>q;
//	q.push(root);
//	while (!q.empty())
//	{
//		p = q.front();
//		q.pop();
//		nums++;
//		if (flag && v[p].first != -1)
//			q.push(v[p].first);
//		else
//			flag = false;
//		if (flag&&v[p].second != -1)
//			q.push(v[p].second);
//		else
//			flag = false;
//	}
//}
//int main()
//{
//	cin >> n;
//	v.resize(n);
//	for(int i=0;i<n;++i)
//	{
//		string ls, rs;
//		int ln, rn;
//		cin >> ls >> rs;
//		if (ls == "-")
//			ln = -1;
//		else
//		{
//			ln = atoi(ls.c_str());
//			notHead[ln] = true;
//		}
//		if (rs == "-")
//			rn = -1;
//		else
//		{
//			rn = atoi(rs.c_str());
//			notHead[rn] = true;
//		}
//		v[i] = make_pair(ln, rn);			
//	}
//	for (int i = 0; i < n; ++i)
//		if (notHead[i] == false)
//			head = i;
//	BFS(head);
//	if (nums != n)
//		cout << "NO " << head << endl;
//	else
//		cout << "YES " << p << endl;
//	return 0;
//}