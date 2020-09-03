#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//【题目】
//	给定一个整型数组arr，代表数值不同的纸牌排成一条线。玩家A和玩家B依次拿走
//	每张纸牌，规定玩家A先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右
//	的纸牌，玩家A和玩家B都绝顶聪明。请返回最后获胜者的分数。
//【举例】
//	arr = [1, 2, 100, 4]。
//	开始时玩家A只能拿走1或4。如果玩家A拿走1，则排列变为[2, 100, 4]，接下来玩
//	家B可以拿走2或4，然后继续轮到玩家A。如果开始时玩家A拿走4，则排列变为
//	[1, 2, 100]，接下来玩家B可以拿走1或100，然后继续轮到玩家A。玩家A作为绝顶
//	聪明的人不会先拿4，因为拿4之后，玩家B将拿走100。所以玩家A会先拿1，让排
//	列变为[2, 100, 4]，接下来玩家B不管怎么选，100都会被玩家A拿走。玩家A会获胜，
//	分数为101。所以返回101。
//	arr = [1, 100, 2]。
//	开始时玩家A不管拿1还是2，玩家B作为绝顶聪明的人，都会把100拿走。玩家B会
//	获胜，分数为100。所以返回100。
//
//【题解思路】
//


///使用递归
int s(vector<int>v, int i, int j);
int f(vector<int>v, int i, int j);

int s(vector<int>v, int i, int j)//后一个人拿，当最后一张牌是第一个人拿的故返回0
{
	if (i == j)
		return 0;
	return min(f(v, i + 1, j), f(v, i, j - 1));
}

int f(vector<int>v, int i, int j)//第一个先拿
{
	if (i == j)
		return v[i];
	return max((v[i] + s(v, i + 1, j)), (v[j] + s(v, i, j - 1)));
}

int maxCarsNum1(vector<int>v)
{
	if (v.size() == 0)
		return 0;
	return max(f(v, 0, v.size() - 1), s(v, 0, v.size() - 1));//两个人，一个拿一次，求能拿到最大数的 那个人
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