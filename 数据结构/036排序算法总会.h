#include "000库函数.h"

#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */
#define MAXSIZE 100  /* 用于要排序数组个数最大值，可根据需要修改 */
#define N 9
struct SqList
{
	int v[MAXSIZE+1];//用于存储要排序的数组，r[0]作为哨兵或临时存放变量
	int len;//记录顺序表的长度
};

//数据交换
void swap(int &i, int &j) {
	int temp;
	temp = i;
	i = j;
	j = temp;
}

/**************************简单排序****************************/
//初级冒泡排序，就是一个一个与后面对比
void  BubbleSort0(SqList* &l,int (&a)[2]) {
	for (int i = 1; i < l->len; ++i) {
		for (int j = i + 1; j <= l->len; ++j) {
			a[0]++;
			if (l->v[i] > l->v[j]){
				swap(l->v[i], l->v[j]);
				a[1]++;
			}
		}
	}
}

/**************************冒泡排序****************************/
//冒泡排序，两两比较排序
void BubbleSort(SqList* &l, int(&a)[2]) {
	for (int i = 1; i < l->len; ++i) {
		for (int j = l->len - 1; j >= i; --j) {
			a[0]++;
			if (l->v[j + 1] < l->v[j]) {
				swap(l->v[j + 1], l->v[j]);
				a[1]++;
			}
		}
	}
}

/**************************改进冒泡排序****************************/
//改进冒泡排序，加入哨兵模式
void BubbleSort2(SqList* &l, int(&a)[2]) {
	bool flag = true;//哨兵
	for (int i = 1; flag&&i < l->len; ++i) {
		flag = false;
		for (int j = l->len - 1; j >= i; --j) {
			a[0]++;
			if (l->v[j + 1] < l->v[j]) {
				a[1]++;
				swap(l->v[j + 1], l->v[j]);
				flag = true;//数据交换后才需要遍历
			}
		}
	}
}

/**************************选择排序****************************/
//选择排序，就是依次找出未排序中的最小值放入前面
void SelectSort(SqList* &l, int(&a)[2]) {
	int i, j, min;
	for (i = 1; i < l->len; ++i) {
		min = i;
		for (j = i + 1; j < l->len; ++j) {
			a[0]++;
			if (l->v[min] > l->v[j])
				min = j;
		}
		if (i != min) {
			swap(l->v[min], l->v[i]);
			a[1]++;
		}
	}
}

/**************************插值排序****************************/
//插值排序，就是从前向后两两比较，若第二个数为小的数，然后将该数记住，
//从此位置从后向前比较该数，并将比他大的数向后挪，直到找到存放该数的位置
//此算法需要一个辅助的临时空间存放：

void InsertSort(SqList* &l, int(&a)[2]) {
	int i, j;
	for (int i = 2; i < l->len; ++i) {
		a[0]++;
		if (l->v[i] < l->v[i - 1]) {//找到了前比后大的数
			l->v[0] = l->v[i];//设置哨兵
			for (j = i - 1; l->v[0] < l->v[j]; --j) {//返回比较
				a[1]++;
				l->v[j + 1] = l->v[j];//大的数向后挪
			}
			l->v[j+1] = l->v[0];
		}
	}
}

/**************************希尔排序****************************/
//希尔排序
//与插值排序很像，不过是间隔比较
void ShellSort(SqList* &l, int(&a)[2]) {
	int gap = l->len;
	int i, j;
	do {
		gap = gap / 3 + 1;//间隔大小
		for (i = gap + 1; i < l->len; ++i) {
			a[0]++;
			if (l->v[i] < l->v[i - gap]) {
				l->v[0] = l->v[i];
				for (j = i - gap; j > 0 && l->v[0] < l->v[j]; j -= gap) {//向前去排序
					l->v[j + gap] = l->v[j];//大数向后移；
					a[1]++;
				}
				l->v[j + gap] = l->v[0];//插入
			}
		}
	} while (gap > 1);
}

/**************************************堆排序*****************************/
//调整为大根堆
void HeapAdjust(SqList* &l, int n, int len) {
	int temp = l->v[n];
	for (int i = 2 * n; i <= len; i *= 2) {//沿着关键字中较大的孩子结构向在筛选
		if (i < len&&l->v[i] < l->v[i + 1])++i;//i为关键字中较大的记录的下标
		if (temp >= l->v[i])break;//找到插入的位置了
		l->v[n] = l->v[i];//
		n = i;
	}
	l->v[n] = temp;//进行插入
}

