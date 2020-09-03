#if 0
#include<iostream>
#include<map>

using namespace std;

//小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？
//
//
//输入描述 :
//
//输入包含多组测试数据。
//
//对于每组测试数据：
//
//N - 本组测试数据有n个数
//
//a1, a2...an - 需要计算的数据
//
//保证 :
//
//1 <= N <= 100000, 0 <= ai <= INT_MAX.
//
//
//
//输出描述 :
//
//对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。
//
//
//输入例子1 :
//6
//45 12 45 32 5 6
//
//输出例子1 :
//1 2



int main()
{
	int nums;
	while (cin >> nums)
	{
		int a;
		map<int, int>numbers;
		for (int i = 0; i < nums; ++i)//使用map存数据，会自动排序
		{
			cin >> a;
			numbers[a]++;
		}
		int zerosN = 0;
		map<int, int>oneN;
		for (auto it = numbers.begin(); it != numbers.end(); ++it)
		{
			if (it->second > 1)//若有相同字母，则最小差为0，组数为所有相同数字的组合
				zerosN += (it->second)*(it->second - 1) / 2;//排列组合个数为组数
			auto ptr = it;
			if (++ptr != numbers.end())//若没有相同数字，则有多少对最小差，则为其组数
				oneN[ptr->first - it->first]++;//用map可以知道最小差为第一个
		}
		if (zerosN == 0)
			cout << oneN.begin()->second << ' ' << (numbers.begin()->second * (--numbers.end())->second) << endl;
		else
			cout << zerosN << ' ' << (numbers.begin()->second * (--numbers.end())->second) << endl;
	}



	system("pause");
	return 0;
}


#endif