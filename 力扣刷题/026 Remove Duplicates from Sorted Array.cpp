//#include "000�⺯��.h"
//
////ʹ��vector��ɾ������
//class Solution2 {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		for (int i = 1; i < nums.size(); ++i)
//			if (nums[i] == nums[i - 1])
//			{
//				nums.erase(nums.begin() + i);
//				--i;
//			}
//		return nums.size();
//	}
//};
//
////���ڲ����������ռ䣬���ԣ�ʹ�ò�������˼��
//class Solution1 {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int res = 0, n = nums.size();
//		for (int i = 1; i < n - res; ++i)
//		{
//			if (nums[i] == nums[i - 1])
//			{
//				++res;//ͳ���ظ�������
//				int temp = nums[i], j = i + 1;
//				while (j < n - res + 1)//���ظ��������Ⱥ��ƶ�
//				{
//					nums[j - 1] = nums[j];
//					++j;
//				}
//				nums[j - 1] = temp;
//				--i;
//			}
//		}
//		nums.erase(nums.begin() + (n-res), nums.end());
//		return n - res;
//	}
//};
//
////Ū�˰��죬����ɾ��nums���ظ����֣�����
////ֻ������Ҫ�����ظ������ַ���ǰ��
////ʹ��˫ָ��
//class Solution {
//public:
	//int removeDuplicates(vector<int>& nums) {
	//	int pre = 0, cur = 0, res = 0;
	//	while (cur < nums.size())
	//	{
	//		if (nums[pre] == nums[cur])
	//			++cur;
	//		else
	//		{
	//			nums[++res] = nums[cur];//����ͬ�������ƶ���ǰ��
	//			pre = cur;
	//		}
	//	}
	//	return nums.empty() ? 0 : res + 1;
	//}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int>v = { 1,1,1,2,2,3,3,3,3 };
//	cout << s.removeDuplicates(v) << endl;
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}
