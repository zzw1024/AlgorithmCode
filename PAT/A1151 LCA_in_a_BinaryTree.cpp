////#include <iostream>
////#include <vector>
////#include <unordered_map>
////#include <algorithm>
////using namespace std;
////int n, m;
////vector<int>in, pre, root;
////unordered_map<int, bool>map;
////unordered_map<int, int>local;
////void DFS(int inL, int inR, int preL, int preR)
////{
////	if (inL > inR)return;
////	int k = inL;
////	while (k <= inR && in[k] != pre[preL])++k;
////	root.push_back(k);
////	int num = k - inL;
////	DFS(inL, k - 1, preL + 1, preL + num);
////	DFS(k + 1, inR, preL + num + 1, preR);
////}
////int main()
////{
////	cin >> m >> n;
////	in.resize(n);
////	pre.resize(n);	
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> in[i];
////		map[in[i]] = true;
////		local[in[i]] = i;
////	}
////	for (int i = 0; i < n; ++i)
////		cin >> pre[i];
////	DFS(0, n - 1, 0, n - 1);
////	while (m--)
////	{
////		int a, b;
////		cin >> a >> b;
////		if (!map[a] && !map[b])
////			printf("ERROR: %d and %d are not found.\n", a, b);
////		else if(!map[a])
////			printf("ERROR: %d is not found.\n", a);
////		else if(!map[b])
////			printf("ERROR: %d is not found.\n", b);
////		else
////		{
////			int res = 0;
////			for (auto v : root)
////			{
////				if ((local[a] <= v && local[b] >= v) || (local[a] >= v && local[b] <= v))
////				{
////					res = in[v];
////					break;
////				}
////			}
////			if (res == a)
////				printf("%d is an ancestor of %d.\n", a, b);
////			else if (res == b)
////				printf("%d is an ancestor of %d.\n", b, a);
////			else
////				printf("LCA of %d and %d is %d.\n", a, b, res);
////		}
////	}
////	return 0;
////}
////
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int n, m;
//vector<int>pre, in, post;
//unordered_map<int, bool>map;
//void postOrder(int inL, int inR, int preL, int preR)
//{
//	if (inL > inR)return;
//	int k = inL, root = pre[preL];
//	while (k <= inR && in[k] != pre[preL])++k;
//	int num = k - inL;
//	postOrder(inL, k - 1, preL + 1, preL + num);
//	postOrder(k + 1, inR, preL + num + 1, preR);
//	post.push_back(pre[preL]);
//}
//int main()
//{
//	cin >> m >> n;
//	pre.resize(n);
//	in.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> in[i];
//		map[in[i]] = true;
//	}
//	for (int i = 0; i < n; ++i)
//		cin >> pre[i];
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (!map[a] && !map[b])
//			printf("ERROR: %d and %d are not found.\n", a, b);
//		else if (!map[a])
//			printf("ERROR: %d is not found.\n", a);
//		else if (!map[b])
//			printf("ERROR: %d is not found.\n", b);
//		else
//		{
//			postOrder(0, n - 1, 0, n - 1);
//			int res = 0;
//			for (auto v : root)
//			{
//				if ((local[a] <= v && local[b] >= v) || (local[a] >= v && local[b] <= v))
//				{
//					res = in[v];
//					break;
//				}
//			}
//			if (res == a)
//				printf("%d is an ancestor of %d.\n", a, b);
//			else if (res == b)
//				printf("%d is an ancestor of %d.\n", b, a);
//			else
//				printf("LCA of %d and %d is %d.\n", a, b, res);
//		}
//	}
//}