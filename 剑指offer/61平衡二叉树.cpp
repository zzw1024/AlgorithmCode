//#include "head.h"
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//			val(x), left(NULL), right(NULL) {
//	}
//};
////方法一：使用深度遍历,判断每个节点是不是平衡二叉树，这种从上至下的方法会导致底层的节点重复判断多次
//class Solution01 {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot == nullptr)return true;
//		int left = getHeight(pRoot->left);
//		int right = getHeight(pRoot->right);
//		if (abs(left - right) > 1)return false;
//		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//	}
//private:
//	int getHeight(TreeNode *pRoot)
//	{
//		if (pRoot == nullptr)return 1;
//		int left = getHeight(pRoot->left);
//		int right = getHeight(pRoot->right);
//		return max(left, right) + 1;
//	}
//};
//
////方法二：使用后序遍历判断，这种方法为自下而上，每个节点只需要判断一次即可
//class Solution02 {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot == nullptr)return true;
//		int level = 0;
//		return IsBalanced_Solution(pRoot, level);
//	}
//private:
//	bool IsBalanced_Solution(TreeNode* pRoot, int &level)
//	{
//		if (pRoot == nullptr)
//		{
//			level = 0;
//			return true;
//		}
//		//按照后序遍历去判断左右子树，然后以当前节点为根树的深度
//		int left = 0, right = 0;
//		if (IsBalanced_Solution(pRoot->left, left) && IsBalanced_Solution(pRoot->right, right))
//		{
//			if (abs(left - right) <= 1)
//			{
//				level = max(left, right) + 1;
//				return true;
//			}
//		}
//		return false;
//	}
//};
//
//int main()
//{
//	Solution02 s;
//	TreeNode*root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->left->right->left = new TreeNode(7);
//	root->right->right = new TreeNode(6);
//	cout << s.IsBalanced_Solution(root) << endl;
//	root->left->right->left->left = new TreeNode(10);
//	cout << s.IsBalanced_Solution(root) << endl;
//	return 0;
//}