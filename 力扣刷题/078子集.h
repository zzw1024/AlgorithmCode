#include "_000�⺯��.h"


//����������ͬ���Ӽ�����
class solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())return { {} };
		vector<vector<int>>res;
		res.push_back({});		
		for (int i = 1; i <= nums.size(); ++i) {
			vector<int>v;
			helper(nums, i, 0, v, res);//��ͬ�������Ӽ�
		}
		return res;
	}

	void helper(vector<int>& nums, int k, int level, vector<int>&v, vector<vector<int>>&res) {
		if (v.size() == k) {
			res.push_back(v);
			return;
		}
		for (int i = level; i < nums.size(); ++i) {
			v.push_back(nums[i]);
			helper(nums, k, i + 1, v, res);
			v.pop_back();
		}
	}
	
};

//ʹ�õ��ӷ���
//ÿ����ԭ����Ļ����ϼ�����������
//���������Ŀ�и�������[1, 2, 3]��˵���ʼ�ǿռ���
//��ô��������Ҫ����1�����ڿռ��ϼ�1��Ϊ[1]�����������������Լ�[]��[1]��
//��������������2��������֮ǰ���Ӽ������ϣ�ÿ�����Ӹ�2�����Էֱ�õ�[2]��[1, 2]��
//��ô�������е��Ӽ���Ϊ[], [1], [2], [1, 2]��ͬ����3������ɵ�[3], [1, 3], [2, 3], [1, 2, 3],
//�ټ���֮ǰ���Ӽ��������е��Ӽ����ˣ��������£�
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())return { {} };
		vector<vector<int>>res;
		res.push_back({});
		for (int i = 0; i < nums.size(); ++i) {
			int n = res.size();
			for (int j = 0; j < n; ++j) {
				vector<int>v = res[j];
				v.push_back(nums[i]);//����µ�����
				res.push_back(v);
			}
		}
		return res;
	}
};


void T078() {
	Solution s;
	vector<int>n = { 1,2,3 };
	vector<vector<int>>v;
	v = s.subsets(n);
	for (auto a : v) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
}