//#include "head.h"
//
//class Solution {
//public:
//	vector<int> multiply(const vector<int>& A) {
//		int size = A.size();
//		if (size < 1)return{};
//		vector<int>res(size);
//		vector<int>C(size, 1), D(size, 1);
//		for (int i = 1, j = size - 2; i < size && j >= 0; ++i, --j)
//		{
//			C[i] = C[i - 1] * A[i - 1];
//			D[j] = D[j + 1] * A[j + 1];
//		}
//		for (int i = 0; i < size; ++i)
//			res[i] = C[i] * D[i];
//		return res;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int>res = s.multiply({1,2,3,4,5});
//	return 0;
//}