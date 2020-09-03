#include "_000库函数.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//递归遍历
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>res;
		helper(res, root);
		return res;
	}
	void helper(vector<int>&res, TreeNode* root) {
		if (root==NULL)
			return;
		if (root->left)
			helper(res, root->left);
		res.push_back(root->val);
		if (root->right)
			helper(res, root->right);
	}
};


////非递归遍历
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int>res;
//		stack<TreeNode*>s;
//		TreeNode* p = root;
//		while (p || !s.empty()) {
//			while (p) {
//				s.push(p);
//				p = p->left;
//			}//找到最左节点
//			p = s.top();
//			s.pop();
//			res.push_back(p->val);
//			p = p->right;
//		}
//		return res;
//	}
//};
//
//
////另一种解法
//// Non-recursion and no stack
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode *root) {
//		vector<int> res;
//		if (!root) return res;
//		TreeNode *cur, *pre;
//		cur = root;
//		while (cur) {
//			if (!cur->left) {
//				res.push_back(cur->val);
//				cur = cur->right;
//			}
//			else {
//				pre = cur->left;
//				while (pre->right && pre->right != cur) pre = pre->right;
//				if (!pre->right) {
//					pre->right = cur;
//					cur = cur->left;
//				}
//				else {
//					pre->right = NULL;
//					res.push_back(cur->val);
//					cur = cur->right;
//				}
//			}
//		}
//		return res;
//	}
//};
//


//TreeNode * creatTree(vector<int>v,int i, TreeNode *root) {
//	if (i >= v.size())
//		return NULL;
//	root = new TreeNode(0);
//	root->val = v[i];
//	root->left = creatTree(v, i + 1, root->left);
//	root->right = creatTree(v, i + 1, root->right);
//	return root;
//}

void CreateBiTree(TreeNode *&T)
{
	int ch;
	//char ch;
	//cout << "please enter the keys:" << endl;
	cin >> ch;
	if (ch == 0)
		T = NULL;
	else
	{
		T = new TreeNode(0);
		T->val = ch;
		CreateBiTree(T->left);
		CreateBiTree(T->right);
	}
}




void T094() {
	Solution s;
	vector<int>v;
	TreeNode *root = new TreeNode(0);
	CreateBiTree(root);

	
	v = s.inorderTraversal(root);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
}