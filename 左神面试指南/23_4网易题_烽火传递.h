#pragma once
#include <iostream>
#include <vector>
#include <deque>


using namespace std;

//【题目】
//	一个数组中的数字组成环形山，数值为山高
//	1   2    4    5    3
//	规则，烽火传递：
//	相邻之间的两座山必能看到烽火，
//	非相邻的山之间有一边的山高都 <= 这两个非相邻山的山高，则这两座山能相互看到烽火。
//	比如，1和4就不能看到，因为顺时针边，2比1大，挡住了，逆时针边，3和5都比1大，挡住了。
//	而3与4就能看到，虽然逆时针边5挡住了，但顺时针边1和2没挡住3。
//	问哪两座山能相互看到烽火；要求时间复杂为O(1)
//	此题答案为(1, 2)(1, 3)(2, 4)(4, 5)(5, 3)(2, 3)(4, 3)
//	
//【题解】
//	【数组中的数字互不相同】
//	在最高山N, 和次高山M，之间的任何一座山向顺时针，逆时针寻找，
//	都有可以看到山N、M两座山，即有(n - 2) * 2对，然后再加上N, M这两座山能相互看到
//	故共有(n - 2) * 2 + 1 = 2 * n - 3对
//	结论：n个不相同的数，共有(2 * n - 3)对
//
//	【数组中含有相同的数字】
//	单调栈：从大到小排序
//	从任意一个最大值开始，以一个方向旋转，进行入栈操作
//	当一个数被弹出栈时，他找到了2个可以相互看到山，即，将入栈的和他下面的
//	当将入栈数与栈顶相等，则将两个数的信息共同记录在同一个栈位置，
//	当弹出某个数为n条记录时，即在同一个位置记录了n次某个数，比如，有连续n个4入栈，则在相同位置记录n次4
//  此时它弹出时，能看到的山为：Cn2 + n * 2次其中Cn2[n个4之间相互组合] + n * 2[n个4与他两边的高山组合]，
//  当将遍历完数组后，栈中剩余的数弹出时：
//  对于倒数第i > 2个剩余数弹出时，他能看到的山为：Cn2 + n * 2
//  对于倒数第二个剩余数弹出时，
//  若最后一个数为 > 1个记录他能看到的山为：Cn2 + n * 2
//  若最后一个数为 == 1个记录他能看到的山为：Cn2 + n * 1, 因为这是一个环。
//  对于倒数第1个剩余数弹出时，他能看到的山为：Cn2
//



int fireTranfer(vector<int>m)
{
	//先找到最大值
	int res = 0;
	int maxIndex = 0;
	deque<pair<int, int>>d;//单调栈
	for (int i = 0; i < m.size(); ++i)//寻找最大值
		maxIndex = m[maxIndex] > m[i] ? maxIndex : i;
	d.push_back(make_pair(m[maxIndex], 1));
	for (int i = maxIndex + 1; i != maxIndex; ++i)
	{
		if (i == m.size())
		{
			i = -1;
			continue;
		}

		while (!d.empty() && m[i] > d.back().first)
		{
			int value, num;
			value = d.back().first;
			num = d.back().second;
			res += (num*(num - 1) / 2) + num * 2;//对于弹出数据进行计算组合
			d.pop_back();
		}
		if (m[i] == d.back().first)
			++d.back().second;
		else
			d.push_back(make_pair(m[i], 1));//压入新数


	}
	//将队列中剩余的数据弹出来
	while (!d.empty())
	{
		int value, num;
		value = d.back().first;
		num = d.back().second;
		if (d.size() > 2)//不是最后两个数据
			res += (num*(num - 1) / 2) + num * 2;
		else if (d.size() == 2)//为倒数第二个数
			if (d.front().second > 1)
				res += (num*(num - 1) / 2) + num * 2;
			else
				res += (num*(num - 1) / 2) + num;
		else//为倒数第一个数
			res += (num*(num - 1) / 2);
		d.pop_back();
	}
	return res;
}

void Test()
{
	vector<int>v;
	v = { 1,2,4,5,3 };
	cout << fireTranfer(v) << endl;
	v = { 2,5,3,4,3,4,5 };
	cout << fireTranfer(v) << endl;
	v = { 5,4,4,4 };
	cout << fireTranfer(v) << endl;

}