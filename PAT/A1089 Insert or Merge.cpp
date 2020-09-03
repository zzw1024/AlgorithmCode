//////注意，这里的排序为排序迭代过程中完成的某一步而已，并不是最终结果
//////我们可以直接用sort来代替排序的部分，无论是合并排序还是插入排序
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int N, a;
////vector<int>nums, ans, temp;
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
////	if (f == false)//那就是合并排序
////	{
////		cout << "Merge Sort" << endl;
////		temp = nums;
////		for (int i = 2; i < N; i *= 2)//将每i个元素归并为一个非递减序列
////		{
////			for (int j = 0; j < N; j += i)
////				sort(temp.begin() + j, temp.begin() + (j + i < N ? j + i : N));
////			if (temp == ans)
////			{
////				for (int j = 0; j < N; j += i * 2)//进行下一次迭代
////					sort(temp.begin() + j, temp.begin() + (j + i * 2 < N ? j + i * 2 : N));
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
//int n, Original[105], Sorted[105];
//int main()
//{
//	int a, i, j;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		cin >> Original[i];
//	for (int i = 0; i < n; ++i)
//		cin >> Sorted[i];
//	for (i = 0; i < n - 1 && Sorted[i] <= Sorted[i + 1]; ++i);//找到未排序的位置
//	for (j = i + 1; Original[j] == Sorted[j] && j < n; ++j);
//	if (j == n)//若未排序后面的顺序没有变，那则是插入排序，因为归并排序会打乱后面的原始数据
//	{
//		cout << "Insertion Sort" << endl;
//		sort(Original, Original + i + 2);//再一次排序
//	}
//	else
//	{
//		cout << "Merge Sort" << endl;
//		int k = 1, flag = 1;
//		while (flag == 1)
//		{
//			flag = 0;
//			for (int i = 0; i < n; ++i)
//				if (Original[i] != Sorted[i])
//					flag = 1;
//			k = k * 2;
//			for (i = 0; i < n / k; ++i)
//				sort(Original + i * k, Original + (i + 1)*k);//进行归并排序
//			sort(Original + n / k * k, Original + n);//再进行下一次的排序
//		}
//	}
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << Original[i];
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n;
//vector<int>org, res;
//int main()
//{
//	cin >> n;
//	org.resize(n);
//	res.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> org[i];
//	for (int i = 0; i < n; ++i)
//		cin >> res[i];
//	bool isInsert = true;
//	int k = 0;
//	while (k < n - 1 && res[k] <= res[k + 1])++k;
//	for (int i = k + 1; i < n; ++i)
//		if (org[i] != res[i])
//			isInsert = false;//因为在插入排序中未排序的部分一定是原来的顺序
//	if(isInsert)
//	{
//		cout << "Insertion Sort" << endl;
//		if (k < n - 1)
//			sort(org.begin(), org.begin() + k + 2);//后面是开区间
//	}
//	else
//	{
//		cout << "Merge Sort" << endl;
//		for (int i = 2; i < n; i *= 2)
//		{
//			for (int j = 0; j < n; j += i)
//				sort(org.begin() + j, j + i < n ? (org.begin() + j + i) : org.end());
//			bool flag = true;
//			for (int t = 0; t < n; ++t)
//				if (org[t] != res[t])
//					flag = false;
//			if(flag)
//			{
//				for (int j = 0; j < n; j += i * 2)
//					sort(org.begin() + j, j + i * 2 < n ? (org.begin() + j + i * 2) : org.end());
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << org[i];
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
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
//		printf("Merge Sort\n");
//		for (int step = 2; step / 2 < n; step *= 2)
//		{
//			if (initial == sorted)//相同后，需要来一轮，而不是再来一步
//			{
//				for (int i = 0; i < n; i += step)
//					sort(initial.begin() + i, initial.begin() + min(i + step, n));
//				break;
//			}
//			for (int i = 0; i < n; i += step)
//				sort(initial.begin() + i, initial.begin() + min(i + step, n));//归并
//		}
//		sorted = initial;
//	}
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << sorted[i];
//	return 0;
//}