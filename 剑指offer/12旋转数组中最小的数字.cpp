//#include "head.h"
//
//class Solution01 {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)return 0;
//		int minN = rotateArray[0];
//		for (int i = 0; i < rotateArray.size() - 1; ++i)
//			if (rotateArray[i] > rotateArray[i + 1])
//				return minN < rotateArray[i + 1] ? minN : rotateArray[i + 1];
//		return minN;
//	}
//};
//
//class Solution02 {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)return 0;
//		int L = 0, R = (int)rotateArray.size() - 1, M = 0;
//		while (rotateArray[L] >= rotateArray[R])
//		{
//			if (R - L == 1)
//			{
//				M = R;
//				break;
//			}
//			M = (L + R) / 2;
//			if (rotateArray[M] == rotateArray[L] && rotateArray[M] == rotateArray[R])
//				return getMin(rotateArray, L, R);
//			else if (rotateArray[M] >= rotateArray[L])
//				L = M;
//			else
//				R = M;
//		}
//		return rotateArray[M];
//	}
//
//	int getMin(vector<int> Num, int L, int R)
//	{
//		int minN = Num[L];
//		for (; L <= R; ++L)minN = minN < Num[L] ? minN : Num[L];
//		return minN;
//	}
//};