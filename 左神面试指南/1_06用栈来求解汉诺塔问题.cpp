//#pragma once
//#include <iostream>
//#include <stack>
//#include <string>
//#include <vector>
//
//using namespace std;
////【问题】
////汉诺塔问题比较经典，这里修改一下游戏规则：
////现在限制不能从最左侧的塔直接移动到最右侧，也不能从最右侧直接移动到最左侧，
////而是必须经过中间。求当塔有N层的时候，打印最优移动过程和最优移动总步数。
////例如，当塔数为两层时，最上层的塔记为1，最下层的塔记为2，则打印：
////Move 1 from left to mid 
////Move 1 from mid to right 
////Move 2 from left to mid
////Move 1 from right to mid 
////Move 1 from mid to left 
////Move 2 from mid to right 
////Move 1 from left to mid
////Move 1 from mid to right 
////It will move 8 steps.
//
////方法一：
////使用递归的方法
////无论多少层，都看作有两层，最大的一层(命名为X)、(N - 1)层合并起来的作为一层(命名为Y)，目标是将X移动到最右侧，然后再把Y移动到最右侧。
////Y从A塔移动到B塔
////Y从B塔移动到C塔
////X从A塔移动到B塔
////Y从C塔移动到B塔
////Y从B塔移动到A塔
////X从B塔移动到C塔
////将Y看做X，继续递归移动
//
//
//
//void Hanota(string l, string m, string r, int n)
//{
//	if (n == 1)//当为一个时，则分两步直接移动到最右端
//	{
//		cout << n << ": " << l << "->" << m << endl;
//		cout << n << ": " << m << "->" << r << endl;
//		return;
//	}
//	//上面n-1当成一个整体Y
//	Hanota(l, m, r, n - 1);//Y直接移动到最右端
//	cout << n << ": " << l << "->" << m << endl;//X移动到中间
//	Hanota(r, m, l, n - 1);//Y移动到最左边
//	cout << n << ": " << m << "->" << r << endl;//n移动到最右端
//	Hanota(l, m, r, n - 1);//Y移动到最右端
//}
//
//
//
//
////借助栈来实现
////用三个栈来实现，三个栈分别为Ls,Ms,Rs
////为了不违反汉诺塔中大不能压小的法则，
////三个栈必须维持小数在上，大数在下
////限制
////当上一步为：LM，下一步的情况分析：
////
////执行LM，违反小压大原则
////执行ML，违反逆反原则
////执行MR还是RM，按照小压大原则，这两种情况是互斥的，只能按条件二选一
////其他分析类似，省略...
//void Help(string &pre, string preMove, string nowMove, stack<int>&Fs, stack<int>&Ts)
//{
//	if (!Fs.empty() && pre != nowMove && Fs.top() < Ts.top())
//	{
//		Ts.push(Fs.top());
//		Fs.pop();
//		cout << preMove << endl;
//		pre = preMove;
//	}
//}
//
//
//void stackToHanota(int n, string l, string m, string r)
//{
//	stack<int>Ls, Ms, Rs;
//	//为了方便比较栈顶元素，我们首先对每个栈都压入一个较大数
//	Ls.push(INT_MAX);
//	Ms.push(INT_MAX);
//	Rs.push(INT_MAX);
//	string pre = "LoM";
//	for (int i = n; i > 0; --i)
//		Ls.push(i);//数据入栈
//	int layerSize = Ls.size();
//	while (layerSize != Rs.size())
//	{//左中右->右中左
//		Help(pre, "LoM", "MoL", Ls, Ms);
//		Help(pre, "MoR", "RoM", Ms, Rs);
//		Help(pre, "RoM", "MoR", Rs, Ms);
//		Help(pre, "MoL", "LoM", Ms, Ls);
//	}
//}
//
//
//
//
//int main()
//{
//	string l = "左";
//	string m = "中";
//	string r = "右";
//	//Hanota(l, m, r, 3);
//	stackToHanota(3, l, m, r);
//	while (1);
//}