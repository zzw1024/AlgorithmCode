//
//#include "head.h"
//
////���λ�û���,�պú��鱾�ϵĳ����뷨������
////��ţ����Ҫ�����λ�ò���
//class Solution01 {
//public:
//	void reOrderArray(vector<int> &array) {
//		if (array.size() < 2)return;
//		int L = 0, R = array.size() - 1;
//		while (L < R)
//		{
//			if (func(array[L]))//������
//				++L;
//			if (!func(array[R]))//��ż��
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
////ţ������Ŀ�Ǳ������λ�ò��䣬��ֻ�����ö���ռ���
//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		if (array.size() < 2)return;
//		vector<int>eventV;
//		int oddPot = 0;
//		for (int i = 0; i < array.size(); ++i)
//		{
//			if (array[i] & 0x01 != 0)//����
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
