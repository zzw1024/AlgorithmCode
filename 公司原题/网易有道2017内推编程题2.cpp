#if 0
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//
//小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
//while (!Q.empty())              //队列不空，执行循环
//
//{
//
//int x = Q.front();            //取出当前队头的值x
//
//Q.pop();                 //弹出当前队头
//
//Q.push(x);               //把x放入队尾
//
//x = Q.front();              //取出这时候队头的值
//
//printf("%d\n", x);          //输出x
//
//Q.pop();                 //弹出这时候的队头
//
//}
//
//做取出队头的值操作的时候，并不弹出当前队头。
//小明同学发现，这段程序恰好按顺序输出了1, 2, 3, ..., n。现在小明想让你构造出原始的队列，你能做到吗？[注：原题样例第三行5有错，应该为3，以下已修正]
//
//输入描述:
//第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000），输入的所有n之和不超过200000。
//
//输出描述 :
//对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.
//
//输入例子1 :
//4
//1
//2
//3
//10
//
//输出例子1 :
//1
//2 1
//2 1 3
//8 1 6 2 10 3 7 4 9 5

int main()
{
	int group;
	cin >> group;
	while (group--)
	{
		int n;
		cin >> n;
		

		//赋值方法一
		//vector<int>v(n, 0);
		//for (int ptr = -1, m = 1; m <= n; ++m)
		//{
		//	do
		//	{
		//		++ptr;//跳过一个
		//		if (ptr >= n)
		//			ptr = 0;
		//	} while (v[ptr] != 0);
		//	do
		//	{
		//		++ptr;//选择下一个
		//		if (ptr >= n)
		//			ptr = 0;
		//	} while (v[ptr] != 0);
		//	v[ptr] = m;			
		//}
		//赋值方法二
		deque<int> v;
		for (int i = n; i > 0; --i)
		{
			v.push_front(i);
			int t = v.back();
			v.pop_back();
			v.push_front(t);
		}


		for (auto a : v)
			cout << a << ' ';
		cout << endl;
	}

	return 0;
}

#endif