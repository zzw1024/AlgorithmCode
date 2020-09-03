//#include "head.h"
//
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//		val(x), left(NULL), right(NULL) {
//	}
//};
//
//
//class Solution {
//public:
//	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//	{
//		if (pRoot1 == nullptr || pRoot2 == nullptr)return false;
//		bool res = false;
//		if (pRoot1->val != pRoot2->val)
//		{
//			if (pRoot1->val == pRoot2->val)
//				res = DFS(pRoot1, pRoot2);
//			if (!res)
//				res = HasSubtree(pRoot1->left, pRoot2);
//			if (!res)
//				res = HasSubtree(pRoot1->right, pRoot2);
//		}
//		return res;
//	}
//	bool DFS(TreeNode* root1, TreeNode* root2)
//	{
//		if (root2 == nullptr)return true;
//		if (root1 == nullptr)return false;
//		if (root1->val != root2->val)return false;
//		return DFS(root1->left, root2->left) && DFS(root1->right, root2->right);
//	}
//};
//
//int main()
//{
//	Solution s;
//	TreeNode* root1 = new TreeNode(8);
//	root1->left = new TreeNode(8);
//	root1->right = new TreeNode(7);
//	root1->left->left = new TreeNode(9);
//	root1->left->right = new TreeNode(2);
//	root1->left->right->left = new TreeNode(4);
//	root1->left->right->right = new TreeNode(7);
//
//	cout << s.HasSubtree(root1, root1->left) << endl;
//	while (1)
//	{
//
//	}
//}