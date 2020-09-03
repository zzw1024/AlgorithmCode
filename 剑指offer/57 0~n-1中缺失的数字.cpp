//#include "head.h"
//
//int findLostNum(const vector<int> &data)
//{
//	if (data.size() == 0)return -1;
//	int L = 0, R = data.size() - 1, M;
//	if (data[R] == R)return -1;
//	while (L >= 0 && R < data.size() && L <= R)
//	{
//		M = (R - L) / 2 + L;
//		if (data[M] == M)L = M + 1;
//		else if (data[M] > M)
//			if (M > 0 && data[M - 1] == M-1)return M;
//			else if (M == 0)return 0;
//			else R = M - 1;
//	}
//	return -1;
//}
//int main()
//{
//	cout << findLostNum({0,1,2,3,5,6}) << endl;
//	cout << findLostNum({1}) << endl;
//	cout << findLostNum({0,1,2,3,4,5}) << endl;
//	cout << findLostNum({1,2,3,4,5}) << endl;
//	cout << findLostNum({0,1,2,3,4,6}) << endl;
//	return 0;
//}