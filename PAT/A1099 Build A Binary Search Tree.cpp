////#include <iostream>
////#include <queue>
////#include <vector>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int val, l, r;
////}node[105];
////vector<int>nums(105), levelOrder;
////int N, k = 0;
////void inOrderTravel(int root)//得到树的中序遍历
////{
////	if (root == -1)
////		return;
////	inOrderTravel(node[root].l);
////	node[root].val = nums[k++];
////	inOrderTravel(node[root].r);
////}
////void levelOrderTravel(int root)//得到树的中序遍历
////{
////	queue<int>q;
////	q.push(root);
////	while (!q.empty())
////	{
////		root = q.front();
////		q.pop();
////		levelOrder.push_back(node[root].val);
////		if (node[root].l != -1)
////			q.push(node[root].l);
////		if (node[root].r != -1)
////			q.push(node[root].r);
////	}
////}
////int main()
////{
////	cin >> N;	
////	int l, r;
////	int root = 0;
////	for (int i = 0; i < N; ++i)//按题目意思使用前序遍历构建一棵树
////	{
////		cin >> l >> r;
////		node[i].l = l;
////		node[i].r = r;
////	}
////	for (int i = 0; i < N; ++i)
////		cin >> nums[i];
////	sort(nums.begin(), nums.begin() + N);//得到中序遍历
////	inOrderTravel(root);//通过中序遍历重构二叉树
////	levelOrderTravel(root);
////	for (int i = 0; i < N; ++i)
////		cout << levelOrder[i] << (i == N - 1 ? "" : " ");
////	return 0;
////}
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//vector<pair<int, int>>v;
//vector<int> nums, res, inOrder, levelOrder;
//int n;
//void getInOrder(int root)
//{
//	if (root == -1)
//		return;
//	getInOrder(v[root].first);
//	inOrder.push_back(root);
//	getInOrder(v[root].second);
//}
//
//void getLevelOrder(int root)
//{
//	if (root == -1)
//		return;
//	queue<int>q;
//	q.push(root);
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		levelOrder.push_back(p);
//		if (v[p].first != -1)
//			q.push(v[p].first);
//		if (v[p].second != -1)
//			q.push(v[p].second);
//	}
//}
//int main()
//{
//	cin >> n;
//	nums.resize(n);
//	res.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		int l, r;
//		cin >> l >> r;
//		v.push_back(make_pair(l, r));
//	}
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];
//	sort(nums.begin(), nums.end());
//	getInOrder(0);
//	getLevelOrder(0);
//	for (int i = 0; i < n; ++i)
//		res[inOrder[i]] = nums[i];
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << res[levelOrder[i]];
//	return 0;
//}