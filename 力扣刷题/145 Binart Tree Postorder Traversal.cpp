//#include "000库函数.h"
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
//	vector<int> postorderTraversal(TreeNode* root) {
//		if (root == nullptr)return {};
//		vector<int>res;
//		res = postOrder(root);
//		return res;
//	}
//	//使用传统的递归形式
//	void postOrder(TreeNode* root, vector<int>&res)
//	{
//		if (root == nullptr)return;
//		postOrder(root->left, res);
//		postOrder(root->right, res);
//		res.push_back(root->val);
//	}
//	//使用跌代形式,使用两个栈
//	vector<int> postOrder(TreeNode* root)
//	{
//		vector<int>v;
//		stack<TreeNode*> s1, s2;
//		s1.push(root);
//		while (!s1.empty())
//		{
//			TreeNode* p = s1.top();
//			s2.push(p);
//			s1.pop();
//			if (p->left != nullptr)s1.push(p->left);
//			if (p->right != nullptr)s1.push(p->right);			
//		}
//		while (!s2.empty())
//		{
//			v.push_back(s2.top()->val);
//			s2.pop();
//		}
//		return v;
//	}
//	//使用一个栈
//	vector<int> postOrder01(TreeNode* root)
//	{
//		vector<int>v;
//		stack<TreeNode*> s;
//		if (root != nullptr)
//		{
//			s.push(root);
//			TreeNode* p;
//			while (!s.empty())
//			{
//				p = s.top();
//				if (p->left && root != p->left && root != p->right)
//					s.push(p->left);
//				else if (p->right && root != p->right)
//					s.push(p->right);
//				else
//				{
//					v.push_back(p->val);
//					s.pop();
//					root = p;
//				}
//			}
//		}
//	}
//
//};
//
//int main(){
//	TreeNode *root = new TreeNode(1);
//	root->right = new TreeNode(2);
//	root->right->left = new TreeNode(3);
//	Solution s;
//	vector<int>v = s.postorderTraversal(root);
//	for (auto a : v)
//		cout << a << " " << endl;
//	while (1);
//
//}