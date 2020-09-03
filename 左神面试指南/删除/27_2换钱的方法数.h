#include <iostream>
#include <vector>

using namespace std;

//����Ŀ��
//��������arr��arr�����е�ֵ��Ϊ�����Ҳ��ظ���
//ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ�
//�ٸ���һ������aim����Ҫ�ҵ�Ǯ������Ǯ�ж����ַ�����
//��������
//arr = [5, 10, 25, 1]��aim = 0��
//���0Ԫ�ķ�����1�֣�����������ֵ�Ļ��Ҷ����á����Է���1��
//arr = [5, 10, 25, 1]��aim = 15��
//���15Ԫ�ķ�����6�֣��ֱ�Ϊ3��5Ԫ��1��10Ԫ + 1��5Ԫ��1��10Ԫ + 5��1Ԫ��10��1Ԫ + 1��5Ԫ��2��5Ԫ + 5��1Ԫ��15��1Ԫ�����Է���6��
//arr = [3, 5]��aim = 2��
//�κη������޷����2Ԫ�����Է���0
//����⡿
//1�������ⷨ��
//ʹ�õݹ飬�ж�ÿ����ֵ��Ǯʹ�ò�ͬ�������������
//
//2��ʹ�ö�̬�滮��



///���ݹ鷨
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

///�Զ����µı���¼
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

///�Ե����Ϸ�

int process3(vector<int>v, int aim)
{
	vector<vector<int>>dp(v.size(), vector<int>(aim + 1, 0));
	for (int i = 0; i < v.size(); ++i)
		dp[i][0] = 1;
	for (int j = 1; v[0] * j <= aim; ++j)
		dp[0][v[0] * j] = 1;//���ǵ�һ����������ʹ�ö����ţ�
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
		dp[0][v[0] * j] = 1;//���ǵ�һ����������ʹ�ö����ţ�
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
		dp[v[0] * j] = 1;//���ǵ�һ����������ʹ�ö����ţ�
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