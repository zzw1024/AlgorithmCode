#include "_000库函数.h"

#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//解法一：
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return helper(root);
	}

	bool helper(TreeNode* root) {
		if (root->left == NULL && root->right == NULL)
			return true;
		if (root->left == NULL || root->right == NULL)
			return false;
		if (root->left->val >= root->val || root->right->val <= root->val)
			return false;
		return helper(root->left);
		helper(root->right);
	}
};


//解法二：
// Recursion without inorder traversal
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode* root, long mn, long mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;
		return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
	}
};


//解法三：中序遍历
// Recursion
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		vector<int> vals;
		inorder(root, vals);
		for (int i = 0; i < vals.size() - 1; ++i) {
			if (vals[i] >= vals[i + 1]) return false;
		}
		return true;
	}
	void inorder(TreeNode* root, vector<int>& vals) {
		if (!root) return;
		inorder(root->left, vals);
		vals.push_back(root->val);
		inorder(root->right, vals);
	}
};

//解法4：
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		queue<TreeNode* >q;
		q.push(root);
		helper(q, root);
		while (!q.empty()) {
			int a = q.front()->val;
			q.pop();
			int b = q.front()->val;
			if (a >= b)
				return false;
		}
	}
	void helper(queue<TreeNode* >&q, TreeNode* root) {
		if (!root)
			return;
		helper(q, root->left);
		q.push(root);
		helper(q, root->right);
	}
};


TreeNode* CreateBTree(const vector<int> &v)
{
	if (v.size() == 0)
		return nullptr;
	TreeNode* root = new TreeNode(v[0]);
	auto cursor = root;
	queue<TreeNode*> que;
	que.push(cursor);
	for (size_t i = 1; i < v.size(); i++)
	{
		if (que.empty())
			break;
		cursor = que.front();
		if (cursor == NULL)
			break;
		que.pop();
		
		if (v[i] != 0)		
			cursor->left = new TreeNode(v[i]);			
		if (v[++i] != 0)
			cursor->right = new TreeNode(v[i]);

		que.push(cursor->left);
		que.push(cursor->right);
	}
	return root;
}




void T098() {
	Solution s;
	vector<int>v = { 6,5,7,0,0,6,8};
	TreeNode *root;

	root = CreateBTree(v);
	cout << s.isValidBST(root) << endl;

	v = { 2,1,3 };
	root = CreateBTree(v);
	cout << s.isValidBST(root) << endl;
}