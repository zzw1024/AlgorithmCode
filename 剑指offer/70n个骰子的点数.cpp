//#include "head.h"
//
//void theProbability(const int &num)
//{
//	if (num < 1)return ;
//	vector<vector<int>> theSum(2, vector<int>(6 * num + 1, 0));
//	int flag = 0;
//	for (int i = 1; i <= 6; ++i)theSum[flag][i] = 1;//��һ��Ͷ��ÿ�����ĸ�����ͬ	
//	for (int i = 2; i <= num; ++i)//������
//	{
//		//for (int j = 0; j < i; ++j)theSum[1-flag][j] = 0;//ǰ��Ͷ��������
//		for (int j = i; j <= 6 * i; ++j)
//		{
//			theSum[1 - flag][j] = 0;
//			for (int k = 1; k <= j && k <= 6; ++k)
//				theSum[1 - flag][j] += theSum[flag][j - k];
//		}
//		flag = 1 - flag;
//	}
//	for (int i = num; i <= num * 6; ++i)
//		cout << i << ":  " << (double)theSum[flag][i] / (double)(pow(6.0, num)) << endl;
//}
//
//int main()
//{
//	theProbability(1);
//	return 0;
//	��Ŀ��
//
//		��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�
//}