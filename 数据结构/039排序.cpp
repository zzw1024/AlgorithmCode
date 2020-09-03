//#include "000库函数.h"
//int n;
//vector<int>v = { 46,4,11,2,0,5,23,6,17,8,10,9 };
//void swap(int a, int b)
//{
//	int temp = v[a];
//	v[a] = v[b];
//	v[b] = temp;
//}
//
//
////01简单排序
//void Sort01()
//{
//	for (int i = 0; i < n; ++i)
//	{
//		int minV = v[i], index = i;
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (minV > v[j])
//			{
//				minV = v[j];
//				index = j;
//			}
//		}
//		swap(i, index);
//	}
//}
//
////02冒泡排序
//void Sort02()
//{
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n - i - 1; ++j)
//			if (v[j] > v[j + 1])
//				swap(j, j + 1);
//}
//
////03选择排序
//void Sort03()
//{
//	for (int i = 0; i < n; ++i)
//	{
//		int index = i;
//		for (int j = i + 1; j < n; ++j)
//			if (v[index] > v[j])
//				index = j;
//		if (index != i)
//			swap(i, index);
//	}
//}
////04直接插入排序
//void Sort04()
//{
//	int temp;//临时哨兵
//	for (int i = 1; i < n; ++i)
//	{
//		temp = v[i];
//		int j = i - 1;
//		for (; j >= 0; --j)//从i的前一位开始从后向前比较
//			if (temp < v[j])
//				v[j + 1] = v[j];//向后移
//			else
//				break;//找到位置了
//		v[j+1] = temp;//注意，j向前移动了
//	}
//}
////05希尔排序
//void Sort05()
//{
//	for (int gap = n / 2; gap > 0; gap /= 2)//gap为组的跨度，初始取长度的一半，此后每一次都折半取
//	{
//		//对于每个跨度为gap的数据进行插入排序
//		for (int i = 0; i < gap; ++i)//每次i与跨度为gap的j一起比较
//		{
//			for (int j = i + gap; j < n; j+=gap)//j对应的是i的跨度为gap的数值
//			{
//				if (v[j] < v[j - gap])//后比前小，应该向前插入
//				{
//					int k = j - gap, temp = v[j];//temp哨兵
//					while (k >= 0 && v[k] > temp)
//					{
//						v[k + gap] = v[k];//后移
//						k -= gap;
//					}
//					v[k + gap] = temp;//k-gap了，故需加上gap
//				}
//			}
//		}
//	}
//}
////06并归排序
//void Merge(int iL, int iR, int jL, int jR)//此处的L，R分别为两个小数组的边界
//{
//	vector<int>temp(jR - iL + 1);//开辟大小为两个数组的大小空间
//	int k = 0, i = iL, j = jL;
//	while (i <= iR && j <= jR)
//	{
//		if (v[i] <= v[j])//此处的等号保证了算法的稳定性，使得相同数值前后位置不变
//			temp[k++] = v[i++];
//		else
//			temp[k++] = v[j++];
//	}
//	while (i <= iR)//数组1未完
//		temp[k++] = v[i++];
//	while (j <= jR)//数组2未完
//		temp[k++] = v[j++];
//
//	for (i = iL, k = 0; i <= jR; ++k, ++i)//将归并并排好序的数值赋值给原素组
//		v[i] = temp[k];
//}
////自底向上：非递归版【小数组到大数组】
//void Sort06()
//{
//	//step为小数组的大小，此处step的代表为两个小数组的大小，故定是2的倍数
//	for (int step = 2; step / 2 < n; step *= 2)//1&1组，2&2组，4&4组。。。。
//	{//一定是从1与1的数组开始！！！不然就没法保证排序了
//		for (int i = 0; i < n; i += step)
//			//sort(v + i, v + min(i + step, n));//直接使用自带的sort函数进行排序
//			if ((i + step / 2 ) < n)//中间节点
//				Merge(i, i + step / 2 - 1, i + step / 2, min(i + step - 1, n - 1));//从i开始，在跨度为step中分为两个小数组进行归并
//	}
//}
////自顶向下：递归版【大数组到小数组】
//void Sort07(int L, int R)
//{
//	if (L < R)
//	{
//		int mid = L + (R - L) / 2;//求中点
//		Sort07(L, mid);//对左边进行递归切分成小数组
//		Sort07(mid + 1, R);//对右边进行递归切分成小数组
//		Merge(L, mid, mid + 1, R);//将左右两边进行归并
//	}
//}
//
////快速排序
////对区间进行划分
//int Partition(int L, int R)
//{
//	//int p = round(1.0*rand() / RAND_MAX * (R - L) + L);//选取随机位置的数为基准值
//	//swap(v[L], v[p]);//将基准值换到最左边
//	int key = v[L];//一般默认使用最左端的值为基准值
//	while (L < R)
//	{
//		while (L < R && v[R]>key)--R;//从右向左，直到找到比key小的数
//		v[L] = v[R];//将小的数移到左边
//		while (L < R && v[L] <= key)++L;//从左向右，直到找到比key大数
//		v[R] = v[L];//将大的数移到右边
//	}
//	v[L] = key;//key在中间的位置
//	return L;//返回中点坐标
//}
//
//void Sort08(int L, int R)
//{
//	if (L < R)
//	{
//		int pos = Partition(L, R);
//		Sort08(L, pos - 1);//对左子区间进行快速排序
//		Sort08(pos + 1, R);//对右子区间进行快速排序
//	}
//}
////堆排序：大根堆
////向下调整
//void downAdjust(int L, int R)
//{
//	int i = L, j = 2 * L + 1;//i为父节点，j为左子节点
//	while (j <= R)
//	{
//		if (j + 1 <= R && v[j + 1] > v[j])//若有右节点，且右节点大，那么就选右节点,即选取最大的子节点与父节点对比
//			++j;//选取了右节点
//		if (v[j] <= v[i])//孩子节点都比父节点小，满足条件，无需调整
//			break;
//		//不满足的话，那么我就将最大孩子节点j与父节点i对调,
//		swap(i, j);
//		i = j;
//		j = 2 * i + 1;//继续向下遍历
//	}
//}
////建堆
//void createHeap()
//{
//	for (int i = n / 2; i >= 0; --i)
//		downAdjust(i, n - 1);
//}
////删除堆顶元素
//void deleteTop()
//{
//	v[0] = v[n - 1];//也就是堆顶使用最后一个数值来替代
//	downAdjust(0, n - 2);//然后对前n-1个数进行排序
//}
//void Sort09()
//{
//	createHeap();//建堆
//	for (int i = n - 1; i > 0; --i)//从最后开始交换，直到只剩下最后一个数字
//	{
//		swap(i, 0);//每次都将最大值放到最后
//		downAdjust(0, i - 1);//将前0-i个数字重新构成大根堆
//	}
//}
//
////添加元素：
////向上调整
//void  upAdjust(int L, int R)
//{
//	int  i = R, j = (i - 1) / 2;//i为欲调整结点，j为其父亲
//	while (j >= L)
//	{
//		if (v[j] < v[i])//父节点小了，那么就将孩子节点调上来
//		{
//			swap(v[i], v[j]);
//			i = j;
//			j = (i - 1) / 2;//继续向上遍历
//		}
//		else//无需调整
//			break;
//	}
//}
//void insert(int  x)
//{
//	v[n] = x;//将新加入的值放置在数组的最后，切记保证数组空间充足
//	upAdjust(0, n);//向上调整新加入的结点n
//}
//
////计数排序
//void Sort10()
//{
//	int minN = v[0], maxN = v[0];
//	for (auto a : v)//找出最大值与最小值
//	{
//		minN = minN < a ? minN : a;
//		maxN = maxN > a ? maxN : a;
//	}
//	vector<int>nums(maxN - minN + 1, 0);//以空间换取时间，用来计算每个数的数量
//	for (auto a : v)
//		++nums[a - minN];
//	for (int i = 0, k = 0; i < nums.size(); ++i)//将数赋给原数组
//		while (nums[i]--)
//			v[k++] = i + minN;
//}
//
////桶排序
//void Sort11()
//{
//	int minN = v[0], maxN = v[0];
//	for (auto a : v)//找出最大值与最小值
//	{
//		minN = minN < a ? minN : a;
//		maxN = maxN > a ? maxN : a;
//	}
//	vector<vector<int>>bucket((maxN-minN)/10+1);//除数是按照数据范围进行调整的
//	for (auto a : v)//将数据放入对应的桶中
//		bucket[(a - minN) / 10].push_back(a);
//	for (int i = 0; i < bucket.size(); ++i)
//		sort(bucket[i].begin(), bucket[i].end());//分别对每个桶进行排序，可以使用任意的排序算法，个人感觉没必要使用复杂的排序算法
//	int k = 0;
//	for (auto a : bucket)//将数据赋予原数组
//		for (auto b : a)
//			v[k++] = b;
//}
//
////基数排序
//void Sort12()
//{
//	int maxBit = 0;//最大的位数
//	int bit = 1;//先从个位开始
//	for (auto a : v)
//	{
//		int len = to_string(a).length();//这里我就偷懒直接使用string来转换
//		maxBit = maxBit > len ? maxBit : len;
//	}	
//	for (int i = 1; i <= maxBit; ++i)//最大的数有多少位就进行多少次排序
//	{
//		vector<vector<int>>count(10);//存放位数上数值相同的数据
//		for (auto a : v)
//			count[(a % (bit * 10) / bit)].push_back(a);//按照第bit位上进行排序
//		int k = 0;
//		for (auto a : count)
//			for (auto b : a)
//				v[k++] = b;//将数据放回
//		bit *= 10;//向前一位
//	}
//}
//int main()
//{
//	n = v.size();
//	vector<int>org = v;
//	Sort12( );
//
//
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}
