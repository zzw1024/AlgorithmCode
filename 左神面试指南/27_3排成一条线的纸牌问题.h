#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����Ŀ��
//	����һ����������arr��������ֵ��ͬ��ֽ���ų�һ���ߡ����A�����B��������
//	ÿ��ֽ�ƣ��涨���A���ã����B���ã�����ÿ�����ÿ��ֻ���������������
//	��ֽ�ƣ����A�����B�������������뷵������ʤ�ߵķ�����
//��������
//	arr = [1, 2, 100, 4]��
//	��ʼʱ���Aֻ������1��4��������A����1�������б�Ϊ[2, 100, 4]����������
//	��B��������2��4��Ȼ������ֵ����A�������ʼʱ���A����4�������б�Ϊ
//	[1, 2, 100]�����������B��������1��100��Ȼ������ֵ����A�����A��Ϊ����
//	�������˲�������4����Ϊ��4֮�����B������100���������A������1������
//	�б�Ϊ[2, 100, 4]�����������B������ôѡ��100���ᱻ���A���ߡ����A���ʤ��
//	����Ϊ101�����Է���101��
//	arr = [1, 100, 2]��
//	��ʼʱ���A������1����2�����B��Ϊ�����������ˣ������100���ߡ����B��
//	��ʤ������Ϊ100�����Է���100��
//
//�����˼·��
//


///ʹ�õݹ�
int s(vector<int>v, int i, int j);
int f(vector<int>v, int i, int j);

int s(vector<int>v, int i, int j)//��һ�����ã������һ�����ǵ�һ�����õĹʷ���0
{
	if (i == j)
		return 0;
	return min(f(v, i + 1, j), f(v, i, j - 1));
}

int f(vector<int>v, int i, int j)//��һ������
{
	if (i == j)
		return v[i];
	return max((v[i] + s(v, i + 1, j)), (v[j] + s(v, i, j - 1)));
}

int maxCarsNum1(vector<int>v)
{
	if (v.size() == 0)
		return 0;
	return max(f(v, 0, v.size() - 1), s(v, 0, v.size() - 1));//�����ˣ�һ����һ�Σ������õ�������� �Ǹ���
}

///***********************************
int maxCarsNum2(vector<int>v)
{
	if (v.size() == 0)
		return 0;
	vector<vector<int>>ff(v.size(), vector<int>(v.size()));
	vector<vector<int>>ss(v.size(), vector<int>(v.size()));
	for (int j  = 0; j < v.size(); ++j)
	{
		ff[j][j] = v[j];
		for (int i = j - 1; i >= 0; --i)
		{
			ff[i][j] = max(v[i] + ss[i + 1][j], v[j] + ss[i][j - 1]);
			ss[i][j] = min(ff[i + 1][j], ff[i][j - 1]);
		}
	}
	return max(ff[0][v.size() - 1], ss[0][v.size() - 1]);
}


void Test()
{
	vector<int>v;
	v = { 1,2,100,4 };
	cout << maxCarsNum2(v) << endl;
}