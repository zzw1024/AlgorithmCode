#include "000�⺯��.h"

#define  MAXSIZE 100


//˳�����
int Sequential_Search(int a[], int n, int key) {
	for (int i = 0; i < n; ++i)
		if (a[i] == key)return i;
	return 0;	
}
//����־����
int Sequential_Search2(int *a, int n, int key) {
	int i = 0;
	a[0] = key;
	i = n-1;
	while (a[i] != key)
		--i;
	return i;//���ҵ��˾ͷ��ط�0��i,����ͷ���0��0����δ���ҵ�
}
//�۰����
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
//��ֵ���Ҿ��Ǹ��ݹؼ����������еı���������
int Interpolation_Search(int arr[], int n, int key) {
	int low = 0, high = n-1, mid;
	while (low <= high) {
		mid = low + (key - arr[low]) / (arr[high] - arr[low])*(high - low);//����ؼ����������еı���λ��
		if (arr[mid] == key)return mid;
		else if (key < arr[mid])high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}

//쳲����������ң����ƽ��������
//��ν �Ļƽ����0.618�����������0.618������ͨ��ʹ��쳲����������м���
//�˴����ҵ�������arr������
int Fibonacci_Search(int F[],int a[], int n, int key) {	
	int low = 0, high = n-1, mid;
	int k = 0;
	while (n > F[k++] - 1);//-1�������ǿ���ȡ��0   //�˴�������þ���ȷ��ȡ�����ķ�Χ

	for (int i = n; i < F[k] - 1; ++i)
		a[i] = a[n-1];//���鳤n��ȡ����n,ͨ����������渳ֵ��������������鳤�ȴﵽ�ƽ�����ı���
	//���ں���ȡ����

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
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };//������������

	for (int i = 0; i <= MAXSIZE; i++)
	{
		a[i] = i;//�ٴ���һ����������
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
