#include <iostream>
#include <vector>

using namespace std;
//【题目】
//初始给定0~n - 1共N个位置，机器人在M位置上，机器人即可以向左或向右走
//请问：走了P步走到K位置的走法共有多少种？

//共N个位置
//p共走的步数
//s开始的步数
//e最终到达的位置

///使用递归
int calSteps(int N, int p, int s, int e)
{
	if (N < 2 || s<1 || s>N || p < 0 || e<1 || e>N)//越界...1
		return 0;
	if (p == 0)//步数走完了...2
		return s == e ? 1 : 0;
		//return s == e ? 1 : 0;
	int res = 0;
	//开始走了，按照边界进行分类
	if (s == 1)//...3
		res += calSteps(N, p - 1, s + 1, e);//只能向右走
	else if (s == N)//...4
		res += calSteps(N, p - 1, s - 1, e);//只能向左走
	else//...5
	{
		res += calSteps(N, p - 1, s - 1, e);//向左走或者向右走
		res += calSteps(N, p - 1, s + 1, e);//向左走或者向右走
	}
	return res;
}

///使用动态规划
int calStep_(int N, int p, int s, int e)
{
	if (N < 2 || s<1 || s>N || p < 0 || e<1 || e>N)//越界对应1
		return 0;
	vector<vector<int>>dp(p + 1, vector<int>(N + 1, 0));
	dp[0][e] = 1;//当剩余步数达到e的位置时，则返回一个正确的步数//对应3，剩余步数为0是
	for (int i = 1; i <= p; ++i)
	{
		for (int j = 1; j <= N; ++j)//对应3的情况直接被边界1给去除了
		{
			if (j + 1 > N)
				dp[i][j] = dp[i - 1][j - 1];//对应4,因为i为步数，j为位置数
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}
	return dp[p][s];//回到最初的位置
}


void Test()
{
	cout << calSteps(6, 5, 2, 5) << endl;
	cout << calStep_(6, 5, 2, 5) << endl;
}