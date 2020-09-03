////#include <iostream>
////#include <vector>
////using namespace std;
////int n, num;
////bool flag = false;
////vector<int>preOrder, inOrder, postOrder;
////void travel(int root, int L, int R)//L，R为中序遍历的，root为前序遍历的第一个点
////{
////	if (L > R || flag)
////		return;
////	int i = L;
////	while (inOrder[i] != preOrder[root])++i;
////	travel(root + 1, L, i - 1);//遍历左子树Order
////	travel(root + 1 + i - L, i + 1, R);//遍历左子树Order
////	//postOrder.push_back(preOrder[root]);//得到完整的后序遍历
////	if (!flag)//输出一个就剪枝
////	{
////		cout << preOrder[root] << endl;
////		flag = true;
////	}
////}
////int main()
////{
////	cin >> n;
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> num;
////		preOrder.push_back(num);
////	}
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> num;
////		inOrder.push_back(num);
////	}
////	travel(0, 0, n - 1);
////	//cout << postOrder[0] << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n;
//vector<int>pre, in, post;
//void getPostOrder(int root, int L, int R)
//{
//	if (L > R || post.size() > 0)
//		return;
//	int k = L;
//	while (k <= R && in[k] != pre[root])++k;
//	int m = k - L;
//	getPostOrder(root + 1, L, k - 1);
//	getPostOrder(root + k - L + 1, k + 1, R);
//	post.push_back(pre[root]);
//}
//int main()
//{
//	cin >> n;
//	in.resize(n);
//	pre.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> pre[i];
//	for (int i = 0; i < n; ++i)
//		cin >> in[i];
//	getPostOrder(0, 0, n - 1);
//	cout << post[0] << endl;
//	return 0;
//}
