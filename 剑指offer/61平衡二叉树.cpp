//#include "head.h"
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//			val(x), left(NULL), right(NULL) {
//	}
//};
////����һ��ʹ����ȱ���,�ж�ÿ���ڵ��ǲ���ƽ������������ִ������µķ����ᵼ�µײ�Ľڵ��ظ��ж϶��
//class Solution01 {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot == nullptr)return true;
//		int left = getHeight(pRoot->left);
//		int right = getHeight(pRoot->right);
//		if (abs(left - right) > 1)return false;
//		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//	}
//private:
//	int getHeight(TreeNode *pRoot)
//	{
//		if (pRoot == nullptr)return 1;
//		int left = getHeight(pRoot->left);
//		int right = getHeight(pRoot->right);
//		return max(left, right) + 1;
//	}
//};
//
////��������ʹ�ú�������жϣ����ַ���Ϊ���¶��ϣ�ÿ���ڵ�ֻ��Ҫ�ж�һ�μ���
//class Solution02 {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot == nullptr)return true;
//		int level = 0;
//		return IsBalanced_Solution(pRoot, level);
//	}
//private:
//	bool IsBalanced_Solution(TreeNode* pRoot, int &level)
//	{
//		if (pRoot == nullptr)
//		{
//			level = 0;
//			return true;
//		}
//		//���պ������ȥ�ж�����������Ȼ���Ե�ǰ�ڵ�Ϊ���������
//		int left = 0, right = 0;
//		if (IsBalanced_Solution(pRoot->left, left) && IsBalanced_Solution(pRoot->right, right))
//		{
//			if (abs(left - right) <= 1)
//			{
//				level = max(left, right) + 1;
//				return true;
//			}
//		}
//		return false;
//	}
//};
//
//int main()
//{
//	Solution02 s;
//	TreeNode*root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->left->right->left = new TreeNode(7);
//	root->right->right = new TreeNode(6);
//	cout << s.IsBalanced_Solution(root) << endl;
//	root->left->right->left->left = new TreeNode(10);
//	cout << s.IsBalanced_Solution(root) << endl;
//	return 0;
//}