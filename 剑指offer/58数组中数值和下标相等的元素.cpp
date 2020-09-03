//#include "head.h"
//
//
//int findThatNum(const vector<int>&data)
//{
//	if (data.size() == 0)return -1;
//	int L = 0, R = data.size() - 1, M;
//	while (L >= 0 && R < data.size() && L <= R)
//	{
//		M = (R - L) / 2 + L;
//		if (data[M] == M)return M; 
//		else if (data[M] > M)R = M - 1;//下角标小于其值，目标值在左边
//		else L = M + 1;//下角标大于其值，目标值在右边
//	}
//	return -1;
//}
//
//int main()
//{
//	cout << findThatNum({ -3,-1,1,3,5 }) << endl;
//	cout << findThatNum({ -3,1,5,6,7 }) << endl;
//	return 0;
//}