//堆排序
void HeapSort(SqList* &l, int(&a)[2]) {
	for (int i = l->len / 2; i > 0; --i) {//把数组中的数据变为一个大堆
		a[0]++;
		HeapAdjust(l, i, l->len);
	}
	for (int i = l->len; i > 1; --i) {
		a[1]++;
		swap(l->v[1], l->v[i]);/* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
		HeapAdjust(l, 1, i - 1);/*  将L->r[1..i-1]重新调整为大根堆 */
	}
}

/**************************递归法归并+排序****************************/
/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
//归并
void Merge(int *SR, int *TR, int pot, int m, int len) {
	int i,j,k;
	for (i = m + 1, k = pot; pot <= m && i <= len; ++k) {/*将SR中记录由小到大地并入TR * /*/
		if (SR[pot] < SR[i])TR[k] = SR[pot++];
		else TR[k] = SR[i++];
	}
	if (pot <= m)
		for (j = 0; j <= m; ++j)
			TR[k + j] = SR[pot + j];	/* 将剩余的SR[i..m]复制到TR */
	if (i <= len)
		for (j = 0; j <= len - i; ++j)
			TR[k + j] = SR[i + j];/* 将剩余的SR[j..n]复制到TR */
}
//进行递归
void MSort(int *SR,int*TR1,int pot, int len, int(&a)[2]) {
	int TR2[MAXSIZE + 1];
	if (len == pot)
		TR1[pot] = SR[pot];
	else {
		int m = (len + pot) / 2;    //将原数组平分两个数组
		a[0]++;
		MSort(SR, TR2, pot, m, a);	/* 递归地将SR[pot..m]归并为有序的TR2[pot..m] */
		MSort(SR, TR2, m + 1, len, a);	/* 递归地将SR[m+1..len]归并为有序的TR2[m+1..len] */
		Merge(TR2, TR1, pot, m, len);	/* 将TR2[pot..m]和TR2[m+1..t]归并到TR1[pot..len] */
		a[1]++;
	}

}

//递归法归并排序
void MergeSort(SqList* &l, int(&a)[2]) {
	MSort(l->v,l->v,1, l->len,a);
}

/**************************非递归法归并排序****************************/
/*将SR[]中相邻长度为s的子序列两两归并到TR[] * /*/
void MergePass(int *SR, int *TR, int k, int len, int(&a)[2]) {
	int i = 1, j;
	a[1]++;
	while (i <= len - 2 * k + 1) {
		//两两归并
		Merge(SR, TR, i, i + k - 1, len);
		i = i + 2 * k;
	}
	if (i < len - k + 1)//归并最后两个序列
		Merge(SR, TR, i, i + k - 1, len);
	else//最后只剩下单个序列
		for (j = i; j <= len; ++j)
			TR[j] = SR[j];
} 
//归并排序
void MergeSort2(SqList* &l, int(&a)[2]) {
	int *TR = new int[l->len];
	int k = 1;
	while (k < l->len) {
		a[0]++;
		MergePass(l->v, TR, k, l->len, a);
		k = k * 2;//加长子序列
		MergePass(TR, l->v, k, l->len, a);
		k = 2 * k;//子序列加长
	}
}

/**************************快速排序****************************/
/* 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
//即处于枢轴的数的左边比其小，右边比其大
int Partiton(SqList* &l, int pot, int len, int(&a)[2]) {
	int pkey;
	pkey = l->v[pot];//假设第一个位置的数就是枢轴的位置
	while (pot < len) {
		a[0]++;
		while (pot < len&&l->v[len] >= pkey)//确保右边大于关键数
			len--;
		a[1]++;
		swap(l->v[pot], l->v[len]);//将比关键数小的数放置到关键数的左边
		a[0]++;
		while (pot < len&&l->v[pot] <= pkey)//确保左边的 数小于关键数
			pot++;
		a[1]++;
		swap(l->v[pot], l->v[len]);//将比关键数大的数放置到关键数的右边
	}
	return pot;//返回关键数的位置
}

/* 对顺序表L中的子序列L->r[low..high]作快速排序 */
void QSort(SqList* &l, int pot, int len, int(&a)[2]) {
	int pivot;
	if (pot < len) {
		pivot = Partiton(l, pot, len, a);/*  将L->r[low..high]一分为二，算出枢轴值pivot */
		QSort(l, pot, pivot - 1, a);/*  对低子表递归排序 */
		QSort(l, pivot + 1, len, a);/*  对高子表递归排序 */
	}
}
void QuickSort(SqList* &l, int(&a)[2]) {
	QSort(l, 1, l->len, a);
}

