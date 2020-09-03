#include "_000库函数.h"

//本来使用sort函数简单无比
//但是题目要求不让使用排序函数

//解法一：计数再生成【两趟扫描】

//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int r = 0, w = 0, b = 0;//三种颜色出现次数计数
//		for (auto a : nums)
//			if (a == 0)++r;
//			else if (a == 1)++w;
//			else ++b;
//		nums.clear();//重置
//		nums.insert(nums.end(), r, 0);
//		nums.insert(nums.end(), w, 1);
//		nums.insert(nums.end(), b, 2);
//	}
//};

//解法二，使用一趟扫描法
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0;i<n;){
			vector<int>::iterator p = nums.begin() + i;
			if (nums[i] == 0) {
				nums.erase(p, p + 1);//删除
				nums.insert(nums.begin(), 1, 0);//前插
				++i;
			}
			else if (nums[i] == 2) {
				nums.erase(p, p + 1);//删除
				nums.insert(nums.end(), 1, 2);//后插
				--n;
			}
			else//让1保留在原位
				++i;
		}
	}
};


void T075() {
	Solution s;
	vector<int>v;
	v = { 2,0,2,1,1,0 };
	s.sortColors(v);
	for (auto a : v)
		cout << a << "， ";
	cout << endl;
}