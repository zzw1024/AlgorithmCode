//#include "head.h"
//
////第一种方法，直接计算每个数字出现的次数，一旦次数大于一半，则直接输出，这种方法的弊端的需要O(n)的额外空间
//class Solution01 {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		unordered_map<int, int>map;
//		for (auto a : numbers)
//		{
//			map[a]++;
//			if (map[a] > numbers.size() / 2)
//				return a;
//		}
//		return 0;
//	}
//};
////第二种方法，计算一个数字出现的次数即可
//class Solution02 {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int res = numbers[0];
//		int times = 1;
//		for (int i = 1; i < numbers.size(); ++i)
//		{
//			if (times == 0)
//			{
//				res = numbers[i];
//				times = 1;
//			}
//			if (numbers[i] == res)
//				times++;
//			else
//				times--;
//		}
//		return (times > 0 ? res : 0);
//	}
//};
//
//
//int main()
//{
//	Solution02 s;
//	cout << s.MoreThanHalfNum_Solution({ 1,2,3,2,4,2,5,2,3 }) << endl;
//	return 0;
//
//
//}