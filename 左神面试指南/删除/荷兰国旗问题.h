#include <iostream>

using namespace std;


//给定一个数组arr，和一个数num，请把小于num的数放在数组的
//左边，等于num的数放在数组的中间，大于num的数放在数组的
//右边。
//要求额外空间复杂度O(1)，时间复杂度O(N)

void swap(int& a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//记住，单次遍历n（n << N）次数组的时间复杂度 = n*O(N) == O(N)
template<class T>//目前我只想到了使用模板来实现引用数组，其他的引用方法都报错了。
void Test(T& array , const int num)
{
	int N, p1, p2;//两个指针
	p1 = -1;//左指针，在p1左边并含p1的所有数都<num
	p2 = N = sizeof(array) / sizeof(array[0]);//右指针，p2=N在p2的右边含p2的所有数都大于num
	for (int i = 0; i != p2; )
	{
		if (array[i] < num)
			swap(array[++p1], array[i++]);
		else if (array[i] > num)
			swap(array[--p2], array[i]);
		else
			++i;

	}

}

void Heland()
{
	int arr[] = { 1, 5,7,4,6,4,2,9 };	
	Test(arr, 4);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		cout << arr[i] << "  ";
	cout << endl << "**************************" << endl;
}

