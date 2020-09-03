//#include "head.h"
//
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//			val(x), left(NULL), right(NULL) {
//	}
//};
////第一种方法，就是使用中序遍历
//class Solution {
//public:
//	TreeNode* KthNode(TreeNode* pRoot, int k)
//	{
//		if (pRoot == nullptr)return nullptr;
//		inOrder(pRoot, k);
//		return res;
//	}
//	void inOrder(TreeNode* pRoot, const int k)
//	{
//		if (n > k || pRoot == nullptr)return;//进行剪枝和边界处理
//		inOrder(pRoot->left, k);
//		++n;
//		if (n == k && res == nullptr)
//		{
//			res = pRoot;
//			return;
//		}
//		inOrder(pRoot->right, k);
//	}
//private:
//	int n = 0;
//	TreeNode *res = nullptr;
//};
//
//int main()
//{
//	Solution s;
//	TreeNode *root = new TreeNode(5);
//	root->left = new TreeNode(3);
//	root->right = new TreeNode(7);
//	root->left->left = new TreeNode(2);
//	root->left->right = new TreeNode(4);
//	root->right->left = new TreeNode(6);
//	root->right->right = new TreeNode(8);
//	TreeNode *p = s.KthNode(root, 3);
//	cout << (p == nullptr ? -1 : p->val) << endl;
//	return 0;
//}