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
//class Solution {
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//		vector<vector<int>>res;
//		BFS(pRoot, res);
//		return res;
//	}
//	void BFS(TreeNode *root, vector<vector<int>>&res)
//	{
//		if (root == nullptr)return;
//		queue<TreeNode*>q;
//		q.push(root);
//		while (!q.empty())
//		{
//			queue<TreeNode*>temp;
//			vector<int>v;
//			while (!q.empty())
//			{				
//				TreeNode* p = q.front();
//				q.pop();
//				v.push_back(p->val);
//				if (p->left != nullptr)temp.push(p->left);
//				if (p->right != nullptr)temp.push(p->right);
//			}
//			res.push_back(v);
//			q = temp;
//		}
//	}
//};
//
//
//int main()
//{
//	TreeNode *root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	Solution s;
//	s.
//	while (1);
//
//}
//
//
