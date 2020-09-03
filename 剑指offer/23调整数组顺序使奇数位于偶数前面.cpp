//
//#include "head.h"
//
////相对位置会变的,刚好和书本上的初级想法合上了
////但牛客上要求相对位置不变
//class Solution01 {
//public:
//	void reOrderArray(vector<int> &array) {
//		if (array.size() < 2)return;
//		int L = 0, R = array.size() - 1;
//		while (L < R)
//		{
//			if (func(array[L]))//是奇数
//				++L;
//			if (!func(array[R]))//是偶数
//				--R;
//			if (!func(array[L]) && func(array[R]))
//			{
//				swap(array[L], array[R]);
//				++L;
//				--R;
//			}
//		}
//	}
//	bool func(int x)
//	{
//		return x & 0x01;
//	}
//};
//
////牛客上题目是保持相对位置不变，我只能利用额外空间了
//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		if (array.size() < 2)return;
//		vector<int>eventV;
//		int oddPot = 0;
//		for (int i = 0; i < array.size(); ++i)
//		{
//			if (array[i] & 0x01 != 0)//奇数
//			{
//				array[oddPot] = array[i];
//				++oddPot;
//			}
//			else
//				eventV.push_back(array[i]);
//		}
//		for (int i = 0; i < eventV.size(); ++i)
//			array[oddPot++] = eventV[i];
//	}
//};
//
//
//int main()
//{
//	vector<int>v = { 1,2,3,7,8,4,5,4,5,6,7 };
//	Solution01 s;
//	s.reOrderArray(v);
//	for (auto a : v)
//		cout << a << " ";
//	while (1);
//}
////
////
