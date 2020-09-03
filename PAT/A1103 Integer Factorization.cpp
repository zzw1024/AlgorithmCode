//////#include <iostream>
//////#include <vector>
//////#include <cmath>
//////#include <algorithm>
//////using namespace std;
//////int n, k, p, maxFacSum = -1;//maxFacSum用来记录最大底数之和
//////vector<int>fac, ans, temp;//最大底数不超过n的数，底数最优数序列，临时存放
//////void DFS(int index, int nowK, int sum, int facSum)
//////{
//////	if (sum == n && nowK == k)//统计因素个数
//////	{
//////		if (facSum > maxFacSum)//更优的组合
//////		{
//////			ans = temp;
//////			maxFacSum = facSum;
//////		}
//////		return;
//////	}
//////	if (sum > n || nowK > k)return;//超出限制
//////	if (index - 1 >= 0)//给出数组小角标的限制
//////	{
//////		temp.push_back(index);//记录数据
//////		DFS(index, nowK + 1, sum + fac[index], facSum + index);//选
//////		temp.pop_back();//弹出数据
//////		DFS(index - 1, nowK, sum, facSum);//不选
//////	}
//////}
//////int main()
//////{
//////	cin >> n >> k >> p;
//////	for (int i = 0; pow(i, p) <= n; ++i)
//////		fac.push_back(pow(i, p));//初始化底数不超过n的因素
//////	DFS(fac.size() - 1, 0, 0, 0);//为了得到最大的因素数组，从最后一位开始向前搜索
//////	if (maxFacSum == -1)
//////		cout << "Impossible" << endl;//没有找到满足的序列
//////	else 
//////	{
//////		cout << n << " = ";
//////		for (int i = 0; i < ans.size(); i++)
//////			cout << ans[i] << "^" << p << (i == ans.size() - 1 ? "" : " + ");
//////	}
//////	return 0;
//////}
////
////#if 1
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <cmath>
////using namespace std;
////int n, k, p, maxSum = 0;
////vector<int>res, temp, nums;
////void DFS(int index, int nowK, int nowSum, int nowPowSum)
////{
////	if (nowK >= k || nowSum >= n)
////	{
////		if (nowK == k && nowSum == n && nowPowSum > maxSum)
////		{
////			res = temp;
////			maxSum = nowPowSum;
////		}
////		return;
////	}
////	if (index > 0)
////	{
////		temp.push_back(index);
////		DFS(index, nowK + 1, nowSum + nums[index], nowPowSum + index);//选择index
////		temp.pop_back();
////		DFS(index-1, nowK, nowSum, nowPowSum);//不选择
////	}
////}
////int main()
////{
////	cin >> n >> k >> p;
////	nums.push_back(0);
////	for (int i = 1; nums.back() <= n; ++i)
////		nums.push_back(pow(i, p));
////	DFS(nums.size() - 1, 0, 0, 0);//从大到小选择，保证答案的确定性
////	if (res.size() != k)
////		cout << "Impossible" << endl;
////	else
////	{
////		cout << n << " = ";
////		for (int i = 0; i < res.size(); ++i)
////			cout << (i == 0 ? "" : " + ") << res[i] << "^" << p;
////	}
////	return 0;
////}
////
////#endif
////
////#if 0
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <cmath>
////using namespace std;
////int N, K, P, sum = 0;
////vector<int>result, temp, powValue;
////void initPow() {//对不超过N的n^P进行打表，并把结果存储到powValue中
////	powValue.push_back(0);
////	while (powValue.back()*P < N)
////		powValue.push_back(pow(powValue.size()*1.0, P*1.0));
////}
////void DFS(int num, int nowK, int nowSum, int nowPowSum) {//DFS递归
////	if (nowK >= K || nowPowSum >= N) {
////		if (nowK == K && nowPowSum == N && nowSum > sum) {//当前序列的和比result的和大，更新相关信息
////			result = temp;
////			sum = nowSum;
////		}
////		return;
////	}
////	if (num >= 1) {
////		temp.push_back(num);
////		DFS(num, nowK + 1, nowSum + num, nowPowSum + powValue[num]);//选择当前的数
////		temp.pop_back();
////		DFS(num - 1, nowK, nowSum, nowPowSum);//没有选择当前的数，向更小的数进行选择
////	}
////}
////int main() {
////	scanf("%d%d%d", &N, &K, &P);
////	initPow();
////	DFS(powValue.size() - 1, 0, 0, 0);//从大到小进行选择
////	if (result.size() == K) {
////		printf("%d =", N);
////		for (int i = 0; i < result.size(); ++i)
////			printf(" %d^%d%s", result[i], P, i < result.size() - 1 ? " +" : "");
////	}
////	else
////		printf("Impossible");
////	return 0;
////}
////
////#endif 
////
////
////DFS深有优先搜索算法，DFS算法从1~P次根号下N中选择K个数，使得他们的P次方和等于N。对于当前处理的数，根据选与不选这个数进入两个分支，在DFS算法的参数中需要有当前处理的数num、已经选择了的数的个数nowK、当前选择了的数的和nowSum，当前选择了的数的平方和nowPowSum。同时定义一个全局变量result存储最优的结果序列，temp存储当前选中的数的临时序列。DFS递归到达nowK >= K || nowPowSum >= N时即停止递归，此时如果nowK == K && nowPowSum说明此时选中的数是满足要求的一组数，这时需要判断当前的临时序列与result谁更优，为了保证序列字典序最大，可以从大到小选择可选的数，这时只需判断两个序列谁的和最大就好了。当然，为了降低时间复杂度，建立一个不超过N的n^P的数组（即进行打表）以方便查询也是可以的。下面给出两份AC代码，一份没有打表，一份打了表。
////————————————————
////版权声明：本文为CSDN博主「日沉云起」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。
////原文链接：https ://blog.csdn.net/richenyunqi/article/details/80151925
//
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int n, m, k, maxSum = 0;
//vector<int>temp, res;
//int getTop()//得到最大值，进行剪枝处理
//{
//	int i = 0;
//	while (pow(i, k) <= n)++i;
//	return i - 1;
//}
//void DFS(int index, int allSum, int facSum)
//{
//	if (allSum > n || temp.size() > m)return;
//	if (allSum == n && temp.size() == m)
//	{
//		if (facSum > maxSum)
//		{
//			res = temp;
//			maxSum = facSum;
//		}
//		return;
//	}
//	if (index > 0)//index从最大开始，保证了得到的res就是最大的序列值
//	{
//		temp.push_back(index);//选择才加入
//		DFS(index, allSum + pow(index, k), facSum + index);
//		temp.pop_back();//不选择,不入
//		DFS(index - 1, allSum, facSum);
//	}
//}
//int main()
//{
//	cin >> n >> m >> k;
//	DFS(getTop(), 0, 0);
//	if (res.size() == 0)
//		cout << "Impossible";
//	else
//	{
//		cout << n << " = ";
//		for (int i = 0; i < res.size(); ++i)
//			cout << (i == 0 ? "" : " + ") << res[i] << "^" << k;
//	}
//	return 0;
//}