//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////using namespace std;
//////int N, nums[1001], res[1001], index = 0;
//////void levelOrder(int k)
//////{
//////	if (k > N)//叶子节点
//////		return;
//////	levelOrder(k * 2);//遍历左子树
//////	res[k] = nums[index++];//即遍历完左子树后，此时即为根节点
//////	levelOrder(k * 2 + 1);//遍历右子树
//////}
//////int main()
//////{
//////	cin >> N;
//////	for (int i = 0; i < N; ++i)
//////		cin >> nums[i];
//////	sort(nums, nums + N, [](int a, int b) {return a < b; });
//////	levelOrder(1);
//////	for (int i = 1; i <= N; ++i)
//////		cout << res[i] << (i == N ? "" : " ");
//////	return 0;
//////}
//////
////
//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////using namespace std;
//////vector<int>v, levelOrder;
//////int n, index = 0;
//////void getLevelOrder(int k)
//////{
//////	if (k > n)//叶子数多于节点数
//////		return;
//////	getLevelOrder(k * 2);//左子树
//////	levelOrder[k] = v[index++];//根节点
//////	getLevelOrder(2 * k + 1);//右子树
//////}
//////int main()
//////{
//////	cin >> n;
//////	v.resize(n);
//////	levelOrder.resize(n+1);
//////	for (int i = 0; i < n; ++i)
//////		cin >> v[i];
//////	sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
//////	getLevelOrder(1);
//////	for (int i = 1; i <= n; ++i)
//////		cout << (i == 1 ? "" : " ") << levelOrder[i];
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////vector<int>v, levelOrder;
////int n;
////void creatTree(int L, int R, int index)
////{
////	if (L > R)
////		return;
////	int temp = (int)floor(log(R - L + 2) / log(2));//除去最后一层
////	temp = (int)pow(2, temp - 1);//如果是满二叉树最后一层元素个数的一半
////	int num = min(R - L + 1 - (temp * 2 - 1), temp);//num表示位于根节点的左子树的最后一层元素个数，
////	int root = L + R + num + temp - 1;//root表示根节点在序列中的位置
////	levelOrder[index] = v[root];
////	creatTree(L, R - 1, index * 2);//左子树
////	creatTree(R + 1, R, index * 2 + 1);//右子树
////}
////int main()
////{
////	int n;
////	v.resize(n);
////	levelOrder.resize(n + 1);
////	for (int i = 0; i < n; ++i)
////		cin >> v[i];
////	sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
////	creatTree(0, n - 1, 1);
////	for (int i = 1; i <= n; ++i)
////		cout << (i == 1 ? "" : " ") << levelOrder[i];
////	return 0;
////}
//
//
////
////#include <iostream>
////#include <vector>
////#include <queue>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int val;
////	Node *l, *r;
////	Node(int a = 0) :val(a), l(nullptr), r(nullptr) {}
////};
////int n;
////vector<int>v;
////vector<Node*>nodes, in;
////void creatTree()
////{
////	int index = 0;
////	queue<Node*>q;
////	q.push(nodes[index++]);
////	while (index < n)
////	{
////		Node *p = q.front();
////		q.pop();
////		if (index < n)
////		{
////			p->l = nodes[index++];
////			q.push(p->l);
////		}
////		if (index < n)
////		{
////			p->r = nodes[index++];
////			q.push(p->r);
////		}
////	}
////}
////void inOrder(Node *root)
////{
////	if (root == nullptr)return;
////	inOrder(root->l);
////	in.push_back(root);
////	inOrder(root->r);
////}
////int main()
////{
////	cin >> n;
////	v.resize(n);
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> v[i];
////		nodes.push_back(new Node(0));
////	}
////	sort(v.begin(), v.end());
////	creatTree();
////	inOrder(nodes[0]);
////	for (int i = 0; i < n; ++i)
////		in[i]->val = v[i];
////	for (int i = 0; i < n; ++i)
////		cout << (i == 0 ? "" : " ") << nodes[i]->val;
////	return 0;
////}
////
////
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int n;
//vector<int>v, level;
//void createTree(int L,int R,int index)
//{
//	int nums = R - L + 1;
//	if (nums < 1)return;
//	int k = 1;
//	while (pow(2, k) < nums)++k;
//	int notTheLast = pow(2, k - 1) - 1;//除去最后一层的元素个数
//	int left = pow(2, k - 1) / 2;//最后一层的一半
//	int mid;
//	if (nums - notTheLast <= left)//最后一层一半不到，那么右子树是满树
//		mid = nums - (pow(2, k - 2) - 1) - 1; //减去0号序号
//	else//过半了，那么坐子树是满树
//		mid = pow(2, k - 1) - 1;
//	//level[index] = v[L + mid];
//	cout << index << endl;
//	createTree(L, L + mid - 1, index * 2);
//	createTree(L + mid + 1, R, index * 2+1);
//}
//int main()
//{
//	cin >> n;
//	v.resize(n);
//	level.resize(n + 1);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//	createTree(0, n - 1, 1);
//	for (int i = 1; i <= n; ++i)
//		cout << (i == 0 ? "" : " ") << level[i];
//	return 0;
//}