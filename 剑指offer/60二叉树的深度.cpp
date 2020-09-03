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
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		if (pRoot == nullptr)return 0;
//		//深度优先遍历
//		DFS(pRoot, 1);
//		return maxLevel;
//	}
//
//private:
//	int maxLevel = -1;
//	void DFS(TreeNode *pRoot, int level)
//	{
//		if (pRoot == nullptr)return;
//		maxLevel = maxLevel > level ? maxLevel : level;
//		DFS(pRoot->left, level + 1);
//		DFS(pRoot->right, level + 1);
//	}	
//};
//int main()
//{
//	Solution s;
//	TreeNode*root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->left->right->left = new TreeNode(7);
//	root->right->right = new TreeNode(6);
//	cout << s.TreeDepth(root) << endl;
//	return 0;
//}