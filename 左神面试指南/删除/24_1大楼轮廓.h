#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


//【题目】
//	给定一个N行3列二维数组，每一行表示有一座大楼，一共有N座大楼。
//	所有大楼的底部都坐落在X轴上，每一行的三个值(a, b, c)代表每座大楼的从(a, 0)点开始，到(b, 0)点结束，高度为c。
//	输入的数据可以保证 a < b, 且a，b，c均为正数。大楼之间可以有重合。 请输出整体的轮廓线。
//	例子：给定一个二维数组[[1, 3, 3], [2, 4, 4], [5, 6, 1]]
//	输出为轮廓线[[1, 2, 3], [2, 4, 4], [5, 6, 1]]
//	
//【题解】
//	[1, 2, 3]表示第1个数到第2个数的高度为3
//	[2, 4, 4]表示第2个数到第4个数的高度为4
//	将数组进行分解：
//	[1, 2, 3]分解为：[1, 3, 上][3, 3, 下]
//	然后将这些分解的数组按照第一个数进行排序从小到大
//	准备一个红黑树map,	key为楼高	value为楼高值出现的次数
//	怎么知道是否产生轮廓了呢？
//	从初始化楼高0开始
//	当压入数据中为上者，则对相应楼高key值的value++
//		每压入一个数字，就查看map中的最高的楼高值【即map中最大的key】是否发生变化，
//		一旦发生变化了，则产生了轮廓，无论是上去还是下来
//		没有发生变化则没有产生轮廓
//	当压入数据为下，则对相应楼高key值的value--，value == 0则删除该条key记录
//	注意
//	当在同一个位置产生两条记录，比如在4的位置上有一个数据为下，和一个数据为上，	你在预处理数据进行排序时，谁前谁后？
//	一般是标记为下者排在前面，因为此时记录为楼高变下，那么前面一定有楼高变为上的
//	在压入数据时，要记录每个数位置的最大高度

	
vector<vector<int>> printContour(vector<vector<int>>v)
{
	vector<vector<int>>data;//存放预处理后的数据
	vector<vector<int>>res;//答案
	map<int, int>mh;//记录楼高
	map<int, int>mp;//记录位置
	for (auto &a : v)
	{
		vector<int>num(3, 0);
		num[0] = a[0];//起始点
		num[1] = a[2];//楼高
		num[2] = 1;//楼高标记为上
		data.push_back(num);
		num[0] = a[1];//终止点
		num[1] = a[2];//楼高
		num[2] = 0;//楼高标记为下
		data.push_back(num);
	}
	sort(data.begin(), data.end(), [](vector<int>v1, vector<int>v2) {return v1[0] == v2[0] ? v1[2] == 0 : v1[0] < v2[0]; });
	//排序规则，第一位数相同者，楼下者排前面，不相同，则小的排在前面
	for (auto& a : data)
	{
		if (a[2])//楼标记为上
		{
			if (mh.find(a[1]) != mh.end())//该楼高存在
				++mh[a[1]];//该楼高存在，进行记录增加
			else
				mh[a[1]] = 1;//该楼高不存在，加入
		}
		else//标记为楼下
		{
			if (mh.find(a[1]) != mh.end())//该楼高存在
			{
				if (mh[a[1]] == 1)//该楼高记录只有一个
					mh.erase(a[1]);//删除该条记录
				else
					--mh[a[1]];//该楼高记录减一
			}
		}

		if (mh.empty())//当楼高记录为0时，即中间有位置没有楼存在
			mp[a[0]] = 0;//则标记该位置的楼高为0
		else
			mp[a[0]] = (--mh.end())->first;//其存在楼的地方采用最高楼记录
	}

	int start, height;
	start = height = 0;
	for (auto &a : mp)//遍历记录
	{
		int p = a.first;//位置
		int h = a.second;//楼高
		if (height != h)//楼高发生变化，那么就产生楼的轮廓了
		{
			if (height != 0)
			{
				vector<int>temp(3, 0);
				temp[0] = start;
				temp[1] = p;
				temp[2] = height;
				res.push_back(temp);
			}
			start = p;//重新记录
			height = h;
		}
	}

	return res;		
}


void Test()
{
	vector<vector<int>>v;
	v = { {1,3,3}, {2,4,4}, {5,6,1}};
	v = printContour(v);
	for (auto &a : v)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << "///////////////////////////////////" << endl;
	v = { {1,5,4}, {2,3,3}, {4,7,1},{6,9,5},{8,10,2}};
	v = printContour(v);
	for (auto &a : v)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << "///////////////////////////////////" << endl;
	v = { {1,3,3}, {2,4,4}, {5,6,1} };
	v = printContour(v);
	for (auto &a : v)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << "///////////////////////////////////" << endl;
	v = { {1,4,2},{2,9,1},{3,6,3},{5,8,4},{7,10,5}};
	v = printContour(v);
	for (auto &a : v)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << "///////////////////////////////////" << endl;

}