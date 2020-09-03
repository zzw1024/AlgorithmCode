#include <iostream>
#include <vector>

using namespace std;

//【题目】
//给定数组arr，arr中所有的值都为正数且不重复。
//每个值代表一种面值的货币，每种面值的货币可以使用任意张，
//再给定一个整数aim代表要找的钱数，求换钱有多少种方法。
//【举例】
//arr = [5, 10, 25, 1]，aim = 0。
//组成0元的方法有1种，就是所有面值的货币都不用。所以返回1。
//arr = [5, 10, 25, 1]，aim = 15。
//组成15元的方法有6种，分别为3张5元、1张10元 + 1张5元、1张10元 + 5张1元、10张1元 + 1张5元、2张5元 + 5张1元和15张1元。所以返回6。
//arr = [3, 5]，aim = 2。
//任何方法都无法组成2元。所以返回0
//【题解】
//1、暴力解法：
//使用递归，判断每种面值的钱使用不同数量的组合总数
//
//2、使用动态规划法



///纯递归法
int process1(vector<int>v, int index, int aim)
{
	int res = 0;
	if (index == v.size())
		res = aim == 0 ? 1 : 0;
	else
	{
		for (int i = 0; v[index] * i <= aim; ++i)
			res += process1(v, index + 1, aim - v[index] * i);
	}
	return res;
}

int coins1(vector<int>v, int aim)
{
	if (v.size() == 0 || aim < 0)
		return 0;
	return process1(v, 0, aim);
}

///自顶向下的备忘录
int process2(vector<int>v, int index, int aim, vector<vector<int>>dp)
{
	int res = 0;
	if (index == v.size())
		res = aim == 0 ? 1 : 0;
	else
	{
		int val = 0;
		for (int i = 0; v[index] * i <= aim; ++i)
		{
			val = dp[index + 1][aim - v[index] * i];
			if (val != 0)
				res += val == -1 ? 0 : val;
			else
				res += process2(v, index + 1, aim - v[index] * i, dp);
		}
	}
	dp[index][aim] = res == 0 ? -1 : res;
	return res;
}

int coins2(vector<int>v, int aim)
{
	if (v.size() == 0 || aim < 0)
		return 0;
	vector<vector<int>>dp(v.size() + 1, vector<int>(aim + 1, 0));
	return process2(v, 0, aim, dp);
}

///自底向上法

int process3(vector<int>v, int aim)
{
	vector<vector<int>>dp(v.size(), vector<int>(aim + 1, 0));
	for (int i = 0; i < v.size(); ++i)
		dp[i][0] = 1;
	for (int j = 1; v[0] * j <= aim; ++j)
		dp[0][v[0] * j] = 1;//就是第一种面额最高能使用多少张？
	for(int i=1;i<v.size();++i)
		for (int j = 1; j <= aim; ++j)
		{
			int num = 0;
			for (int k = 0; j - v[i] * k >= 0; ++k)
				num += dp[i - 1][j - v[i] * k];
			dp[i][j] = num;
		}
	
	return dp[v.size() - 1][aim];
}

int process4(vector<int>v, int aim)
{
	vector<vector<int>>dp(v.size(), vector<int>(aim + 1, 0));
	for (int i = 0; i < v.size(); ++i)
		dp[i][0] = 1;
	for (int j = 1; v[0] * j <= aim; ++j)
		dp[0][v[0] * j] = 1;//就是第一种面额最高能使用多少张？
	for (int i = 1; i < v.size(); ++i)
		for (int j = 1; j <= aim; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += j - v[i] >= 0 ? dp[i][j - v[i]] : 0;
		}
	return dp[v.size() - 1][aim];
}

int process5(vector<int>v, int aim)
{
	vector<int>dp(aim + 1, 0);
	for (int j = 0; v[0] * j <= aim; ++j)
		dp[v[0] * j] = 1;//就是第一种面额最高能使用多少张？
	for (int i = 1; i < v.size(); ++i)
		for (int j = 1; j <= aim; ++j)
			dp[j] += j - v[i] >= 0 ? dp[j - v[i]] : 0;
		
	return dp[aim];
}

int coins3(vector<int>v, int aim)
{
	if (v.size() == 0 || aim < 0)
		return 0;	
	return process3(v, aim);
}

void Test()
{
	vector<int>v;
	int aim;
	v = { 5, 10, 25, 1 };
	aim = 0;
	cout << coins1(v, aim) << endl;

	v = { 5, 10, 25, 1 };
	aim = 15;
	cout << coins2(v, aim) << endl;

	v = { 3,5 };
	aim = 2;
	cout << coins1(v, aim) << endl;
}