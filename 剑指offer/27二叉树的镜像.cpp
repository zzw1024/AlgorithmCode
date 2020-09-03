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
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		if (pRoot == nullptr)return;
//		TreeNode *temp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = temp;
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//};
//
//int main()
//{
//	TreeNode *root = new TreeNode(0);
//
//}