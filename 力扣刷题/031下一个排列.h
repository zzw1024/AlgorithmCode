#pragma once
#include "000�⺯��.h"

//�Խⷨ 20ms
//ʹ��һ�鷨�������������αȽ������������֣������Ƿ�Ϊ��������[���������޸����������]
//��������������ʱ��ֻ��Ҫ���˴������������Ҷ˱����һ���������н������ٽ���i-1���Ҷ˵���������������
//�͵õ���Ŀǰ��һ���������
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0)return;
		int flag = 1;//�������ԭ�����Ƿ����ٴ������
		for (int i = nums.size() - 1; i > 0; --i) {//���Ҷ˿�ʼ�Ƚ�
			if (nums[i - 1] < nums[i])//�˴�Ϊ��������		
				for (int j = nums.size() - 1; j > i - 1; --j) //�ҵ���[i-1]��һ������
					if (nums[i - 1] < nums[j]) {
						swap(nums[i-1],nums[j]);						
						flag = 0;//���ڸ��������
						sort(nums.begin()+i, nums.end()); //�ٽ���i - 1���Ҷ˵���������������
						return;
					}
		}
		if (flag)//���ٴ�������ˣ���ô�ͷ�����С����
			sort(nums.begin(), nums.end());
		return;
	}
};

//ʹ��C++�����к���next_permutation  32ms
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (!(next_permutation(nums.begin(), nums.end())))//���û�и����������
			sort(nums.begin(), nums.end());//�Ǿͷ���������С���С�
	}
};

//���ʹ���
//���Լ��Ľⷨһ����ֻ�����������࣬ʱ��һ�����ڴ����һ���
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