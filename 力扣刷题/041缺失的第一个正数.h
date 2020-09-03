#include "000库函数.h"


//先排序，然后找值
//自己的解法 12ms
//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		sort(nums.rbegin(),nums.rend());//对数组进行逆序排序
//		for (int i = nums.size() - 1; i >= 0; --i)
//			if (nums[i] < 1)nums.pop_back();//将小于1的数删除
//		if (nums.size() == 0 || nums[nums.size()-1] > 1)return 1;//若数组为空或者最小值大于1，则返回1
//		if (nums.size() == 1)return nums[0] == 1 ? 2 : 1;//当且只有1个元素时，若是1，就返回2否则返回1
//		for (int i = nums.size() - 2; i >= 0; --i) {
//			if (nums[i] - nums[i + 1] > 1)//找到间隔大于1的相邻两数，
//				return nums[i + 1] + 1;//返回较小数+1
//		}		
//		return nums[0] + 1;//返回最大数+1
//	}
//};


//第二种解法更好用
//先排序，将小于1的数删除，然后存入剩下的数，若数组下角标不是该值，则返回该数
//我以为会很快，但都是12ms,但点子很好，你觉得呢？
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());//排序
		vector<int>v;
		v.push_back(0);//将0与下标为0的位置占用
		for (int i = 0, j = 0; i < nums.size(); ++i) {
			if (nums[i] < 1 || nums[i] == v.back())continue;//排除小于1的数和去除重复数字
			v.push_back(nums[i]);
			++j;
			if (j != nums[i])return j;//小角标未与该处的数字对应
		}	
		return v.back() + 1;//原数组是连续的，返回最大数+1；
	}
};


//博客的解答
//我怎么感觉复杂一丢丢
//除了排序是自己做的，原理都一样，找下角标
//同样12ms
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
};

void T041() {
	Solution s;
	vector<int>n;
	n = {2,1 };
	cout << s.firstMissingPositive(n) << endl;
	n = { 3,4,-1,1 };
	cout << s.firstMissingPositive(n) << endl;
	n = { 7,8,9,11,12 };
	cout << s.firstMissingPositive(n) << endl;
	n = {100,-9};
	cout << s.firstMissingPositive(n) << endl;
	n = { 0,2,2,1,1 };
	cout << s.firstMissingPositive(n) << endl;
}