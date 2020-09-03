//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
//			return nullptr;
//		return createTree(pre, vin, 0, pre.size() - 1, 0, pre.size() - 1);
//	}
//	TreeNode *createTree(vector<int> pre, vector<int> vin, int inL, int inR, int preL, int preR)
//	{
//		if (inL > inR)return nullptr;
//		TreeNode *root = new TreeNode(pre[preL]);
//		int k = inL;
//		while (k <= inR && vin[k] != pre[preL])k++;
//		int m = k - inL;
//		root->left = createTree(pre, vin, inL, k - 1, preL + 1, preL + m);
//		root->right = createTree(pre, vin, k + 1, inR, preL + m + 1, preR);
//		return root;
//	}
//};
//
//int main()
//{
//	vector<int>pre = { 1,2,4,7,3,5,6,8 };
//	vector<int>vin = { 4,7,2,1,5,3,8,6 };
//	Solution s;
//	TreeNode *root = s.reConstructBinaryTree(pre, vin);
//	while (1);
//}