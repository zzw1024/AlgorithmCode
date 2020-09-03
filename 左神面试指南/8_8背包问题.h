#pragma once
#include <iostream>
#include <vector>
#include <set>

using namespace std;


int MaxValue1(vector<int>w, vector<int>v,int i, int wsum, int bag)//使用递归
{
	if (wsum > bag)
		return 0;
	if (i == w.size())
		return 0;
	return	((MaxValue1(w, v, i + 1, wsum, bag)) >
		(v[i] + MaxValue1(w, v, i + 1, wsum + w[i], bag)) ?
		(MaxValue1(w, v, i + 1, wsum, bag)) :
		(v[i] + MaxValue1(w, v, i + 1, wsum + w[i], bag)));
}

int MaxValue2(vector<int>w, vector<int>v, int bag)//使用动态规划
{
	vector<vector<int>> dp(w.size() + 1, vector<int>(bag + 1, 0));
	for(int i = w.size()-1;i>=0;--i)
		for (int j = bag; j >= 0; --j)
		{
			dp[i][j] = dp[i + 1][j];
			if (j + w[i] <= bag)
				dp[i][j] = dp[i][j] > (v[i] + dp[i + 1][j + w[i]]) ? dp[i][j] : (v[i] + dp[i + 1][j + w[i]]);
		}
	return dp[0][0];
}

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string>res;
		if (str.size() == 0)
		{
			return res;
		}
		set<string>ss;
		Resctive(ss, str, 0);
		res.assign(ss.begin(), ss.end());
		return res;
	}
	void Resctive(set<string>&res, string s, int i)
	{
		if (i >= s.size())
			res.insert(s);
		else
		{
			for (int j = i; j < s.size(); ++j)
			{
				swap(s[i], s[j]);
				Resctive(res, s, i + 1);
				swap(s[i], s[j]);
			}

		}
	}
	void swap(char &a, char &b)
	{
		char temp;
		temp = a;
		a = b;
		b = temp;
	}
};



void Test()
{
	//vector<int>w;
	//vector<int>v;
	//set<string>s;
	//
	//w = { 3,2,4,7 };
	//v = { 5,6,3,19 };
	//int bag = 11;
	//cout << MaxValue1(w, v, 0, 0, bag) << endl;
	//cout << MaxValue2(w, v, bag) << endl;


}