//#include "head.h"
//
////��Ŀ����������n����˳���ӡ����1������nλʮ��������
////��������3�����ӡ��1��2��3һֱ������3λ��999��
//
//class Solution
//{
//public:
//	void Print1ToMaxOfNDigits(int n)
//	{
//		if (n < 1)
//		{
//			cout << 0 << endl;
//			return;
//		}
//		string str = "1";
//		while(str.length()<n+1)
//		{
//			cout << str << endl;
//			int c = 0;			
//			for (int i = str.length() - 1; i >= 0; --i)
//			{
//				if (i == str.length() - 1 || c == 1)
//				{
//					int temp = str[i] - '0' + 1;
//					str[i] = temp % 10 + '0';
//					c = temp / 10;
//				}
//				else
//					break;
//			}
//			if (c == 1)
//				str.insert(str.begin(), '1');
//		}
//	}
//};
//
//int main()
//{
//	Solution P;
//	P.Print1ToMaxOfNDigits(20);
//	while (1);
//}