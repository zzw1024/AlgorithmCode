//#include "head.h"
//
////��һ�ַ����ܼ򵥣�������һ�������ֵĴ���
//class Solution01 {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//		bool flag = false;
//		unordered_map<int, int>map;
//		for (auto a : data)map[a]++;
//		for(auto a:map)
//			if(a.second==1)
//				if (!flag) {
//					*num1 = a.first;
//					flag = !flag;
//				}
//				else
//				{
//					*num2 = a.first;
//					return;
//				}
//	}
//};
//
////�ڶ��ַ�����ʹ���������
//class Solution02 {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//		if (data.size() == 0)return;
//		int resultExclusiveOR = 0;
//		for (auto a : data)resultExclusiveOR ^= a;
//		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
//
//		*num1 = *num2 = 0;
//		for (auto a:data)
//		{
//			if (IsBit1(a, indexOf1))
//				*num1 ^= a;
//			else
//				*num2 ^= a;
//		}
//	}
//
//	// �ҵ�num���ұ������һ����1��λ
//	unsigned int FindFirstBitIs1(int num)
//	{
//		int indexBit = 0;
//		while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
//		{
//			num = num >> 1;
//			++indexBit;
//		}
//
//		return indexBit;
//	}
//
//	// �ж�����num�ĵ�indexBitλ�ǲ���1
//	bool IsBit1(int num, unsigned int indexBit)
//	{
//		num = num >> indexBit;
//		return (num & 1);
//	}
//
//};
