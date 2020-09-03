#include "000�⺯��.h"


//ʹ�û��ݷ�������
//����ⷨΪ���ݵݹ飬һ��һ�������ɨ�裬��Ҫ�õ�һ��pos���飬
//����pos[i]��ʾ��i�лʺ��λ�ã���ʼ��Ϊ - 1��Ȼ��ӵ�0��ʼ�ݹ飬
//ÿһ�ж�һ�α������У��ж�����ڸ�λ�÷��ûʺ�᲻���г�ͻ���Դ����ƣ�
//�������һ�еĻʺ�źú�һ�ֽⷨ�������ˣ����������res�У�
//Ȼ���ٻ����������������е�������������£�17ms
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {		
		vector<vector<string>>res;
		vector<int>pos(n, -1);
		NQueue(res, pos, 0);
		return res;
	}
	
	void NQueue(vector<vector<string>>&res, vector<int>&pos, int t) {
		int n = pos.size();
		if (t == n) {//��ϳɹ�
			vector<string>v(n, string(n, '.'));//���ʼ��������
			for (int i = 0; i < n; ++i)
				v[i][pos[i]] = 'Q';
			res.push_back(v);
		}
		else
			for (int k = 0; k < n; ++k)
				if (Danger(pos, t, k)) {
					pos[t] = k;
					NQueue(res, pos, t + 1);
					pos[t] = -1;//�мǣ��ؼ��㣬����
				}
	}

	bool Danger(vector<int>pos, int t, int k) {
		for (int i = 0; i < t; ++i)
			if (pos[i] == k || abs(t - i) == abs(pos[i] - k))
				return false;
		return true;
	}

};


//ͨ��ʹ�����н����ж��Ƿ���н������
//����̫��ʱ�ˣ������û��ݷ���
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>>res;
		vector<int>nums;
		for (int i = 0; i < n; ++i)
			nums.push_back(i);

		if (Danger(nums)) {
			vector<string>v;
			for (int i = 0; i < n; ++i) {
				string s = "";
				for (int k = 0; k < nums[i]; ++k)
					s += '.';
				s += 'Q';
				for (int k = nums[i] + 1; k < n; ++k)
					s += '.';
				v.push_back(s);
			}
			res.push_back(v);
		}
		while (next_permutation(nums.begin(), nums.end())) {
			if (Danger(nums)) {
				vector<string>v;
				for (int i = 0; i < n; ++i) {
					string s = "";
					for (int k = 0; k < nums[i]; ++k)
						s += '.';
					s += 'Q';
					for (int k = nums[i] + 1; k < n; ++k)
						s += '.';
					v.push_back(s);
				}
				res.push_back(v);
			}
		}
		return res;
	}
				


	bool Danger(vector<int>nums) {//�����ж��Ƿ����
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (j == i)continue;
				if ((j + nums[j]) == (i + nums[i]) || (i - nums[i]) == (j - nums[j]))
					return false;
			}
		}
		return true;
	}
					

};


void T051() {
	Solution s;
	vector<vector<string>>v;
	int n;
	n = 5;
	v = s.solveNQueens(n);
	for (auto &a : v) {
		for (auto b : a)
			cout << b << endl;
		cout << "//////////////////////////" << endl;
	}
	
}