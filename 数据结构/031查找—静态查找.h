#include "000库函数.h"

#define  MAXSIZE 100


//顺序查找
int Sequential_Search(int a[], int n, int key) {
	for (int i = 0; i < n; ++i)
		if (a[i] == key)return i;
	return 0;	
}
//带标志查找
int Sequential_Search2(int *a, int n, int key) {
	int i = 0;
	a[0] = key;
	i = n-1;
	while (a[i] != key)
		--i;
	return i;//查找到了就返回非0的i,否则就返回0，0代表未查找到
}
//折半查找
int Binary_Search(int arr[], int n, int key) {
	int low = 0, high = n-1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == key)return mid;
		else if (key < arr[mid])high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
//插值查找就是根据关键数在数组中的比例来查找
int Interpolation_Search(int arr[], int n, int key) {
	int low = 0, high = n-1, mid;
	while (low <= high) {
		mid = low + (key - arr[low]) / (arr[high] - arr[low])*(high - low);//计算关键数在数组中的比例位置
		if (arr[mid] == key)return mid;
		else if (key < arr[mid])high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}

//斐波切那数查找，即黄金比例查找
//所谓 的黄金比例0.618并不是真的用0.618，而是通过使用斐波那契数进行计算
//此处查找的是数组arr的数据
int Fibonacci_Search(int F[],int a[], int n, int key) {	
	int low = 0, high = n-1, mid;
	int k = 0;
	while (n > F[k++] - 1);//-1的作用是可以取到0   //此代码的作用就是确定取菲数的范围

	for (int i = n; i < F[k] - 1; ++i)
		a[i] = a[n-1];//数组长n但取不到n,通过给数组后面赋值最大数，来让数组长度达到黄金比例的倍数
	//利于后面取菲数

	while (low <= high) {
		mid = low + F[k - 1] - 1;
		if (key < a[mid]) {
			high = mid - 1;
			k--;
		}
		else if (key > a[mid]) {
			low = mid + 1;
			k -= 2;
		}
		else {
			if (mid <= n)return mid;
			else return n;
		}
	}
	return 0;
}



int T031(void)
{

	int a[MAXSIZE + 1], result;
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };//有序数组数据

	for (int i = 0; i <= MAXSIZE; i++)
	{
		a[i] = i;//再创建一个有序数组
	}
	result = Sequential_Search(a, MAXSIZE, MAXSIZE);
	printf("Sequential_Search:%d \n", result);
	result = Sequential_Search2(a, MAXSIZE, 1);
	printf("Sequential_Search2:%d \n", result);

	result = Binary_Search(arr, 11, 62);
	printf("Binary_Search:%d \n", result);


	result = Interpolation_Search(arr, 11, 62);
	printf("Interpolation_Search:%d \n", result);

	int F[MAXSIZE];
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < 100; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	result = Fibonacci_Search(F,arr, 11,62);
	printf("Fibonacci_Search:%d \n", result);

	return 0;
}
