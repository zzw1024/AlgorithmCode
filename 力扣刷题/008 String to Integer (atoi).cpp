//#include "000�⺯��.h"
//
//ֱ��Ӳ������
//class Solution {
//public:
//	int myAtoi(string str) {
//		if (str.length() == 0)return 0;
//		double res = 0;//������ֹ�����
//		bool isBegan = false; //�Ƿ�ʼ��
//		int isMinus = 1;//�Ƿ��Ǹ���
//		for (int i = 0; i < str.length(); ++i)
//		{
//			if (!isBegan && str[i] == ' ')continue;//��û�п�ʼ
//			if (!isBegan && (str[i] == '-' || str[i] == '+'))//��һ����������
//				isMinus = str[i] == '-' ? -1 : 1;//�Ǹ���
//			else if (isdigit(str[i]))
//				res = res * 10 + str[i] - '0';
//			else//��������
//				return res * isMinus;
//			isBegan = true;//��ʼ��
//			//�ж��Ƿ�Խ��	
//			if ((res * isMinus) < INT_MIN)return INT_MIN;
//			else if (res * isMinus > INT_MAX)return INT_MAX;
//		}
//		return res * isMinus;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.myAtoi("42") << endl;
//	cout << s.myAtoi("4193 with words") << endl;
//	cout << s.myAtoi("words and 987") << endl;
//	cout << s.myAtoi("-91283472332") << endl;
//	return 0;
//}