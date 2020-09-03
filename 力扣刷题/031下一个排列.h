#pragma once
#include "000库函数.h"

//自解法 20ms
//使用一遍法，从右向左依次比较相邻两个数字，看其是否为降序排列[降序排列无更大的排列了]
//当出现升序排列时，只需要将此处的数字与其右端比其大一点点的数进行交换，再将【i-1】右端的数进行升序排列
//就得到比目前大一点的排列了
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0)return;
		int flag = 1;//用来标记原排列是否无再大的排列
		for (int i = nums.size() - 1; i > 0; --i) {//从右端开始比较
			if (nums[i - 1] < nums[i])//此处为升序排列		
				for (int j = nums.size() - 1; j > i - 1; --j) //找到比[i-1]大一点点的数
					if (nums[i - 1] < nums[j]) {
						swap(nums[i-1],nums[j]);						
						flag = 0;//存在更大的排列
						sort(nums.begin()+i, nums.end()); //再将【i - 1】右端的数进行升序排列
						return;
					}
		}
		if (flag)//无再大的排列了，那么就返回最小排列
			sort(nums.begin(), nums.end());
		return;
	}
};

//使用C++的排列函数next_permutation  32ms
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (!(next_permutation(nums.begin(), nums.end())))//如果没有更大的排列了
			sort(nums.begin(), nums.end());//那就返回升序【最小排列】
	}
};

//博客代码
//与自己的解法一样，只不过代码更简洁，时间一样，内存多了一点点
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), i = n - 2, j = n - 1;
		while (i >= 0 && nums[i] >= nums[i + 1]) --i;
		if (i >= 0) {
			while (nums[j] <= nums[i]) --j;
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};


void T031() {
	vector<int>v;
	Solution s;
	v = { 1,2,3 };	
	for (auto i : v)
		cout << i << '\t';
	cout << endl;
	s.nextPermutation(v);
	for (auto i : v)
		cout << i << '\t';
	cout << endl;
	cout << "*************" << endl;
	v = { 6,5,4 };
	for (auto i : v)
		cout << i << '\t';
	cout << endl;
	s.nextPermutation(v);
	for (auto i : v)
		cout << i << '\t';
	cout << endl;
	cout << "*************" << endl;
	v = { 1,5,8,4,7,6,5,3,1 };
	for (auto i : v)
		cout << i << '\t';
	cout << endl;
	s.nextPermutation(v);
	for (auto i : v)
		cout << i << '\t';
	cout << endl;
	cout << "*************" << endl;
}