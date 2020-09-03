//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int n, m;
//vector<int>pre;
//unordered_map<int, bool>map;
//int main()
//{
//	cin >> m >> n;
//	pre.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> pre[i];
//		map[pre[i]] = true;
//	}
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (map[a] != true && map[b] != true)
//			printf("ERROR: %d and %d are not found.\n", a, b);
//		else if (map[a] != true)
//			printf("ERROR: %d is not found.\n", a);
//		else if (map[b] != true)
//			printf("ERROR: %d is not found.\n", b);
//		else
//		{
//			int k = 0;
//			for (k = 0; k < n; ++k)
//				if (a <= pre[k] && pre[k] <= b || b <= pre[k] && pre[k] <= a)
//					break;
//			if (pre[k] == a)
//				printf("%d is an ancestor of %d.\n", a, b);
//			else if (pre[k] == b)
//				printf("%d is an ancestor of %d.\n", b, a);
//			else
//				printf("LCA of %d and %d is %d.\n", a, b, pre[k]);
//		}
//	}
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int n, m;
//vector<int>pre;
//unordered_map<int, bool>isExist;
//int main()
//{
//	cin >> m >> n;
//	pre.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> pre[i];
//		isExist[pre[i]] = true;
//	}
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (isExist[a] != true && isExist[b] != true)
//			printf("ERROR: %d and %d are not found.\n", a, b);
//		else if (isExist[a] != true)
//			printf("ERROR: %d is not found.\n", a);
//		else if (isExist[b] != true)
//			printf("ERROR: %d is not found.\n", b);
//		else
//		{
//			int i = 0;
//			for (i = 0; i < n; ++i)
//				if ((a <= pre[i] && b >= pre[i]) || (b <= pre[i] && a >= pre[i]))//一但pre[i]夹在a,b中间,那么i就是共同节点
//					break;
//			if (pre[i] == a)
//				printf("%d is an ancestor of %d.\n", a, b);
//			else if (pre[i] == b)
//				printf("%d is an ancestor of %d.\n", b, a);
//			else
//				printf("LCA of %d and %d is %d.\n", a, b, pre[i]);
//		}
//	}
//	return 0;
//}
