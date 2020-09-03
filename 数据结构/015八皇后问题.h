#include "000库函数.h"
#include <algorithm>

static int num;
static int *x;
static int sum;

bool place(int k)
{
	for (int j = 1; j < k; j++)
		if (abs(x[k] - x[j]) == abs(k - j) || x[j] == x[k])
			return false;
	return true;

}

void backtrack(int t)
{
	if (t > num) //num为皇后的数目
	{
		sum++;//sum为所有的可行的解
		for (int m = 1; m <= num; m++)
		{
			cout << x[m];//这一行用输出当递归到叶节点的时候，一个可行解
		}
		cout << endl;
	}
	else
		for (int i = 1; i <= num; i++)//遍历该节点的所有叶
		{
			x[t] = i;
			if (place(t)) backtrack(t + 1);//此处的place函数用来进行我们上面所说的条件的判断，如果成立，进入下一级递归
		}
}
void T015()
{
	num = 8;
	sum = 0;
	x = new int[num + 1];//因为一个节点有num个叶，故需要num+1个位置
	for (int i = 0; i <= num; i++)
		x[i] = 0;
	backtrack(1);
	cout << "方案共有" << sum;

}





//解法二
bool isPass(int*);
int EightQueue() {
	int a[8] = { 0,1, 2, 3, 4, 5, 6, 7 };
	int n = 0;	
	while (next_permutation(a, a + 8)) {//一一判断排列是否可行
		if (isPass(a))++n;//可行就计数一次
	}
	return n;
}


bool isPass(int *a) {//判断斜方是否会受到其他皇后的攻击
	int queue[8][8] = { 0 };
	for(int i=0;i<8;++i)
		queue[i][a[i]] = 1;//按照0-7数字，每行按照a中数字对应其列进行放置皇后，则不会出现同行同列出现两个皇后了，大大减少了判断

	for (int i = 0; i < 8; ++i) {
		for (int t = i - 1, k = a[i] - 1; t >= 0 && k >= 0; --t, --k) {//左上方
			if (queue[t][k] == 1)
				return false;
		}
		for (int t = i + 1, k = a[i] + 1; t < 8 && k < 8; ++t, ++k) {//右下方
			if (queue[t][k] == 1)
				return false;
		}
		for (int t = i + 1, k = a[i] - 1; t < 8 && k >= 0; ++t, --k) {//左下方
			if (queue[t][k] == 1)
				return false;
		}
		for (int t = i - 1, k = a[i] + 1; t >= 0 && k < 8; --t, ++k) {//右上方
			if (queue[t][k] == 1)
				return false;
		}
	}
	return true;
}



void T015()
{
	cout << "方案共有" << EightQueue() << endl;

}