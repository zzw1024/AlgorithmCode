//
//#include "000¿âº¯Êý.h"
//
//
//class Solution {
//public:
//	int singleNumber(int A[], int n) {
//		int bits[32] = { 0 };
//		for (int i = 0; i < n; ++i)
//		{
//			int c = 1;
//			for (int j = 0; j < 32; ++j)
//			{
//				bits[j] += (c & A[i]) ? 1 : 0;
//				c = c << 1;
//			}
//		}
//		int res = 0;
//		for (int i = 0; i < 32; ++i)
//			if (bits[i] % 3)
//				res += (int)pow(2.0, i);
//		return res;
//	}
//};
//
//
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int bits[32] = { 0 };
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			int c = 1;
//			for (int j = 0; j < 32; ++j)
//			{
//				bits[j] += (c & nums[i]) ? 1 : 0;
//				c = c << 1;
//			}
//		}
//		int res = 0;
//		for (int i = 0; i < 32; ++i)
//			if (bits[i] % 3)
//				res += (int)pow(2.0, i);
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int>v;
//	v = { 2,2,2,3 };
//	cout << s.singleNumber(v) << endl;
//	v = { 0,1,0,1,0,1,99 };
//	cout << s.singleNumber(v) << endl;
//	while (1);
//}