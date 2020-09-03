#include <iostream>
#include <vector>

using namespace std;
//����Ŀ��
//��ʼ����0~n - 1��N��λ�ã���������Mλ���ϣ������˼����������������
//���ʣ�����P���ߵ�Kλ�õ��߷����ж����֣�

//��N��λ��
//p���ߵĲ���
//s��ʼ�Ĳ���
//e���յ����λ��

///ʹ�õݹ�
int calSteps(int N, int p, int s, int e)
{
	if (N < 2 || s<1 || s>N || p < 0 || e<1 || e>N)//Խ��...1
		return 0;
	if (p == 0)//����������...2
		return s == e ? 1 : 0;
		//return s == e ? 1 : 0;
	int res = 0;
	//��ʼ���ˣ����ձ߽���з���
	if (s == 1)//...3
		res += calSteps(N, p - 1, s + 1, e);//ֻ��������
	else if (s == N)//...4
		res += calSteps(N, p - 1, s - 1, e);//ֻ��������
	else//...5
	{
		res += calSteps(N, p - 1, s - 1, e);//�����߻���������
		res += calSteps(N, p - 1, s + 1, e);//�����߻���������
	}
	return res;
}

///ʹ�ö�̬�滮
int calStep_(int N, int p, int s, int e)
{
	if (N < 2 || s<1 || s>N || p < 0 || e<1 || e>N)//Խ���Ӧ1
		return 0;
	vector<vector<int>>dp(p + 1, vector<int>(N + 1, 0));
	dp[0][e] = 1;//��ʣ�ಽ���ﵽe��λ��ʱ���򷵻�һ����ȷ�Ĳ���//��Ӧ3��ʣ�ಽ��Ϊ0��
	for (int i = 1; i <= p; ++i)
	{
		for (int j = 1; j <= N; ++j)//��Ӧ3�����ֱ�ӱ��߽�1��ȥ����
		{
			if (j + 1 > N)
				dp[i][j] = dp[i - 1][j - 1];//��Ӧ4,��ΪiΪ������jΪλ����
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}
	return dp[p][s];//�ص������λ��
}


void Test()
{
	cout << calSteps(6, 5, 2, 5) << endl;
	cout << calStep_(6, 5, 2, 5) << endl;
}