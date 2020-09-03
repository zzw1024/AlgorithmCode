#pragma once
#include <iostream>
#include <vector>

using namespace std;


void Goback(int t, vector<vector<int>>data, vector<int>& res, vector<int>v, int& bestf, int f1, int f2)
{
	if (t >= data.size())
	{
		bestf = f2;
		res.assign(v.begin(), v.end());
		return;
	}
	for (int i = t; i < data.size(); ++i)//���ѵ㣬��ôʹ�ò��ظ��ӹ�����
	{
		int temp = f2;//��������
		f1 += data[v[i]][0];  //����ǰ���Ѿ��ӹ���ʱ��
		f2 = (f1 > f2 ? f1 : f2) + data[v[i]][1];//�Ƿ�ù�����һ���ӹ��꣬�ǵĻ�ֱ�ӽ���ڶ�������
		if (f2 < bestf)//��Ϊ����ʹ���ظ�����������ʹ�ý����ķ���
		{
			swap(v[i], v[t]);
			Goback(t + 1, data, res, v, bestf, f1, f2);
			swap(v[i], v[t]);//��λ
		}
		f1 -= data[v[i]][0];//��λ
		f2 = temp;
	}
}

void Test()
{
	vector<vector<int>>data;
	data.push_back({ 0,0 });
	data.push_back({ 5,7 });
	data.push_back({ 1,2 });
	data.push_back({ 8,2 });
	data.push_back({ 5,4 });
	data.push_back({ 3,7 });
	data.push_back({ 4,4 });

	vector<int>res;
	vector<int>v = { 0,1,2,3,4,5,6 };//�ȸ���һ����ʼ˳�򣬺����ڴ˻����Ͻ��н�������
	int bestf = INT_MAX;
	int f1 = 0;
	int f2 = 0;
	Goback(1, data, res, v, bestf, f1, f2);

	for (auto a : res)
		cout << a << "  ";
	cout << endl << bestf << endl;
}
