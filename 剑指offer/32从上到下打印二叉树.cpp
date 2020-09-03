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
//	vector<int> PrintFromTopToBottom(TreeNode* root) {
//		vector<int>res;
//		BFS(root, res);
//		return res;
//	}
//	void BFS(TreeNode *root, vector<int>&res)
//	{
//		if (root == nullptr)return;
//		queue<TreeNode*>q;
//		q.push(root);
//		while (!q.empty())
//		{
//			TreeNode* p = q.front();
//			q.pop();
//			res.push_back(p->val);
//			if (p->left != nullptr)q.push(p->left);
//			if (p->right != nullptr)q.push(p->right);
//		}
//	}
//};
