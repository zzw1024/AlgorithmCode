#include "000�⺯��.h"

//��һ�о�ʹ�û��ݱȽϿ�
//96ms


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>>R;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0)return R;
		vector<int>v;//��ʱ��Ž�	
		Combin(candidates, R, v, target, 0, 0);		
		return R;
	}

	void Combin(vector<int>candidates, vector<vector<int>>&Res, vector<int>&v, int target, int start, int sum) {
		if (sum == target) {
			//sort(v.begin(), v.end());
			Res.push_back(v);
			return;
		}
		else if (sum > target)
			return;

		for (int i = start; i < candidates.size(); ++i) {
			if (i > start&&candidates[i] == candidates[i - 1])continue;//ȥ���ظ������			
			v.push_back(candidates[i]);
			Combin(candidates, Res, v, target, i + 1, sum + candidates[i]);//i+1��������Ĳ�֮ͬ������������ظ�ʹ��Ԫ��
			v.pop_back();//�������˳�				
		}
	}

};

void T040() {
	vector<int> v;
	vector<vector<int>>Res;
	Solution s;
	v = {10,1,2,7,6,1,5 };
	Res = s.combinationSum2(v, 8);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "*********" << endl;
	/*v = { 2, 3,5 };
	Res = s.combinationSum(v, 8);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "*********" << endl;
*/


}