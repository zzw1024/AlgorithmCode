#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<int>w, v, bestx, x;
int W = 0;



//���ݺ���
void Backtrack(int t, int&wp, int&vp, int&bestp)
{
	if (t >= v.size())//�Ѿ�����Ҷ�ӽ�㣬��Ϊ���ڵ�
	{
		bestx.assign(x.begin(), x.end());//���ֲ����Ž��¼Ϊȫ�����Ž�
		bestp = vp;//�������Žڵ�
		return;
	}

	int rp = 0;
	for (int i = t + 1; i < v.size(); ++i)
		rp += v[i];
	if (rp + wp > bestp)//���Լ��������ҽڵ�,һ�����ڻ���ʹ�ã����������ж��Ƿ���Ҫ��n+1���ڵ�
	{
		x[t] = 0;//��ѡȡt����ڵ�
		Backtrack(t + 1, wp, vp, bestp);//�������һ���ڵ㷢
	}

	if (wp + w[t] <= W)//�˴������㣬������ж��Ƿ�Ϊ���ڵ�
	{
		wp += w[t];
		vp += v[t];
		x[t] = 1;//Ҫ�����
		Backtrack(t + 1, wp, vp, bestp);
		wp -= w[t];//�˴�Ϊ�ص㣬���л���
		vp -= v[t];
	}

}

int GoBack()
{
	int bestp = 0;
	int wp = 0;
	int vp = 0;
	int sumw = 0;
	int sumv = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		sumw += w[i];
		sumv += v[i];
	}
	if (sumw <= W)
	{
		bestx.assign(v.size(), 1);
		return sumv;
	}

	Backtrack(1, wp, vp, bestp);
	return bestp;
}



void Test()
{
	w = { 0,2,5,4,2 };
	v = { 0,6,3,5,4 };
	W = 10;
	bestx.assign(v.size(), 0);
	x.assign(v.size(), 0);
	cout << "max value is��" << GoBack() << endl;
	cout << "the choosed one is��";
	for (int i = 1; i < v.size(); ++i)
		if (bestx[i] == 1)
			cout << i << "  ";
	cout << endl;
}