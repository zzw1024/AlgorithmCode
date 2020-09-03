//#include "head.h"
//
//class Solution
//{
//public:
//	int findTheOnlyNum(vector<int>data)
//	{
//		if (data.size() == 0)return 0;
//		for (auto a : data)	calTheBits(a);
//		int res = 0;
//		for (int i = 0; i < 32; ++i)
//			if (bits[i] % 3 == 1)res += pow(2, i);
//		return res;
//	}
//private:
//	int bits[32] = { 0 };
//	void calTheBits(int num)
//	{
//		int n = 1;
//		for (int i = 0; i < 32; ++i)
//		{
//			if (num & n)bits[i]++;
//			n = n << 1;
//		}
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	cout << s.findTheOnlyNum({5,5,5,3,3,3,4,4,4,6}) << endl;
//	return 0;
//}