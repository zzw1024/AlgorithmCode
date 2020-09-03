//#include "head.h"
//
////题目的意思是，在一颗二叉树的中序遍历中，给出其中一个节点，让你找到中序中该节点的下一个节点
//struct TreeLinkNode {
//	int val;
//	struct TreeLinkNode *left;
//	struct TreeLinkNode *right;
//	struct TreeLinkNode *next;
//	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
//
//	}
//};
//
//class Solution {
//public:
//	TreeLinkNode* GetNext(TreeLinkNode* pNode)
//	{
//		if (pNode == nullptr)
//			return nullptr;
//		if (pNode->right != nullptr)//有右子树，则为右子树的最左节点
//		{
//			pNode = pNode->right;
//			while (pNode->left != nullptr)
//				pNode = pNode->left;
//			return pNode;
//		}
//		else if (pNode->right == nullptr)
//		{
//			while (pNode->next!=nullptr && pNode != pNode->next->left)
//				pNode = pNode->next;
//			return pNode->next;
//		}
//		return nullptr;
//	}
//};