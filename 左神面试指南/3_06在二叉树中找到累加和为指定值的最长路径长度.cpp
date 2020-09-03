//#include <iostream>
//#include <unordered_map>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int v;
//	Node *l, *r;
//	Node(int a = -1) :v(a), l(nullptr), r(nullptr) {}
//};
//
//int preOrder(Node* root, int sum, int preSum, int level,
//	int maxLen, unordered_map<int, int>sumMap)
//{
//	if (root == nullptr)
//		return maxLen;
//	int curSum = preSum + root->v;
//	if (sumMap.find(curSum) == sumMap.end())//加上这一层的这个数
//		sumMap.insert(make_pair(curSum, level));
//	if (sumMap.find(curSum - sum) != sumMap.end())//存在
//		maxLen = max(level - sumMap[curSum - sum], maxLen);//取更长的路径
//	maxLen = preOrder(root->l, sum, curSum, level + 1, maxLen, sumMap);
//	maxLen = preOrder(root->r, sum, curSum, level + 1, maxLen, sumMap);
//	if (level == sumMap[curSum])
//		sumMap.erase(curSum);
//	return maxLen;
//}
//
//int getMaxLenght(Node* root, int sum)
//{
//	unordered_map<int, int>sumMap;
//	sumMap.insert(make_pair(0, 0));//这一步很重要，表示0个节点就能得到和为0
//	return preOrder(root, sum, 0, 1, 0, sumMap);
//}
//
//Node* creatTree()
//{
//	Node* root = new Node(-3);
//	root->l = new Node(3);
//	root->r = new Node(-9);
//	root->l->l = new Node(1);
//	root->l->r = new Node(0);
//	root->l->r->l = new Node(1);
//	root->l->r->r = new Node(6);
//	root->r = new Node(-9);
//	root->r->l = new Node(2);
//	root->r->r = new Node(1);	
//	return root;
//}
//
//int main()
//{
//	Node* root = creatTree();
//	cout << getMaxLenght(root, -9) << endl;
//	cout << getMaxLenght(root, 6) << endl;
//	return 0;
//}