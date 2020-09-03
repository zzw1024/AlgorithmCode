#include "_000�⺯��.h"

//һ���ۿ�����Ŀ�������������������㷨
//ʱ���е㳤588ms

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int>v;
		for (int i = 1; i <= n; ++i)
			v.push_back(i);
		--k;
		while (next_permutation(v.begin(), v.end()) && --k);
		string s = "";
		for (auto a : v)
			s += a + '0';
		return s;
	}
};

//��һ�µݹ�
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int>v;
		for (int i = 1; i <= n; ++i)
			v.push_back(i);
		Combin(v, 1, 0);
		string s = "";
		for (auto a : v)
			s += a + '0';
		return s;
	}
	void Combin(vector<int>&v, int k, int s) {
		if (!k)return;
		if (s >= v.size())--k;		
		for (int i = s; i < v.size(); ++i) {
			swap(v[i], v[s]);
			Combin(v, k, s + 1);
			swap(v[i], v[s]);
		}
	}
};
	
//���ʹ𰸣�û��ô����
//���ڿ����ٸ���
//12ms
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		string num = "123456789";
		vector<int> f(n, 1);
		for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
		--k;
		for (int i = n; i >= 1; --i) {
			int j = k / f[i - 1];
			k %= f[i - 1];
			res.push_back(num[j]);
			num.erase(j, 1);
		}
		return res;
	}
};


void T060() {
	Solution s;
	cout << s.getPermutation(3, 3) << endl;
	cout << s.getPermutation(4, 9) << endl;
}