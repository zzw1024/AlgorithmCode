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
//		ConvertNode(pRootOfTree, head);//���ص�headΪָ��˫�����β�ڵ�
//		while (head != nullptr && head->left != nullptr)//��ǰ�ҵ�ͷ�ڵ�
//			head = head->left;
//		return head;
//	}
//	void ConvertNode(TreeNode *cur, TreeNode *&pre)
//	{
//		if (cur == nullptr)return;
//		ConvertNode(cur->left, pre);//�ҵ�����ڵ�
//
//		cur->left = pre;//��ڵ�ָ�������С�Ľڵ�
//		if (pre != nullptr)pre->right = cur;//��С���ҽڵ�ָ���һ���ڵ�
//		 
//		pre = cur;//Ȼ�����˫����
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