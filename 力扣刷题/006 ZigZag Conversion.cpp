//#include "000�⺯��.h"
//
//ע���������ĸ�����ǰ��յ��ŵ�N����ģ�Ȼ���������������õ�N��ͼ�ν��а����������
//���հ��N����:һ������һ���е�ѭ�����������뵽ÿһ����
//�������룺0��1��2��3��4��5��6��7��8��9��10��4��
//����״Ϊ
//0			6
//1		5	7
//2	4		8	10
//3			9
//���հ��N����0��1��2��3 ��4��5 Ϊѭ����Ȼ��ȷ�����N�Ĵ�СΪsize = 2 * numRows - 2 = 6
//���N������Ϊ, ������[i%size]����б����[size - i % size];
//
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (s.length() < 2 || numRows < 2)return s;
//		string res = "";
//		vector<string>rows(numRows, "");
//		int size = 2 * numRows - 2;//���N�Ĵ�С
//		for (int i = 0; i < s.length(); ++i)
//		{
//			int id = i % size;
//			if (id < numRows)//����
//				rows[id] += s[i];
//			else//б��
//				rows[size - id] += s[i];
//		}
//		for (auto str : rows)
//			res += str;
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.convert("PAYPALISHIRING", 3) << endl;
//	cout << s.convert("PAYPALISHIRING", 4) << endl;
//	return 0;
//}