/**************************改进快速排序****************************/
//快速排序的优化
int Partiton1(SqList* &l, int pot, int len, int(&a)[2]) {
	int pkey;

	/////改进之处，之间选中间作为关键数的位置
	int m = pot + (len - pot) / 2;
	a[0]++;
	if (l->v[pot] > l->v[len]) {
		swap(l->v[pot], l->v[len]);/* 交换左端与右端数据，保证左端较小 */
		a[1]++;
	}
	a[0]++;
	if (l->v[m] > l->v[len]) {
		swap(l->v[m], l->v[len]);/* 交换中间与右端数据，保证中间较小 */
		a[1]++;
	}
	a[0]++;
	if (l->v[m] < l->v[pot]) {
		swap(l->v[m], l->v[pot]);/* 交换中间与左端数据，保证左端较小 */
		a[1]++;
	}
	/////
	pkey = l->v[pot];//假设第一个位置的数就是枢轴的位置
	l->v[0] = pkey;//保留
	while (pot < len) {/*从表的两端交替地向中间扫描 */
		a[0]++;
		while (pot < len&&l->v[len] >= pkey)//确保右边大于关键数
			--len;
		l->v[pot] = l->v[len];
		a[0]++;
		while (pot < len&&l->v[pot] <= pkey)//确保左边的 数小于关键数
			++pot;
		l->v[len] = l->v[pot];
	}
	l->v[pot] = l->v[0];
	return pot;//返回关键数的位置
}

void QSort1(SqList* &l, int pot, int len, int(&a)[2]) {
	int pivot;
	if ((len - pot) > MAX_LENGTH_INSERT_SORT) {
		while (pot < len) {
			pivot = Partiton1(l, pot, len, a);/*  将L->r[low..high]一分为二，算出枢轴值pivot */
			QSort1(l, pot, pivot - 1, a);/*  对低子表递归排序 */
			pot = pivot + 1;//尾递归
		}
	}
	else
		InsertSort(l,a);
}

void QuickSort1(SqList* &l, int(&a)[2]) {
	QSort1(l, 1, l->len, a);
}


/*************************************************************/
int T036(){
	/* int d[N]={9,1,5,8,3,7,4,6,2}; */
	int d[N] = { 50,10,90,30,70,40,80,60,20 };
	/* int d[N]={9,8,7,6,5,4,3,2,1}; */
	int count[2] = { 0,0 };//记录比较次数和交换次数
	SqList *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9, *l10;

	l0 = new SqList;
	for (int i = 0; i < N; i++)
		l0->v[i + 1] = d[i];
	l0->len = N;

	l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l0;
	printf("排序前:\n");
	for(int i=1;i<=N;++i)
		cout << l0->v[i] << "  ";
	cout << endl;

	printf("初级冒泡排序:\n");
	BubbleSort0(l0,count);
	for (int i = 1; i <= N; ++i)
		cout << l0->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("冒泡排序:\n");
	BubbleSort(l1,count);
	for (int i = 1; i <= N; ++i)
		cout << l1->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("改进冒泡排序:\n");
	BubbleSort2(l2,count);
	for (int i = 1; i <= N; ++i)
		cout << l2->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("选择排序:\n");
	SelectSort(l3,count);
	for (int i = 1; i <= N; ++i)
		cout << l3->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("直接插入排序:\n");
	InsertSort(l4, count);
	for (int i = 1; i <= N; ++i)
		cout << l4->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("希尔排序:\n");
	ShellSort(l5, count);
	for (int i = 1; i <= N; ++i)
		cout << l5->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("堆排序:\n");
	HeapSort(l6, count);
	for (int i = 1; i <= N; ++i)
		cout << l6->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("归并排序（递归）:\n");
	MergeSort(l7, count);
	for (int i = 1; i <= N; ++i)
		cout << l7->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("归并排序（非递归）:\n");
	MergeSort2(l8, count);
	for (int i = 1; i <= N; ++i)
		cout << l8->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("快速排序:\n");
	QuickSort(l9, count);
	for (int i = 1; i <= N; ++i)
		cout << l9->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0

	printf("改进快速排序:\n");
	QuickSort1(l10, count);
	for (int i = 1; i <= N; ++i)
		cout << l10->v[i] << "  ";
	cout << endl;
	cout << "比较次数： " << count[0] << " ; 交换次数： " << count[1] << endl;
	count[0] = count[1] = 0;//归0


	/*大数据排序*/
	/*
	srand(time(0));
	int Max=10000;
	int d[10000];
	int i;
	SqList l0;
	for(i=0;i<Max;i++)
		d[i]=rand()%Max+1;
	for(i=0;i<Max;i++)
		l0.r[i+1]=d[i];
	l0.length=Max;
	MergeSort(l0);
	print(l0);
	*/
	return 0;
}


