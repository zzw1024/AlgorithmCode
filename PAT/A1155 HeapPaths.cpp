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
////vector<int>level;
////Node *creatTree(int index)//�ع�������
////{
////	Node *root = new Node(level[index++]);
////	queue<Node*>q;
////	q.push(root);
////	while (!q.empty() && index<n)
////	{
////		Node *p = q.front();
////		q.pop();
////		p->l = new Node(level[index++]);
////		q.push(p->l);
////		if (index >= n)break;
////		p->r = new Node(level[index++]);
////		q.push(p->r);
////	}
////	return root;
////}
////vector<int>res;
////void DFS(Node *root, bool isMaxHeap,bool &isHeap)
////{
////	if (root == nullptr)
////		return;
////	res.push_back(root->val);
////	if (isMaxHeap)//������ж�
////	{
////		if ((root->l && root->l->val > root->val) || (root->r && root->r->val > root->val))
////			isHeap = false;
////	}
////	else//С�����ж�
////	{
////		if ((root->l && root->l->val < root->val) || (root->r && root->r->val < root->val))
////			isHeap = false;
////	}
////	if (root->l == nullptr && root->r == nullptr)//���·��
////	{
////		for (int i = 0; i < res.size(); ++i)
////			cout << (i == 0 ? "" : " ") << res[i];
////		cout << endl;
////	}
////	DFS(root->r, isMaxHeap, isHeap);//�ǵ���������
////	DFS(root->l, isMaxHeap, isHeap);
////	res.pop_back();
////}
////int main()
////{
////	cin >> n;
////	level.resize(n);
////	for (int i = 0; i < n; ++i)
////		cin >> level[i];
////	Node* root = creatTree(0);
////	bool isHeap = true;
////	bool isMaxHeap = level[0] >= level[1] ? 1 : 0;
////	DFS(root, isMaxHeap, isHeap);
////	if (isHeap && isMaxHeap)
////		cout << "Max Heap" << endl;
////	else if (isHeap && !isMaxHeap)
////		cout << "Min Heap" << endl;
////	else
////		cout << "Not Heap" << endl;
////	return 0;
////}
//
//
////��̬������
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//int n;
//vector<int>level, res;
//void DFS(int index, const bool isMaxHeap, bool &isHeap)
//{
//	if (index > n)return;
//	res.push_back(level[index]);
//	int L = 2 * index, R = index * 2 + 1;
//	if (L > n && R > n)//����Ҷ�ӽڵ�
//	{
//		for (int i = 0; i < res.size(); ++i)
//			cout << (i == 0 ? "" : " ") << res[i];
//		cout << endl;
//	}
//	if ((isMaxHeap && ((L <= n && level[L] > level[index]) || (R <= n && level[R] > level[index]))) ||
//		(!isMaxHeap && ((L <= n && level[L] < level[index]) || (R <= n && level[R] < level[index]))))
//		isHeap = false;
//	DFS(index * 2 + 1, isMaxHeap, isHeap);//��������
//	DFS(index * 2, isMaxHeap, isHeap);
//	res.pop_back();
//}
//int main()
//{
//	cin >> n;
//	level.resize(n+1);//�ǵ�С���1��ʼ
//	for (int i = 1; i <= n; ++i)
//		cin >> level[i];
//	bool isHeap = true;
//	bool isMaxHeap = level[1] >= level[2] ? 1 : 0;	
//	DFS(1, isMaxHeap, isHeap);
//	if (isHeap && isMaxHeap)
//		cout << "Max Heap" << endl;
//	else if (isHeap && !isMaxHeap)
//		cout << "Min Heap" << endl;
//	else
//		cout << "Not Heap" << endl;
//	return 0;
//}
//
