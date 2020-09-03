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
//
//class Solution01 {
//public:
//	bool isSymmetrical(TreeNode* pRoot)
//	{
//		if (pRoot == nullptr)return true;
//		vector<int>v1, v2;
//		DFS(pRoot, v1, true);
//		DFS(pRoot, v2, false);
//		if (v1 == v2)return true;
//		else return false;
//		
//	}
//	void DFS(TreeNode* pRoot, vector<int>&v,const bool flag)
//	{
//		if (pRoot == nullptr)
//			v.push_back(-1);
//		else
//			v.push_back(pRoot->val);
//		if (pRoot == nullptr)return;
//		if (flag)
//		{
//			DFS(pRoot->left, v, flag);
//			DFS(pRoot->right, v, flag);
//		}
//		else
//		{
//			DFS(pRoot->right, v, flag);
//			DFS(pRoot->left, v, flag);
//		}
//	}
//};
//
//class Solution02 {
//public:
//	bool isSymmetrical(TreeNode* pRoot)
//	{
//		return DFS(pRoot, pRoot);
//
//	}
//	bool DFS(TreeNode* root1, TreeNode* root2)
//	{
//		if (root1 == nullptr && root2 == nullptr)return true;
//		if (root1 == nullptr || root2 == nullptr)return false;
//		if (root1->val != root2->val)return false;
//		return DFS(root1->left, root2->right) && DFS(root1->right, root2->left);
//	}
//};
//
//
//int main()
//{
//	TreeNode* root = new TreeNode(8);
//	root->left = new TreeNode(6);
//	root->right = new TreeNode(6);
//	root->left->left = new TreeNode(5);
//	root->left->right = new TreeNode(7);
//	//root->right->left = new TreeNode(7);
//	root->right->right = new TreeNode(5);
//	Solution s;
//	cout << s.isSymmetrical(root) << endl;
//	while (1);
//}