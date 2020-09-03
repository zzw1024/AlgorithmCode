#include <iostream>
#include <string>

using namespace std;

//使用manacher算法寻找字符中最长的回文子串

int Manacher(string str)
{
	//字符串预处理
	string newStr = "#";
	for (auto c : str)
		newStr = newStr + c + "#";
	//回文半径记录数组
	int* rIndex = new int[newStr.length()];
	int c = -1;//回文中心
	int R = -1;//回文右边界 R位于回文对称右边界的右边一个字母
	int maxL = INT_MIN;//记录最长回文字长
	for (int i = 0; i < newStr.length(); ++i)
	{
		//第一步直接取得可能的最短的回文半径，当i>R时，最短的回文半径是1，
		//反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
		if (R > i)
			rIndex[i] = rIndex[2 * c - i] < R - i ? rIndex[2 * c - i] : R - i;
		else
			rIndex[i] = 1;
		//取最小值后开始从边界暴力匹配，匹配失败就直接退出
		while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
		{
			if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])//向两边扩展，找回文字母
				rIndex[i]++;
			else
				break;
		}
		//观察此时R和C是否能够更新
		if (i + rIndex[i] > R)
		{
			R = i + rIndex[i];
			c = i;
		}
		//更新最大回文半径的值
		maxL = maxL > rIndex[i] ? maxL : rIndex[i];
	}
	delete[] rIndex;
	//这里解释一下为什么返回值是maxn-1，因为manacherstring的长度和原字符串不同，
	//所以这里得到的最大回文半径其实是原字符串的最大回文子串长度加1，
	//有兴趣的可以自己验证试试,-1是为了将后面的‘#’去掉
	return maxL - 1;	
	
}

void Test()
{
	string str = "abc1234321ab";
	cout << Manacher(str) << endl;
}