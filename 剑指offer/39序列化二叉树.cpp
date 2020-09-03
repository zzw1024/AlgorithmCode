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
//
//class Solution {
//public:
//	char* Serialize(TreeNode *root) {
//		string str = "";
//		preOrder(root, str);
//		char *c = new char[str.size() + 1];
//		strcpy(c, str.c_str());
//		return c;
//	}
//	void preOrder(TreeNode *root, string &str)
//	{
//		if (root == nullptr)
//		{
//			str += "#";
//			return;
//		}
//		str += to_string(root->val) + "!";
//		preOrder(root->left, str);
//		preOrder(root->right, str);
//	}
//	TreeNode* Deserialize(char *str) {
//		string s = str;
//		int index = 0;
//		return createTree(s, index);
//	}
//	TreeNode* createTree(const string &str, int &index)
//	{
//		TreeNode* root = nullptr;
//		if (str[index] == '#' || index == str.size())
//		{
//			index++;
//			return root;
//		}
//		string s = "";
//		while (str[index] != '!')
//			s += str[index++];
//		index++;
//		root = new TreeNode(atoi(s.c_str()));
//		root->left = createTree(str, index);
//		root->right = createTree(str, index);
//		return root;
//	}
//};
//
//
//int main()
//{
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	Solution s;
//	char* str = s.Serialize(root);
//	cout << str << endl;
//	TreeNode *a = s.Deserialize(str);
//	while (1);
//}
//
