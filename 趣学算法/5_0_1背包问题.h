#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<int>w, v, bestx, x;
int W = 0;



//回溯函数
void Backtrack(int t, int&wp, int&vp, int&bestp)
{
	if (t >= v.size())//已经到达叶子结点，成为死节点
	{
		bestx.assign(x.begin(), x.end());//将局部最优解记录为全局最优解
		bestp = vp;//保存最优节点
		return;
	}

	int rp = 0;
	for (int i = t + 1; i < v.size(); ++i)
		rp += v[i];
	if (rp + wp > bestp)//可以继续搜索右节点,一是用于回溯使用，二是用于判断是否需要第n+1个节点
	{
		x[t] = 0;//不选取t这个节点
		Backtrack(t + 1, wp, vp, bestp);//继续向后一个节点发
	}

	if (wp + w[t] <= W)//此处不满足，则进行判断是否为死节点
	{
		wp += w[t];
		vp += v[t];
		x[t] = 1;//要这个解
		Backtrack(t + 1, wp, vp, bestp);
		wp -= w[t];//此处为重点，进行回溯
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
	cout << "max value is：" << GoBack() << endl;
	cout << "the choosed one is：";
	for (int i = 1; i < v.size(); ++i)
		if (bestx[i] == 1)
			cout << i << "  ";
	cout << endl;
}