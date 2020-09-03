#include "000�⺯��.h"


//ʹ�����򣬸о������ף�������Ŀû˵������
//24ms
class solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>res;
		if (nums.empty())return res;
		sort(nums.begin(), nums.end());//����
		do {
			res.push_back(nums);				
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

//ʹ�õݹ�
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>Res;
		if (nums.empty())return Res;
		Combin(Res, nums, 0);//����
		return Res;
	}
	void Combin(vector<vector<int>>&Res, vector<int>v, int s) {
		if (s >= v.size()) //�˴���return����for�н������Զ�����
			Res.push_back(v);
			
		for (int i = s; i < v.size(); ++i) {
			swap(v[s], v[i]);//����
			Combin(Res, v, s + 1);//����
			swap(v[s], v[i]);//������
		}
	}

};

////ʹ��DFS�ݹ�
class Solution {
public:
	vector<vector<int>> permute(vector<int>& num) {
		vector<vector<int>> res;
		vector<int> out, visited(num.size(), 0);
		permuteDFS(num, 0, visited, out, res);
		return res;
	}
	void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
		if (level == num.size()) { res.push_back(out); return; }//���ִ�С�ﵽҪ��
		for (int i = 0; i < num.size(); ++i) {
			if (visited[i] == 1) continue;
			visited[i] = 1;//�������Ѿ�ѡ��
			out.push_back(num[i]);
			permuteDFS(num, level + 1, visited, out, res);
			out.pop_back();//����
			visited[i] = 0;
		}
	}
};

//��n = 1ʱ��������ֻ��һ����a1����ȫ����ֻ��һ�֣���Ϊa1
//
//��n = 2ʱ�������д�ʱ��a1a2����ȫ���������֣�a1a2��a2a1����ô��ʱ���ǿ��Ǻ�������������Ĺ�ϵ�����Ƿ��֣���ʵ������a1��ǰ������λ�÷ֱ������a2
//
//��n = 3ʱ����������a1a2a3����ʱȫ���������֣��ֱ�Ϊa1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, �� a3a2a1����ô��������Ľ��ۣ�ʵ��������a1a2��a2a1�Ļ������ڲ�ͬ��λ���ϼ���a3���õ��ġ�
//
//_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3
//
//_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3
class Solution {
public:
	vector<vector<int>> permute(vector<int>& num) {
		vector<vector<int>> res;
		if (num.empty()) return res;		
		int first = num[0];
		num.erase(num.begin());//ɾ��������
		vector<vector<int>> words = permute(num);
		for (auto &a : words) {
			for (int i = 0; i <= a.size(); ++i) {
				a.insert(a.begin() + i, first);
				res.push_back(a);
				a.erase(a.begin() + i);
			}
		}
		return res;
	}
};

void T046() {
	vector<int>n;
	Solution s;
	n = { 1,2,3 };
	for (auto &a : s.permute(n)) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}

}