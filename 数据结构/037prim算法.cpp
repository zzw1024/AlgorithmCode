////////#include "000�⺯��.h"
////////
////////int main()
////////{
////////	vector<int>v{ -2,11,-4,13,-5,-2 };
////////	int tempL = 0, resL, resR, sum = 0, resSum = 0;
////////	for (int i = 0; i < v.size(); ++i)
////////	{
////////		if (sum < 0)
////////		{
////////			sum = v[i];
////////			tempL = i;
////////		}
////////		else
////////			sum += v[i];
////////		if (sum > resSum)
////////		{
////////			resL = tempL;
////////			resR = i;
////////			resSum = sum;
////////		}		
////////	}
////////	cout << resL << " " << resR << " " << resSum << endl;
////////	while (1);
////////}
//////
////////#include "000�⺯��.h"
////////int main()
////////{
////////	vector<int>v = { 1,2,3,-1,-2,7,9 };
////////	vector<int>dp(v.size(), 1);
////////	int maxL = 0;
////////	for(int i=0;i<v.size();++i)
////////	{
////////		for (int j = 0; j < i; ++j)
////////			if (v[j] <= v[i])//���½�
////////				dp[i] = max(dp[i], dp[j] + 1);
////////		maxL = max(dp[i], maxL);
////////	}
////////	cout << maxL << endl;
////////	while (1);
////////}
//////
//////
////////#include "000�⺯��.h"
////////int main()
////////{
////////	string s1, s2;
////////	s1 = "sadstory";
////////	s2 = "adminsorry";
////////	s1 = " " + s1;
////////	s2 = " " + s2;
////////	vector<vector<int>>dp(s1.size(), vector<int>(s2.size(), 0));
////////	for (int i = 1; i < s1.size(); ++i)
////////		for (int j = 1; j < s2.size(); ++j)
////////			if (s1[i] == s2[j])//��ס������i��j�Ǵ�1��ʼ�ģ������ַ����ĵ�һλӦ����" "ռλ
////////				dp[i][j] = dp[i - 1][j - 1] + 1;
////////			else
////////				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);//ȡ������s1ǰi-1��s2ǰj ��s1ǰi��s2ǰj-1��������
////////	cout << dp[s1.size()-1][s2.size()-1] << endl;
////////	while (1);
////////}
//////
//////#include "000�⺯��.h"
//////vector<vector<int>>v;
//////vector<int>father, dp;
//////int calDP(int index)//���ס�������ǴӺ���ǰ��
//////{
//////	if (dp[index] > 0)
//////		return dp[index];//dp[index]��ֵ�Ѿ�����õ���
//////	for (int i = 0; i < dp.size(); ++i)
//////	{
//////		if (v[index][i] > 0)//��·Ϊͨ
//////		{
//////			int temp = calDP(i) + v[index][i];
//////			if (temp > dp[index])
//////			{
//////				dp[index] = temp;//����������
//////				father[index] = i;//index�ǴӺ����i������������
//////			}
//////		}
//////	}			
//////	return dp[index];
//////}
//////
//////
//////
//////int main()
//////{
//////	v = {
//////	   {0,0,0,0,0,0,0,0,0,0},
//////	   {0,0,0,3,2,0,0,0,0,0},
//////	   {0,0,0,0,3,2,0,0,0,0},
//////	   {0,0,0,0,0,0,3,0,0,0},
//////	   {0,0,0,0,0,0,3,2,0,0},
//////	   {0,0,0,0,0,0,0,1,0,0},
//////	   {0,0,0,0,0,0,0,0,2,1},
//////	   {0,0,0,0,0,0,0,0,2,2},
//////	   {0,0,0,0,0,0,0,0,0,0},
//////	   {0,0,0,0,0,0,0,0,0,0} };
//////	vector<vector<int>>dp(v.size(), vector<int>(v.size(), 0);
//////	father.resize(v.size());
//////	for (int i = 0; i < father.size(); ++i)
//////		father[i] = i;
//////}
////
//////
//////#include "000�⺯��.h"
//////int main()
//////{
//////	for (int i = 1; i <= n; ++i)
//////	{
//////		for (int v = w[i]; v <= V; ++v)//��ֵ����
//////			dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + c[j]);
//////	}
//////}
////
////
////#include "000�⺯��.h"
////int n, wn, maxV = 0;
////vector<int>res, temp, w, v;
////void DFS(int index,int sumW,int sumV)
////{
////	if (sumW > wn)//һ����ֹ����������
////		return;
////	if (sumV > maxV)//һ��ѡ����������ֹ��������
////	{
////		res = temp;
////		maxV = sumV;
////	}
////	for (int i = index; i < n; ++i)
////	{
////		temp.push_back(index);
////		DFS(i + 1, sumW + w[i], sumV + v[i]);//ѡ��
////		temp.pop_back();
////		DFS(i + 1, sumW, sumV);//��ѡ��
////	}
////}
////void DFS(int index, int sumV, int sumW)
////{
////	if (sumW > weight)
////		return;
////	if (sumV> maxV)
////		maxV = sumV;
////	for (int i = index; i < n; ++i)
////	{
////		DFS(i + 1, sumV + v[index], sumW + w[index]); //ѡ�����Ʒ Ȼ�����ѡ��һ�� 
////		DFS(i + 1, sumV + v[index], sumW + w[index]); //ѡ�����Ʒ Ȼ��ѡ��һ�� 
////		DFS(i + 1, sumV, sumW); //��ѡ�����Ʒ 
////	}
////}
////
////
////int main()
////{
////	w = { 3,5,1,2,2 };
////	v = { 4,5,2,1,3 };
////	n = 5;
////	wn = 8;
////	DFS(0, 0, 0);
////	cout << maxV;
////	while (1);
////}
//#include "000�⺯��.h"
//vector<vector<int>>v;
//int cnt = 0;
//void DFS(int i, int j)
//{
//	if (i < 0 || i >= v.size() || j < 0 || j >= v[i].size() || v[i][j] != 1)
//		return;
//	v[i][j] = 2;//Ⱦɫ������ʹ��visit���ɱ�
//	DFS(i + 1, j);
//	DFS(i - 1, j);
//	DFS(i, j + 1);
//	DFS(i, j - 1);
//}
//void BFS(int i, int j)
//{
//	queue<pair<int, int>>q;
//	q.push(make_pair(i, j));
//	v[i][j] = 2;//Ⱦɫ������ʹ��visit���ɱ�
//	vector<vector<int>>dir = { {1,0},{-1,0},{0,1},{0,-1} };//����
//	while (!q.empty())
//	{
//		pair<int, int>p = q.front();
//		q.pop();
//		for (int k = 0; k < 4; ++k)
//		{
//			int x = p.first + dir[k][0], y = p.second + dir[k][1];
//			if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size())
//				continue;
//			if (v[x][y] == 1)
//			{
//				q.push(make_pair(x, y));
//				v[x][y] = 2;//һ��������ջ��ʱ�����Ⱦɫ
//			}
//		}
//	}
//}
//int main()
//{
//	v = {
//	{0, 1, 1, 1, 0, 0, 1},
//	{0, 0, 1, 0, 0, 0, 0 },
//	{0, 0, 0, 0, 1, 0, 0},
//	{0, 0, 0, 1, 1, 1, 0},
//	{1, 1, 1, 0, 1, 0, 0},
//	{1, 1, 1, 1, 0, 0, 0},
//	};
//	
//	for (int i = 0; i < v.size(); ++i)
//	{
//		for (int j = 0; j < v[i].size(); ++j)
//		{
//			if (v[i][j] == 1)
//			{
//				BFS(i, j);
//				//DFS(i, j);//�мǣ�һ���ڴ泬���������������̫�󣬵���DFS�ݹ���ڴ�ջ�����Ӧ����BFS
//				++cnt;
//			}
//		}
//	}
//	cout << cnt;
//	while (1);
//}

