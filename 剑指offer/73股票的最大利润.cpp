//#include "head.h"
//
//int maxBenifit(vector<int>data)
//{
//	if (data.size() < 2)return 0;
//	int minV = data[0], res = 0;
//	for (int i = 1; i < data.size(); ++i)
//	{
//		res = res >= data[i] - minV ? res : data[i] - minV;
//		minV = minV < data[i] ? minV : data[i];
//	}
//	return res;
//}
//
//int main()
//{
//	cout << maxBenifit({9,11,8,5,7,12,16,14}) << endl;
//	return 0;
//}