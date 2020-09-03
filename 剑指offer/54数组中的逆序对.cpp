//#include "head.h"
//
////最笨的方法
//class Solution01 {
//public:
//	int InversePairs(vector<int> data) {
//		if (data.size() < 2)return 0;
//		set<int>s;
//		s.insert(data[0]);
//		int res = 0;
//		for (int i = 1; i < data.size(); ++i)
//		{
//			if (data[i] < *(s.begin()))
//				res += s.size();
//			else if (data[i] > *(--s.end()))
//				res += 0;
//			else
//			{
//				int k = 0;
//				for (auto ptr = s.begin(); ptr != s.end(); ++ptr, ++k)
//				{
//					if (*ptr > data[i])
//					{
//						res += s.size() - k;
//						break;
//					}
//				}
//			}
//			s.insert(data[i]);
//		}
//		return res;
//	}
//};
//
////书本代码，有点乱
//class Solution02 {
//public:
//	int InversePairs(vector<int> data) {
//		if (data.size() < 2)return 0;
//		vector<int>v;//用来复制的
//		v = data;
//		return InversePairsCore(data, v, 0, data.size() - 1);
//	}
//
//	int InversePairsCore(vector<int>&data, vector<int>&copy, int start, int end)
//	{
//		if (start == end)
//		{
//			copy[start] = data[start];
//			return 0;
//		}
//
//		int length = (end - start) / 2;
//
//		int left = InversePairsCore(copy, data, start, start + length) % 1000000007;
//		int right = InversePairsCore(copy, data, start + length + 1, end) % 1000000007;
//
//		// i初始化为前半段最后一个数字的下标
//		int i = start + length;
//		// j初始化为后半段最后一个数字的下标
//		int j = end;
//		int indexCopy = end;
//		int count = 0;
//		while (i >= start && j >= start + length + 1)
//		{
//			if (data[i] > data[j])
//			{
//				copy[indexCopy--] = data[i--];
//				count += j - start - length;
//				if (count >= 1000000007)//数值过大求余
//				{
//					count %= 1000000007;
//				}
//			}
//			else
//			{
//				copy[indexCopy--] = data[j--];
//			}
//		}
//
//		for (; i >= start; --i)
//			copy[indexCopy--] = data[i];
//
//		for (; j >= start + length + 1; --j)
//			copy[indexCopy--] = data[j];
//
//		return (left + right + count) % 1000000007;
//	}
//};
//
//
////使用归并排序思想
//class Solution03 {
//private:
//	int count = 0;
//public:
//	int InversePairs(vector<int> data) {
//		if (data.size() < 2)return 0;
//		mergeSort(data, 0, data.size() - 1);
//		return count;
//	}
//	void mergeSort(vector<int>&data, int L, int R)
//	{
//		if (L < R)
//		{
//			int M = (L + R) / 2;
//			mergeSort(data, L, M);
//			mergeSort(data, M + 1, R);
//			merge(data, L, M, R);
//		}
//	}
//	void merge(vector<int>&data, int L, int M, int R)
//	{
//		vector<int>temp(R - L + 1);
//		int t = R - L;
//		int tL = M;
//		int tR = R;
//		while (tL >= L && tR >= M + 1)
//		{
//			if (data[tL] > data[tR])
//			{
//				count += tR - M;
//				temp[t--] = data[tL--];
//				count %= 1000000007;
//			}
//			else
//				temp[t--] = data[tR--];
//		}
//		while (tL >= L)
//			temp[t--] = data[tL--];
//		while (tR >= M + 1)
//			temp[t--] = data[tR--];
//		for (int i = 0; i <= R - L; ++i)
//			data[L + i] = temp[i];
//	}
//};
//int main()
//{
//	Solution02 s;
//	cout << s.InversePairs({1,2,3,4}) << endl;
//	cout << s.InversePairs({ 1,2,3,4,5,6,7,0 }) << endl;
//	cout << s.InversePairs({ 2,4,6,8,1,3,5,7 }) << endl;
//	cout << s.InversePairs({ 2,4,6,8,5,3,1,7 }) << endl;
//	return 0;
//}