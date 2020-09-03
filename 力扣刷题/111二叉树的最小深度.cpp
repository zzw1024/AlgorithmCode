//#include "000¿âº¯Êý.h"
//
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//private:
//	int minLevel = INT32_MAX;
//public:
//	int minDepth(TreeNode* root) {
//		if (root == nullptr)return 0;
//		//return BFS(root);
//		int res = INT32_MAX;
//		DFS(root, 1, res);
//		return res;
//	}
//
//	int BFS(TreeNode* root)
//	{
//		queue<TreeNode*>q;
//		q.push(root);
//		int level = 0;
//		while (!q.empty())
//		{
//			queue<TreeNode*>temp;
//			++level;
//			while (!q.empty())
//			{
//				TreeNode* p = q.front();
//				q.pop();
//				if (p->left == nullptr && p->right == nullptr)return level;
//				if (p->left != nullptr)temp.push(p->left);
//				if (p->right != nullptr)temp.push(p->right);
//			}
//			q = temp;
//		}
//		return level;
//	}
//	void DFS(TreeNode* root, int level, int &res)
//	{
//		if (root->left == nullptr && root->right == nullptr) {
//			res = res > level ? level : res;
//			return;
//		}
//		if (root->left != nullptr)DFS(root->left, level + 1, res);
//		if (root->right != nullptr)DFS(root->right, level + 1, res);
//	}
//
//};
//
//int main()
//{
//	Solution s;
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//	cout << s.minDepth(root) << endl;
//	while (1);
//}