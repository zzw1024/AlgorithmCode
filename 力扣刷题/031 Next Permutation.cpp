//#include "000�⺯��.h"
//
////���������������һ������˳������Ŀ�и������ӿ��Կ�������
////������������ǽ�����˵����ȫ���е����һ�����������һ�����о������ʼ�����
////�����µ�һ������
////1����2����7����4����3����1
////��һ������Ϊ��
////1����3����1����2����4����7
////��ô����εõ����أ�����ͨ���۲�ԭ������Է��֣�
////�����ĩβ��ǰ���������𽥱�󣬵���2ʱ�ż�С�ģ�
////Ȼ���ٴӺ���ǰ�ҵ�һ����2������֣���3����ô���ǽ���2��3��
////�ٰѴ�ʱ3�������������ת��һ�¼��ɣ��������£�
//
//
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		if (nums.size() < 2)return;
//		int n = nums.size(), minN = n - 2, maxN = n - 1;
//		while (minN >= 0 && nums[minN] >= nums[minN + 1])
//			--minN;//�ҵ��Ӻ���ǰ���ǵ�����λ��
//		if (minN<0)//ԭ����Ϊ����
//		{
//			sort(nums.begin(), nums.end());
//			return;
//		}
//		while (maxN >= 0 && nums[maxN] <= nums[minN])--maxN;
//		swap(nums[minN], nums[maxN]);
//		for (int i = minN + 1, j = n - 1; i <= j; ++i, --j)//��ת���������
//			swap(nums[i], nums[j]);
//	}
//};
//
//
////�����İ汾
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		int n = nums.size(), minN = n - 2, maxN = n - 1;
//		while (minN >= 0 && nums[minN] >= nums[minN + 1])
//			--minN;//�ҵ��Ӻ���ǰ���ǵ�����λ��
//		if (minN >= 0)
//		{
//			while (maxN >= 0 && nums[maxN] <= nums[minN])--maxN;
//			swap(nums[minN], nums[maxN]);
//		}
//		reverse(nums.begin() + minN + 1, nums.end());
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int>v = { 1,1 };
//	s.nextPermutation(v);
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}