//#include "head.h"
////使用遍历判断的方法
//class Solution01 {
//public:
//	int GetUglyNumber_Solution(int index) {
//		if (index < 1)return 0;
//		int cnt = 0;
//		for (int i = 1; cnt < index; ++i)
//		{
//			if (isChouShu(i))
//				cnt++;
//			if (cnt == index)
//				return i;
//		}
//	}
//	bool isChouShu(int num)
//	{
//		while (num % 2 == 0)
//			num /= 2;
//		while (num % 3 == 0)
//			num /= 3;
//		while (num % 5 == 0)
//			num /= 5;
//		return num == 1;
//	}
//};
//
//
////使用保存数据法
//class Solution02 {
//public:
//	int GetUglyNumber_Solution(int index) {
//		if (index < 1)return 0;
//		vector<int>v(index, 0);
//		v[0] = 1;
//		int p2, p3, p5, k = 1;
//		p2 = p3 = p5 = 0;
//		while (k < index)
//		{
//			v[k++] = min(min(v[p2] * 2, v[p3] * 3), v[p5] * 5);
//			while (v[p2] * 2 <= v[k - 1])p2++;
//			while (v[p3] * 3 <= v[k - 1])p3++;
//			while (v[p5] * 5 <= v[k - 1])p5++;
//		}
//		return v[index - 1];
//	}
//};
//int main()
//{
//	Solution03 s;
//	cout << s.GetUglyNumber_Solution(12) << endl;
//	return 0;
//}