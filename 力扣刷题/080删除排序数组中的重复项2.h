#include "_000库函数.h"


//该题目要求不允许使用额外的内存空间
//只能在原数组上动手
//又因为数组是排序数组，故简单点
//测试完才发现，题目是让你将多余的数据向后移，后台根据你 返回数组长度打印数组
//原来不是返回长度那么简单

//方法一，使用删除
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)return nums.size();
		int n = 0, res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			n = 1;
			while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {				
				++n;
				++i;
			}		
			if (n > 2) {
				vector<int>::iterator pt = nums.begin() + res+1;
				nums.erase(pt, pt + n - 2);//删除多余的元素
				i -= n - 2;
			}
			res += n > 2 ? 2 : n;
		}
		return res;
	}
};


void T080() {
	Solution s;
	vector<int>v;
	v = { 1, 1, 1, 2, 2, 3 };
	cout << s.removeDuplicates(v) << endl;
	for (auto a : v)
		cout << a << " ";
	cout << endl;
	v = { 0,0,1,1,1,1,2,3,3 };
	cout << s.removeDuplicates(v) << endl;
	for (auto a : v)
		cout << a << " ";
	cout << endl;
}