//#pragma once
//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
////
////����Ŀ��
////	����һ�����;���map�����е�ֵֻ��0��1���֣�������ȫ��1
////	�����о��������У����ľ�������Ϊ1��������
////	���磺
////	1 1 1 0
////	���У����ľ���������3��1�����Է���3��
////	���磺
////	1 0 1 1
////	1 1 1 1
////	1 1 1 0
////	���У����ľ���������6��1�����Է���6��
////���⡿
////	ʹ�õ���ջ
////	ջ��Ϊ��С����˳��
////	������ӵ�һ�����½�ÿһ�н����ۼӣ��µ�����Ϊ0�����ۼӺ�Ϊ0
////  ����ÿһ�е��ۼӺ͵�������
////	�������ĵ�һ���ۼӺ�����Ϊ[1,0,1,1]
////			�ڶ����ۼӺ�����Ϊ[2,1,2,2]
////			�������ۼӺ�����Ϊ[3, 2, 3, 0];
////	Ȼ���ۼӺ��������õ���ջ���м���������������ά��ջΪ��С���������
//
//
//int MaxRecArea(const vector<vector<int>>v)
//{
//	vector<int>Sum(v[0].size(), 0);//����ÿ�е��ۼӺ�
//	int res = 0;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		for (int j = 0; j < v[0].size(); ++j)
//			Sum[j] = v[i][j] == 0 ? 0 : (Sum[j] + v[i][j]);
//
//		deque<int>d;//����ջ
//		for (int j = 0; j < Sum.size(); ++j)
//		{
//			while (!d.empty() && Sum[j] <= Sum[d.back()])//ά��ջΪ��С���������
//			{
//				int index = d.back();
//				d.pop_back();
//				if (d.empty())//���������ܵ������-1��λ��
//					res = res > (Sum[index] * j) ? res : (Sum[index] * j);
//				else//������������߽�
//					res = res > (Sum[index] * (j - d.back() - 1)) ? res : (Sum[index] * (j - d.back() - 1));
//			}
//			d.push_back(j);
//		}
//		while (!d.empty())//����ʣ��������䶼���ұ߽磬�ұ߽�Ϊ����Ĵ�С
//		{
//			int index = d.back();
//			d.pop_back();
//			if (d.empty())//���������ܵ������-1��λ��
//				res = res > (Sum[index] * Sum.size()) ? res : (Sum[index] * Sum.size());
//			else//������������߽�,
//				res = res > (Sum[index] * (Sum.size() - d.back() - 1)) ? res : (Sum[index] * (Sum.size() - d.back() - 1));
//		}
//	}
//	return res;
//}
//
//
//
//void Test()
//{
//	vector<vector<int>>v;
//	v = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 0, 1, 1 }, };
//	cout << MaxRecArea(v) << endl;
//
//}