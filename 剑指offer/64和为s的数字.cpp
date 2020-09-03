//#include "head.h"
//
//class Solution {
//public:
//	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
//		if (array.size() < 2)return{};
//		int L = 0, R = array.size() - 1;
//		while (L < R)
//		{
//			if (array[L] + array[R] == sum)return { array[L] , array[R] };
//			else if (array[L] + array[R] > sum)--R;
//			else ++L;
//		}
//		return {};
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int >v = s.FindNumbersWithSum({ 1,2,4,7,11,15 }, 15);
//	for (auto a : v)cout << a << " ";
//	return 0;
//}
//
