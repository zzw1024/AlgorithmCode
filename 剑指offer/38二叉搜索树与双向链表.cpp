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
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		TreeNode* head = nullptr;
//		ConvertNode(pRootOfTree, head);//返回的head为指向双链表的尾节点
//		while (head != nullptr && head->left != nullptr)//向前找到头节点
//			head = head->left;
//		return head;
//	}
//	void ConvertNode(TreeNode *cur, TreeNode *&pre)
//	{
//		if (cur == nullptr)return;
//		ConvertNode(cur->left, pre);//找到最左节点
//
//		cur->left = pre;//左节点指向比他更小的节点
//		if (pre != nullptr)pre->right = cur;//更小的右节点指向后一个节点
//		 
//		pre = cur;//然后更新双链表
//		ConvertNode(cur->right, pre);
//	}
//};
//
//
//int  main()
//{
//	TreeNode* root = new TreeNode(10);
//	root->left = new TreeNode(6);
//	root->right = new TreeNode(14);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(8);
//	root->right->left = new TreeNode(12);
//	root->right->right = new TreeNode(12);
//	Solution s;
//	TreeNode * p = s.Convert(root);
//	return 0;
//
//}