//#include "head.h"
//
////��Ŀ����˼�ǣ���һ�Ŷ���������������У���������һ���ڵ㣬�����ҵ������иýڵ����һ���ڵ�
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
//		if (pNode->right != nullptr)//������������Ϊ������������ڵ�
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