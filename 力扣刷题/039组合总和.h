#include "000�⺯��.h"

//��һ�о�ʹ�û��ݱȽϿ�
//�ü�������һ��ʹ�û��ݳɹ� 96ms,37.1M


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>Res;
		if (candidates.size() == 0)return Res;			
		vector<int>v;//��ʱ��Ž�			
		Combin(candidates, Res,v, target, 0, 0);		
		return Res;
	}

	void Combin(vector<int>candidates, vector<vector<int>>&Res, vector<int>&v, int target, int start, int sum) {
		if (sum == target) {
			Res.push_back(v);
			return;
		}
		else if (sum > target)
			return;
		for (int i = start; i < candidates.size(); ++i) {
			v.push_back(candidates[i]);
			Combin(candidates, Res, v, target, i, sum + candidates[i]);
			v.pop_back();//�������˳�
		}
	}

};


//���ʹ�
//�ⷨһ
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i) {
			if (candidates[i] > target) break;
			if (candidates[i] == target) { res.push_back({ candidates[i] }); break; }
			vector<int> vec = vector<int>(candidates.begin() + i, candidates.end());
			vector<vector<int>> tmp = combinationSum(vec, target - candidates[i]);
			for (auto a : tmp) {
				a.insert(a.begin(), candidates[i]);
				res.push_back(a);
			}
		}
		return res;
	}
};

//�ⷨ��
//����һ����ά����dp������dp[i]��ʾĿ����Ϊi�����нⷨ���ϡ�
//�����i�ʹ�1������target���ɣ�����ÿ��i�����Ƕ��½�һ����ά����cur��
//Ȼ�����candidates���飬��������������ִ���i��˵����ǰ��֮������ֶ��޷����i��
//ֱ��break�������������ȣ���ô�ѵ�ǰ�����Լ����һ�����飬���Ҽӵ�cur�С�
//����ͱ���dp[i - candidates[j] - 1] �е��������飬�����ǰ���ִ����������Ԫ�أ�
//����������Ϊ���ǵĽ��Ҫ����Ҫ����ġ�����ͽ���ǰ���ּ�������Ŀ�ͷ��
//���ҽ��������cur֮�м��ɣ��μ��������£�

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<vector<int>>> dp;
		sort(candidates.begin(), candidates.end());
		for (int i = 1; i <= target; ++i) {
			vector<vector<int>> cur;
			for (int j = 0; j < candidates.size(); ++j) {
				if (candidates[j] > i) break;
				if (candidates[j] == i) { cur.push_back({ candidates[j] }); break; }
				for (auto a : dp[i - candidates[j] - 1]) {
					if (candidates[j] > a[0]) continue;
					a.insert(a.begin(), candidates[j]);
					cur.push_back(a);
				}
			}
			dp.push_back(cur);
		}
		return dp[target - 1];
	}
};

void T039() {
	vector<int> v;	
	vector<vector<int>>Res;
	Solution s;
	v = { 2, 3, 6, 7 };
	Res = s.combinationSum(v, 7);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl<<"*********"<< endl;
	v = { 2, 3,5 };
	Res = s.combinationSum(v, 8);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "*********" << endl;



}