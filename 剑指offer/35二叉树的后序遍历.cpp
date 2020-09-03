//#include "head.h"
////
////class Solution {
////public:
////	bool VerifySquenceOfBST(vector<int> sequence) {
////		if (sequence.size() == 0)return false;
////		return isBST(sequence, 0, sequence.size() - 1);
////	}
////	bool isBST(vector<int>v, int L, int R)
////	{
////		if (L >= R)return true;
////		int root = v[R];
////		int i = L;
////		while (v[i] < root)++i;//ÕÒµ½×ó×ÓÊ÷
////		int j = i;
////		while (j < R)if (v[j++] < root)return false;//ÅÐ¶ÏÓÒ×ÓÊ÷
////		return isBST(v, L, i - 1) && isBST(v, i, R - 1);	
////	}	
////};
////
//int main()
//{
//	vector<int>v = { 1,2,3 };
//	return 0;
//
//
//}