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
//	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
//		vector<vector<int>>res;
//		vector<int>v;
//		DFS(root, expectNumber, 0, v, res);
//		sort(res.begin(), res.end(), [](vector<int>a, vector<int>b) {
//			if (a.size() != b.size())return a.size() > b.size();
//			for (int i = 0; i < a.size(); ++i)
//				if (a[i] != b[i])
//					return a[i] > b[i];
//			return a[0] > b[0];
//		});
//		return res;		
//	}
//	void DFS(TreeNode* root, const int N, int sum, vector<int>&v, vector<vector<int>>&res)
//	{
//		if (root == nullptr)return;
//		v.push_back(root->val);//切记，这样算值的递归，一般是先计算值，然后在递归返回时，再将数据减去
//		sum += root->val;
//		if (sum >= N)
//		{
//			if (sum == N && root->left == nullptr && root->right == nullptr)//判断是不是叶子节点
//				res.push_back(v);
//			//return;//不知为何这里不要剪枝，剪枝后结果还是错的
//		}
//		DFS(root->left, N, sum, v, res);
//		DFS(root->right, N, sum, v, res);
//		sum -= root->val;
//		v.pop_back();
//	}
//};
//
//
//int main()
//{
//	TreeNode * root = new TreeNode(5);
//	root->left = new TreeNode(4);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(2);
//	root->left->right = new TreeNode(1);
//	root->right->left = new TreeNode(2);
//	root->right->right = new TreeNode(1);
//	Solution s;
//	vector<vector<int>>v = s.FindPath(root, 11);
//	return 0;
//
//}