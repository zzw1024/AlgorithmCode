// ////#include <iostream>
// ////#include <vector>
// ////using namespace std;
// ////
// //////使用窗口很容易解决该问题
// ////
// ////void Test01()
// ////{
// ////	int K;
// ////	cin >> K;
// ////	vector<int>v(K);
// ////	int l = 0, r = K - 1, sum = -1, temp = 0, index = 0;//所求的左、右边界，累加和，以及临时的累加和、左边界
// ////	for (int i = 0; i < K; ++i)
// ////	{
// ////		cin >> v[i];
// ////		temp += v[i];
// ////		if (temp < 0)//如果和小于0，则直接抛弃
// ////		{
// ////			temp = 0;
// ////			index = i + 1;//选下一个点为新左点
// ////		}
// ////		else if (temp > sum)//获得更大值
// ////		{
// ////			sum = temp;
// ////			l = index;
// ////			r = i;
// ////		}
// ////	}
// ////	if (sum < 0)
// ////		sum = 0;
// ////	cout << sum << " " << v[l] << " " << v[r] << endl;
// ////}
// ////
// ////void Test02()
// ////{
// ////	int K;
// ////	cin >> K;
// ////	vector<int>v(K);
// ////	int l = 0, r = K - 1, sum = -1, temp = 0, index = 0;//所求的左、右边界，累加和，以及临时的累加和、左边界
// ////	for (int i = 0; i < K; ++i)
// ////		cin >> v[i];
// ////
// ////	vector<int>max_sum(K), max_sum_index(K);//当前数能获得最大值的到达的最右端
// ////	for (int r = K - 1; r >= 0; --r)//c从最右端开始加，每次得到自己获取最大值的最优边界
// ////	{
// ////		if (r + 1 < K && max_sum[r + 1] > 0)//加上大的数会使我变大
// ////		{
// ////			max_sum[r] = max_sum[r + 1] + v[r];
// ////			max_sum_index[r] = max_sum_index[r + 1];//记录，我这边能到达的最右边是哪
// ////		}
// ////		else//加上负数会使我变小，还不如自己当最大的数
// ////		{
// ////			max_sum[r] = v[r];
// ////			max_sum_index[r] = r;
// ////		}
// ////	}
// ////	for (int t = 0; t < K; ++t)
// ////	{
// ////		if (max_sum[t] > sum)
// ////		{
// ////			sum = max_sum[t];
// ////			l = t;//自己为左边界
// ////			r = max_sum_index[t];//记录点为右边界
// ////		}
// ////	}
// ////	if (sum < 0)//如果最大和小于0，则所有数都小于0，按要求输出整个数组
// ////	{
// ////		sum = 0;
// ////		l = 0;
// ////		r = K - 1;
// ////	}
// ////	cout << sum << " " << v[l] << " " << v[r] << endl;
// ////}
// ////
// ////int main()
// ////{
// ////	
// ////	return 0;
// ////}
// //
// //////使用
// ////#include <iostream>
// ////#include <vector>
// ////using namespace std;
// ////int main()
// ////{
// ////	int k;
// ////	cin >> k;
// ////	int sum = 0, maxS = -1, rL = 0, rR = k - 1, tempIndex = 0;
// ////	vector<int>v(k);//记录序列的左边节点，右边节点就是i
// ////	for (int i = 0; i < k; ++i)
// ////	{
// ////		cin >> v[i];
// ////		sum += v[i];
// ////		if (sum < 0)//把v[i]是个大负数，把v[i]加上，会拖累后面i+1这个数的累加和
// ////		{
// ////			sum = 0;
// ////			tempIndex = i + 1;
// ////		}
// ////		else if (sum > maxS)
// ////		{
// ////			maxS = sum;
// ////			rL = tempIndex;
// ////			rR = i;
// ////		}
// ////	}
// ////	cout << (maxS < 0 ? 0 : maxS) << " " << v[rL] << " " << v[rR];
// ////	return 0;	
// ////}
// //
// //
// //#include <iostream>
// //#include <vector>
// //using namespace std;
// //int k;
// //int main()
// //{
// //	cin >> k;
// //	vector<int>v(k);
// //	int sum = 0, maxS = -1, rL = 0, rR = k - 1, tempL = 0;
// //	for (int i = 0; i < k; ++i)
// //	{
// //		cin >> v[i];
// //		if (sum < 0)//前面的和为负数，会连累v[i]的，故新和从v[i]开始
// //		{
// //			sum = v[i];
// //			tempL = i;
// //		}
// //		else
// //		{
// //			sum += v[i];//一直沿用前面的和，故tempL不用变
// //		}
// //		if (sum > maxS)
// //		{
// //			maxS = sum;
// //			rL = tempL;
// //			rR = i;
// //		}
// //	}
// //	cout << (maxS < 0 ? 0 : maxS) << " " << v[rL] << " " << v[rR];
// //	return 0;
// //}

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
// 	int n;
// 	cin >> n;
// 	vector<int>v(n);
// 	int sum = 0, res = -1, resL = 0, resR = n-1, tempL = 0;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cin >> v[i];
// 		if (sum < 0)//sum为前面的和
// 		{
// 			sum = v[i];//不要前面的和
// 			tempL = i;//重新计算
// 		}
// 		else
// 			sum += v[i];
// 		if (sum > res)
// 		{
// 			res = sum;
// 			resL = tempL;
// 			resR = i;
// 		}		
// 	}
// 	cout << (res < 0 ? 0 : res) << " " << v[resL] << " " << v[resR];
// 	return 0;//0000
// }