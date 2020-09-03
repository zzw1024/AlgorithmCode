#include "_000�⺯��.h"

//�ϲ�������������
//�ܼ򵥣������ٿ��ٿռ䣬��num1�иı����
//��ͷ��ʼ�Ƚ�
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums2.empty())return;
		if(nums1.empty()){
			nums1 = nums2;
			return;
		}
		for (int i = 0, j = 0; i < m + n && j < n; ++i) {
			if (i==m) {
				nums1[i] = nums2[j];
				++j;
				++m;
				continue;
			}
			if (nums1[i] <= nums2[j]) continue;
			for (int k = 0; m - k > i; ++k)nums1[m - k] = nums1[m - k - 1];//����
			++m;
			nums1[i] = nums2[j];
			++j;
		}
	}
};
//��β��ʼ�Ƚ�
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, p = m + n - 1;
		while (j >= 0) {
			nums1[p--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
		}
	}
};


void T088() {
	Solution s;
	vector<int>v1, v2;
	v1 = { 1,2,3,0,0,0 };
	v2 = { 2,5,6};
	s.merge(v1,3, v2, 3);
	for (auto a : v1)
		cout << a << "  ";
	cout << endl;
}