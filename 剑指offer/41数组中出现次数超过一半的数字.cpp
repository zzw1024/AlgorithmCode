//#include "head.h"
//
////��һ�ַ�����ֱ�Ӽ���ÿ�����ֳ��ֵĴ�����һ����������һ�룬��ֱ����������ַ����ı׶˵���ҪO(n)�Ķ���ռ�
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
////�ڶ��ַ���������һ�����ֳ��ֵĴ�������
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