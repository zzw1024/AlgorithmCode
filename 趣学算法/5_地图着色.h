#pragma once
#include <iostream>
#include <vector>

using namespace std;

bool isOK(vector<int >m, vector<int >x, int c)
{
	for (int i = 1; i < m.size(); ++i)
		if (m[i] == 1 && x[i] == c)
			return false;
	return true;
}
void GoBack(int t, vector<vector<int>>map, vector<vector<int>>&bestx, vector<int>x, vector<int>color)
{
	if (t >= map.size())
	{
		bestx.push_back(x);
		return;
	}

	for (int i = 0; i < color.size(); ++i)
	{
		x[t] = color[i];
		if (isOK(map[t], x, color[i]))
			GoBack(t + 1, map, bestx, x, color);
	}
}


void Test()
{
	vector<vector<int>>map;
	map.push_back({ 0,0,0,0,0,0,0,0 });
	map.push_back({ 0,0,1,1,1,0,0,0 });
	map.push_back({ 0,1,0,1,0,1,0,0 });
	map.push_back({ 0,1,1,0,1,1,0,0 });
	map.push_back({ 0,1,0,1,0,1,0,1 });
	map.push_back({ 0,0,1,1,1,0,1,1 });
	map.push_back({ 0,0,0,0,0,1,0,1 });
	map.push_back({ 0,0,0,0,1,1,1,0 });
	vector<vector<int>>bestx;
	vector<int>x(map.size(), 0);
	vector<int>color = { 1,2,3 };
	GoBack(1, map, bestx, x, color);

	for (auto &a : bestx)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl;
}

