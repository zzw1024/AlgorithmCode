//#include "000¿âº¯Êý.h"
//
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		int m = nums1.size(), n = nums2.size();
//		int i = 0, j = 0, k = 0, mid = (m + n) / 2 + ((m + n) % 2 == 0 ? 0 : 1);
//		double sum = 0.0;
//		while (i < m && j < n)
//		{
//			if (nums1[i] <= nums2[j])sum += nums1[i++];
//			else sum += nums2[j++];
//			++k;
//			if (isReturn(sum, k, mid, m + n))return sum;
//		}
//		while (i < m)
//		{
//			sum += nums1[i++];
//			++k;
//			if (isReturn(sum, k, mid, m + n))return sum;
//		}
//		while (j < n)
//		{
//			sum += nums2[j++];
//			++k;
//			if (isReturn(sum, k, mid, m + n))return sum;
//		}
//		return sum;
//	}
//	bool isReturn(double &sum, int k, int mid, int s)
//	{
//		if (k < mid)
//		{
//			sum = 0.0;
//			return false;
//		}
//		else if (k == mid && s % 2 == 1)
//			return true;
//		else if (k == mid + 1)
//		{
//			sum /= 2.0;
//			return true;
//		}
//		return false;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int>v1 = { 4,5,6,7,8,9,10 }, v2 = { 1,2,3};
//	cout << s.findMedianSortedArrays(v1, v2) << endl;
//	return 0;
//}