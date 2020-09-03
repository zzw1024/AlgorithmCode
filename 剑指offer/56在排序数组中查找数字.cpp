//#include "head.h"
//
//class Solution01 {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		if (data.size() == 0)return 0;
//		int L = 0, R = data.size() - 1, M;
//		while (L <= R)
//		{
//			M = (R - L) / 2 + L;
//			if (data[M] == k)break;
//			else if (data[M] > k)R = M - 1;
//			else L = M + 1;
//		}
//		if (L > R)return 0;
//		L = R = M;
//		int res = 0;
//		while (L >= 0 && data[L] == k) {
//			res++; --L;
//		}
//		while (R<data.size() && data[R] == k) {
//			res++; ++R;
//		}
//		return res - 1;
//	}
//};
//
//class Solution02 {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		if (data.size() == 0)return 0;
//		int pM = find(data, 0, data.size() - 1, k);
//		if (data[pM] != k)return 0;
//		int pL = pM, pR = pM;
//		while (pL !=-1 && data[pL] == k) pL = find(data, 0, pL - 1, k);
//		while (pR != -1 && data[pR] == k) pR = find(data, pR + 1, data.size() - 1, k);
//		return (pR == -1 ? data.size() : pR) - pL - 1;
//	}
//	int find(const vector<int>data, int L, int R, const int k)
//	{
//		int M = -1;
//		while (L >= 0 && R < data.size() && L <= R)
//		{
//			M = (R - L) / 2 + L;
//			if (data[M] == k)break;
//			else if (data[M] > k)R = M - 1;
//			else L = M + 1;
//		}
//		return M;
//	}
//};
//
//int main()
//{
//	Solution02 s;
//	cout << s.GetNumberOfK({ 1,2,3,4 }, 5) << endl;
//	cout << s.GetNumberOfK({ 5}, 5) << endl;
//	cout << s.GetNumberOfK({ 1,2,3,3,4,4,4,5,6 }, 4) << endl;
//	cout << s.GetNumberOfK({ 1,2,3,3,3,4,5,6 }, 3) << endl;
//	cout << s.GetNumberOfK({ 2,2,2,2,2,2 }, 2) << endl;
//	cout << s.GetNumberOfK({ 1,1,2,3,4,5 }, 1) << endl;
//	cout << s.GetNumberOfK({ 1,1,2,3,4,5,5,5 }, 5) << endl;
//	cout << s.GetNumberOfK({ 1,2,3,4,5 }, 2) << endl;
//	return 0;
//}
