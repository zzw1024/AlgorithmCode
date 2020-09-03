//#include"000�⺯��.h"
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		if (root == nullptr)return {};
//		vector<int>res;
//		stack<TreeNode*>s;
//		s.push(root);
//		while (!s.empty())
//		{
//			TreeNode* p = s.top();
//			s.pop();
//			res.push_back(p->val);
//			if (p->right)s.push(p->right);
//			if (p->left)s.push(p->left);
//		}
//		return res;
//	}
//};