//#include "000�⺯��.h"
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
//		if (S == G.size() * 2)return 0;//ƽ��
//		if (M == C)return dp[S][M][C] = 2;//èӮ��
//		if (M == 0)return dp[S][M][C] = 1;//����Ӯ��
//		if (dp[S][M][C] != -1)return dp[S][M][C];
//		bool mouseTurn = (S % 2 == 0);
//		if (mouseTurn)//��������
//		{
//			bool catWin = true;
//			for (int i = 0; i < G[M].size(); ++i)
//			{
//				int next = helper(G, S + 1, G[M][i], C, dp);
//				if (next == 1)return dp[S][M][C] = 1;//����ص�������λ��
//				else if (next != 2)catWin = false;
//			}
//			if (catWin)return dp[S][M][C] = 2;//èӮ��
//			else return dp[S][M][C] = 0;
//		}
//		else
//		{
//			bool mouseWin = true;
//			for (int i = 0; i < G[C].size(); ++i)
//			{
//				if (G[C][i] == 0)continue;//è������
//				int next = helper(G, S + 1, M, G[C][i], dp);
//				if (next == 2)return dp[S][M][C] = 2;//è�ص�����λ��
//				else if (next != 1)mouseWin = false;
//			}
//			if (mouseWin)return dp[S][M][C] = 1;//����Ӯ��
//			else return dp[S][M][C] = 0;
//		}
//	}
//};
