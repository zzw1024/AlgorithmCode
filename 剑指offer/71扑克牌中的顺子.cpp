//#include "head.h"
//
//
//class Solution {
//public:
//	bool IsContinuous(vector<int> numbers) {
//		if (numbers.size() < 1)return false;
//		sort(numbers.begin(), numbers.end());
//		int zerosN = 0, lostN = 0;
//		for (int i = 0; i < numbers.size(); ++i)
//		{
//			if (numbers[i] == 0)zerosN++;//�����С���ĸ���
//			else if (i > 0 && numbers[i] == numbers[i - 1])return false;//���ֶ���
//			else if (i > 0)lostN += numbers[i] - numbers[i - 1] - 1;//���������
//		}
//		return zerosN >= lostN;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.IsContinuous({1,2,3,4,5}) << endl;
//	cout << s.IsContinuous({1,3,0,0,5}) << endl;
//	cout << s.IsContinuous({1,2,3,4,6}) << endl;
//	return 0;
//}