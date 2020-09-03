//#include "head.h"
//
//void theProbability(const int &num)
//{
//	if (num < 1)return ;
//	vector<vector<int>> theSum(2, vector<int>(6 * num + 1, 0));
//	int flag = 0;
//	for (int i = 1; i <= 6; ++i)theSum[flag][i] = 1;//第一次投，每个数的概率相同	
//	for (int i = 2; i <= num; ++i)//骰子数
//	{
//		//for (int j = 0; j < i; ++j)theSum[1-flag][j] = 0;//前面投过的清零
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
//	题目：
//
//		把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//}