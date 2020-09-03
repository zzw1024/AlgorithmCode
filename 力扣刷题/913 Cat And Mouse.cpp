//#include "000库函数.h"
//class Solution {
//public:
//	int catMouseGame(vector<vector<int>>& graph) {
//		if (graph.size() < 3)return 0;
//		int n = graph.size();
//		vector<vector<vector<int>>>dp(2*n, vector<vector<int>>(n, vector<int>(n, -1)));
//		return helper(graph, 0, 1, 2, dp);
//	}
//	int helper(const vector<vector<int>>&G, int S, int M, int C, vector<vector<vector<int>>>&dp)
//	{
//		if (S == G.size() * 2)return 0;//平均
//		if (M == C)return dp[S][M][C] = 2;//猫赢了
//		if (M == 0)return dp[S][M][C] = 1;//老鼠赢了
//		if (dp[S][M][C] != -1)return dp[S][M][C];
//		bool mouseTurn = (S % 2 == 0);
//		if (mouseTurn)//老鼠先走
//		{
//			bool catWin = true;
//			for (int i = 0; i < G[M].size(); ++i)
//			{
//				int next = helper(G, S + 1, G[M][i], C, dp);
//				if (next == 1)return dp[S][M][C] = 1;//老鼠回到当初的位置
//				else if (next != 2)catWin = false;
//			}
//			if (catWin)return dp[S][M][C] = 2;//猫赢了
//			else return dp[S][M][C] = 0;
//		}
//		else
//		{
//			bool mouseWin = true;
//			for (int i = 0; i < G[C].size(); ++i)
//			{
//				if (G[C][i] == 0)continue;//猫不进洞
//				int next = helper(G, S + 1, M, G[C][i], dp);
//				if (next == 2)return dp[S][M][C] = 2;//猫回到当初位置
//				else if (next != 1)mouseWin = false;
//			}
//			if (mouseWin)return dp[S][M][C] = 1;//老鼠赢了
//			else return dp[S][M][C] = 0;
//		}
//	}
//};
