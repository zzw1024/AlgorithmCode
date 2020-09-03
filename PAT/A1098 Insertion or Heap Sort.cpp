//////注意，这里的排序为排序迭代过程中完成的某一步而已，并不是最终结果
//////我们可以直接用sort来代替排序的部分，无论是合并排序还是插入排序
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int N, a;
////vector<int>nums, ans, temp;
////void down(int index, int n)
////{
////	int t = temp[index];
////	while (2 * index + 1 < n)
////	{
////		int child = 2 * index + 1;
////		if (child + 1 < n && temp[child] < temp[child + 1])
////			++child;
////		if (temp[child] > t)
////		{
////			temp[index] = temp[child];
////			index = child;
////		}
////		else
////			break;
////	}
////	temp[index] = t;
////}
////int main()
////{
////	cin >> N;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> a;
////		nums.push_back(a);
////	}
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> a;
////		ans.push_back(a);
////	}
////	temp = nums;
////	bool f = false;
////	for (int i = 1; i < N; ++i)//进行插入排序
////	{
////		sort(temp.begin(), temp.begin() + i + 1);//第一趟排序应该是排序前两个数，第i趟排序分别排序前i+1个数
////		if (temp == ans)
////		{
////			f = true;
////			cout << "Insertion Sort" << endl;
////			sort(temp.begin(), temp.begin() + i + 2);//再一次迭代
////			break;
////		}
////	}
////	if (f == false)//那就是堆排序
////	{
////		cout << "Heap Sort" << endl;
////		temp = nums;
////		for (int i = N / 2; i >= 0; --i)//将前一半元素进行下滤
////			down(i, N);
////		for(int i=N-1;i>0;--i)//N-1趟排序，每次排序得到一个第N-i大的值放到相应位置
////		{
////			swap(temp[i], temp[0]);
////			down(0, i);
////			if (temp == ans)
////			{
////				swap(temp[i-1], temp[0]);//进行下一次迭代
////				down(0, i - 1);
////				break;
////			}
////		}
////	}
////	for (int i = 0; i < N; ++i)
////		cout << temp[i] << (i < N - 1 ? " " : "");
////	return 0;
////}
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int Origil[105], Sorted[105];
//void downAdjust(int low, int hight)
//{
//	int i = 0, j = 1;
//	while (j <= hight)
//	{
//		if (j + 1 <= hight && Sorted[j] < Sorted[j + 1])
//			++j;
//		if (Sorted[i] >= Sorted[j])break;
//		swap(Sorted[i], Sorted[j]);
//		i = j;
//		j = i * 2;
//	}
//}
//int main()
//{
//	int n, i, j;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		cin >> Origil[i];
//	for (int i = 0; i < n; ++i)
//		cin >> Sorted[i];
//	for (i = 0; i < n - 1 && Sorted[i] <= Sorted[i + 1]; ++i);
//	for (j = i + 1; j < n&&Sorted[j] == Origil[j]; ++j);
//	if (j == n)
//	{
//		cout << "Insertion Sort" << endl;
//		sort(Sorted, Sorted + i + 2);
//	}
//	else
//	{
//		cout << "Heap Sort" << endl;
//		for (i = n-1; i > 1 && Sorted[i] >= Sorted[0]; --i);
//		swap(Sorted[0], Sorted[i]);
//		downAdjust(0, i - 1);
//	}
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << Sorted[i];
//	return 0;
//}
//

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n;
//vector<int>org, res;
//void downAdjust(int low, int high)
//{
//	int i = low, j = 2 * i;//i为根节点，j为左孩子
//	while (j <= high)
//	{
//		if (j + 1 <= high && res[j] < res[j + 1])//右节点比左节点小正常
//			++j;//j为右节点
//		if (res[i] >= res[j])break;//左右节点满足条件，不用动
//		swap(res[i], res[j]);//调整
//		i = j;
//		j = 2 * i;
//	}
//}
//int main()
//{
//	cin >> n;
//	org.resize(n+1);
//	res.resize(n+1);
//	for (int i = 1; i <= n; ++i)
//		cin >> org[i];
//	for (int i = 1; i <= n; ++i)
//		cin >> res[i];
//	bool isInsert = true;
//	int k = 1;
//	while (k < n && res[k] <= res[k + 1])++k;
//	for (int i = k + 1; i <= n; ++i)
//		if (org[i] != res[i])
//			isInsert = false;//因为在插入排序中未排序的部分一定是原来的顺序
//	if (isInsert)
//	{
//		cout << "Insertion Sort" << endl;
//		if (k < n)
//			sort(res.begin(), res.begin() + k + 2);//后面是开区间
//	}
//	else
//	{
//		cout << "Heap Sort" << endl;
//		int  i = n;
//		while (i > 2 && res[i] >= res[1])--i;//堆排序的后面是比前面的大，所以找到不满足规则的数与1号交换
//		swap(res[1], res[i]);
//		downAdjust(1, i - 1);
//	}
//	for (int i = 1; i <= n; ++i)
//		cout << (i == 1 ? "" : " ") << res[i];
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//void downAdjust(vector<int>&v, int L, int R)
//{
//	int i = L, j = 2 * L + 1;//i父节点，j左孩子
//	while (j <= R)
//	{
//		if (j + 1 <= R && v[j + 1] > v[j])++j;//找到最大的左右孩子
//		if (v[i] >= v[j])break;//父节点最大，无需调整
//		swap(v[j], v[i]);//否则就交换父节点与子节点
//		i = j;
//		j = 2 * i + 1;
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>initial(n), sorted(n);
//	for (int i = 0; i < n; ++i)
//		cin >> initial[i];
//	for (int i = 0; i < n; ++i)
//		cin >> sorted[i];
//	int k = 1;
//	while (k < n && sorted[k - 1] <= sorted[k])++k;//找到未排序的位置
//	bool isInsert = true;
//	for (int i = k; i < n && isInsert; ++i)//判断未排序的部分是不是与原数组一样
//		if (initial[i] != sorted[i])
//			isInsert = false;//不一样就不是插入排序
//	if (isInsert)
//	{
//		printf("Insertion Sort\n");
//		sort(sorted.begin(), sorted.begin() + k + 1);//再进行一步
//	}
//	else
//	{
//		printf("Heap Sort\n");
//		for (int i = n / 2; i >= 0; --i)
//			downAdjust(initial, i, n - 1);
//		bool over = false;
//		for (int i = n - 1; i > 0; --i)//一定把v[0]留住
//		{
//			swap(initial[0], initial[i]);//交换
//			downAdjust(initial, 0, i - 1);//调整
//			if (over)break;//排序结束
//			if (initial == sorted)over = true;//使用标志，再排一次序就立马结束
//		}
//		sorted = initial;
//	}
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << sorted[i];
//	return 0;
//}